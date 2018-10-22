-- --------------------------------------------------------
-- 主机:                           127.0.0.1
-- 服务器版本:                        5.5.35-MariaDB - mariadb.org binary distribution
-- 服务器操作系统:                      Win32
-- HeidiSQL 版本:                  8.3.0.4799
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

-- 导出 zendb 的数据库结构
CREATE DATABASE IF NOT EXISTS `zendb` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `zendb`;


-- 导出  表 zendb.ams_t_hisalarm 结构
CREATE TABLE IF NOT EXISTS `ams_t_hisalarm` (
  `Uid` int(4) NOT NULL AUTO_INCREMENT,
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Obj` char(128) NOT NULL DEFAULT '0',
  `Type` tinyint(1) NOT NULL DEFAULT '0',
  `Aid` smallint(2) NOT NULL DEFAULT '0',
  `Des` varchar(1024) NOT NULL DEFAULT '',
  `STime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `ETime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`Uid`),
  KEY `STime` (`STime`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.ams_t_hislog 结构
CREATE TABLE IF NOT EXISTS `ams_t_hislog` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `User` char(128) NOT NULL DEFAULT '0',
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Type` tinyint(1) NOT NULL DEFAULT '0',
  `Action` varchar(4096) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Nid`,`User`,`Time`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.ams_t_hislost 结构
CREATE TABLE IF NOT EXISTS `ams_t_hislost` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Type` tinyint(1) NOT NULL DEFAULT '0',
  `STime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `ETime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`Nid`,`Type`,`STime`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.ams_t_hisstate 结构
CREATE TABLE IF NOT EXISTS `ams_t_hisstate` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `DevName` char(128) NOT NULL DEFAULT '',
  `STime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `ETime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `State` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Nid`,`DevName`,`STime`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.ams_t_lastalarm 结构
CREATE TABLE IF NOT EXISTS `ams_t_lastalarm` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Type` tinyint(1) NOT NULL,
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Data` varchar(16384) NOT NULL DEFAULT '',
  PRIMARY KEY (`Nid`,`Type`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.ams_t_lastdt 结构
CREATE TABLE IF NOT EXISTS `ams_t_lastdt` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Tid` smallint(2) NOT NULL DEFAULT '0',
  `Type` tinyint(1) NOT NULL DEFAULT '0',
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`Nid`,`Type`,`Tid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.ams_t_laststate 结构
CREATE TABLE IF NOT EXISTS `ams_t_laststate` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Data` varchar(16384) NOT NULL DEFAULT '',
  PRIMARY KEY (`Nid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.ams_t_markalarm 结构
CREATE TABLE IF NOT EXISTS `ams_t_markalarm` (
  `Uid` int(4) NOT NULL DEFAULT '0',
  `STime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `ETime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Flag` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Uid`,`STime`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.ams_t_markdata 结构
CREATE TABLE IF NOT EXISTS `ams_t_markdata` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Type` tinyint(1) NOT NULL DEFAULT '0',
  `Obj` char(10) NOT NULL DEFAULT '""' COMMENT '全局因子',
  `State` tinyint(1) NOT NULL DEFAULT '0',
  `STime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `ETime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`Nid`,`Obj`,`State`,`STime`,`Type`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.ams_t_markdtarq 结构
CREATE TABLE IF NOT EXISTS `ams_t_markdtarq` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Tid` smallint(2) NOT NULL DEFAULT '0',
  `Type` tinyint(1) NOT NULL DEFAULT '0',
  `STime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `ETime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`Nid`,`Type`,`Tid`,`STime`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.cms_t_cmdreq 结构
CREATE TABLE IF NOT EXISTS `cms_t_cmdreq` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Src` char(32) NOT NULL DEFAULT '',
  `Dst` char(32) NOT NULL DEFAULT '',
  `Qn` char(32) NOT NULL DEFAULT '',
  `Msg` varchar(4096) NOT NULL DEFAULT '',
  `UTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`Nid`,`Src`,`Dst`,`Qn`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.cms_t_cmdres 结构
CREATE TABLE IF NOT EXISTS `cms_t_cmdres` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Src` char(32) NOT NULL DEFAULT '',
  `Dst` char(32) NOT NULL DEFAULT '',
  `Qn` char(32) NOT NULL DEFAULT '',
  `Msg` varchar(4096) NOT NULL DEFAULT '',
  `UTime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`Nid`,`Src`,`Dst`,`Qn`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.rdms_t_data 结构
CREATE TABLE IF NOT EXISTS `rdms_t_data` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Gid` tinyint(1) NOT NULL DEFAULT '0',
  `Fid` smallint(2) NOT NULL DEFAULT '0',
  `Inst` tinyint(1) NOT NULL DEFAULT '0',
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Value` double NOT NULL DEFAULT '0',
  `State` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Nid`,`Gid`,`Fid`,`Time`,`Inst`),
  KEY `Time` (`Time`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8
/*!50100 PARTITION BY HASH (year(Time)*12+month(Time))
PARTITIONS 36 */;

-- 数据导出被取消选择。


-- 导出  表 zendb.rdms_t_datapack 结构
CREATE TABLE IF NOT EXISTS `rdms_t_datapack` (
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Fid` char(10) NOT NULL,
  `BV` double NOT NULL DEFAULT '0',
  `K` float NOT NULL DEFAULT '0',
  `ST` smallint(2) NOT NULL,
  `T` smallint(2) NOT NULL DEFAULT '0',
  `S` tinyint(1) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`Time`,`Nid`,`Fid`),
  KEY `Time` (`Time`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8
/*!50100 PARTITION BY HASH (Nid)
PARTITIONS 32 */;

-- 数据导出被取消选择。


-- 导出  表 zendb.rdms_t_dataperiod 结构
CREATE TABLE IF NOT EXISTS `rdms_t_dataperiod` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Type` tinyint(1) NOT NULL DEFAULT '0',
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Data` varchar(16384) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Nid`,`Type`,`Time`),
  KEY `Time` (`Time`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.rdms_t_lastdata 结构
CREATE TABLE IF NOT EXISTS `rdms_t_lastdata` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `PNum` tinyint(1) NOT NULL DEFAULT '0',
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Data` varchar(16384) NOT NULL DEFAULT '',
  PRIMARY KEY (`Nid`,`PNum`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.rdms_t_lastpacket 结构
CREATE TABLE IF NOT EXISTS `rdms_t_lastpacket` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Data` varchar(16384) NOT NULL DEFAULT '',
  PRIMARY KEY (`Nid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.rdms_t_qc_info 结构
CREATE TABLE IF NOT EXISTS `rdms_t_qc_info` (
  `NODE_ID` smallint(2) NOT NULL DEFAULT '0',
  `ITEM_ID` char(10) NOT NULL DEFAULT '',
  `QC_TYPE` int(4) NOT NULL DEFAULT '0' COMMENT '0:零点检查; 1跨度检查; 2精度检查; 3零点校准; 4跨度校准;5质量检查;6流量检查;7温度压力校准',
  `START_TIME` datetime NOT NULL,
  `END_TIME` datetime NOT NULL,
  `USER_NAME` char(50) DEFAULT '',
  `CRC_HOUR` int(11) DEFAULT '0',
  `REMARK` char(100) DEFAULT '',
  PRIMARY KEY (`NODE_ID`,`ITEM_ID`,`QC_TYPE`,`START_TIME`,`END_TIME`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='站点质控信息表';

-- 数据导出被取消选择。


-- 导出  表 zendb.udms_t_avgday 结构
CREATE TABLE IF NOT EXISTS `udms_t_avgday` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Gid` tinyint(1) NOT NULL DEFAULT '0',
  `Fid` smallint(2) NOT NULL DEFAULT '0',
  `Inst` tinyint(1) NOT NULL DEFAULT '0',
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Avg` double NOT NULL DEFAULT '0',
  `Min` double NOT NULL DEFAULT '0',
  `Max` double NOT NULL DEFAULT '0',
  `Cou` double NOT NULL DEFAULT '0',
  `State` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Nid`,`Gid`,`Fid`,`Time`,`Inst`),
  KEY `Time` (`Time`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.udms_t_avghour 结构
CREATE TABLE IF NOT EXISTS `udms_t_avghour` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Gid` tinyint(1) NOT NULL DEFAULT '0',
  `Fid` smallint(2) NOT NULL DEFAULT '0',
  `Inst` tinyint(1) NOT NULL DEFAULT '0',
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Avg` double NOT NULL DEFAULT '0',
  `Min` double NOT NULL DEFAULT '0',
  `Max` double NOT NULL DEFAULT '0',
  `Cou` double NOT NULL DEFAULT '0',
  `State` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Nid`,`Gid`,`Fid`,`Time`,`Inst`),
  KEY `Time` (`Time`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8
/*!50100 PARTITION BY HASH (year(Time))
PARTITIONS 5 */;

-- 数据导出被取消选择。


-- 导出  表 zendb.udms_t_avgminute 结构
CREATE TABLE IF NOT EXISTS `udms_t_avgminute` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Gid` tinyint(1) NOT NULL DEFAULT '0',
  `Fid` smallint(2) NOT NULL DEFAULT '0',
  `Inst` tinyint(1) NOT NULL DEFAULT '0',
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Avg` double NOT NULL DEFAULT '0',
  `Min` double NOT NULL DEFAULT '0',
  `Max` double NOT NULL DEFAULT '0',
  `Cou` double NOT NULL DEFAULT '0',
  `State` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Nid`,`Gid`,`Fid`,`Time`,`Inst`),
  KEY `Time` (`Time`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8
/*!50100 PARTITION BY HASH (year(Time)*12+month(Time))
PARTITIONS 36 */;

-- 数据导出被取消选择。


-- 导出  表 zendb.udms_t_avgmonth 结构
CREATE TABLE IF NOT EXISTS `udms_t_avgmonth` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `Gid` tinyint(1) NOT NULL DEFAULT '0',
  `Fid` smallint(2) NOT NULL DEFAULT '0',
  `Inst` tinyint(1) NOT NULL DEFAULT '0',
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Avg` double NOT NULL DEFAULT '0',
  `Min` double NOT NULL DEFAULT '0',
  `Max` double NOT NULL DEFAULT '0',
  `Cou` double NOT NULL DEFAULT '0',
  `State` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Nid`,`Gid`,`Fid`,`Time`,`Inst`),
  KEY `Time` (`Time`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.udms_t_lastacc 结构
CREATE TABLE IF NOT EXISTS `udms_t_lastacc` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `PNum` tinyint(1) NOT NULL DEFAULT '0',
  `Type` tinyint(1) NOT NULL DEFAULT '0',
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Data` varchar(16384) NOT NULL DEFAULT '',
  PRIMARY KEY (`Nid`,`PNum`,`Type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- 数据导出被取消选择。


-- 导出  表 zendb.udms_t_lastavg 结构
CREATE TABLE IF NOT EXISTS `udms_t_lastavg` (
  `Nid` smallint(2) NOT NULL DEFAULT '0',
  `PNum` tinyint(1) NOT NULL DEFAULT '0',
  `Type` tinyint(1) NOT NULL DEFAULT '0',
  `Time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `Data` varchar(16384) NOT NULL DEFAULT '',
  PRIMARY KEY (`Nid`,`PNum`,`Type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='注意16KB是否够用。考虑Fid用0-255的数值（工况情况下，如果一个分组最多允许设200个因子应该是可以的）';

-- 数据导出被取消选择。
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
