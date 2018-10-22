#include "dsmpub.h"
#include <stdlib.h>
int dsm_strtoufid(const char* strfid, unsigned int* mygid, unsigned int* myfid, unsigned int* myinstid)
{
    int ret = 0;
    unsigned int gid = 0;
    unsigned int fid = 0;
    unsigned int inst = 0;
    unsigned int ufid = 0;
    
    ufid = atoi(strfid+1);

    inst = (ufid/(DM_FID_MAXNUM*DM_GROUP_MAXNUM));
    gid = ((ufid/DM_FID_MAXNUM)%DM_GROUP_MAXNUM);
    fid = (ufid%DM_FID_MAXNUM);

    if (gid >= DM_GROUP_MAXNUM)
    {
        gid = (DM_GROUP_MAXNUM-1);
    }
    
    if (inst >= DM_INST_MAXNUM)
    {
        inst = (DM_INST_MAXNUM-1);
    }
    
    if (fid >= DM_FID_MAXNUM)
    {
        fid = (DM_FID_MAXNUM-1);
    }

    *mygid = gid;
    *myfid = fid;
    *myinstid = inst;
    
    return 0;
}
