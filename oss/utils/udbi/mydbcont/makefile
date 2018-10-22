include $(ROOT_DIR)/mk/common.mk
include $(ROOT_DIR)/mk/leaf.mk

MYCFLAGS=
MYLDFLAGS=
MYLIBS=

ifeq ($(US_MODEL),M6G2C)
    TARGET_T= libmydbcont.a
	TARGET_O= mydbcontempty.o
else ifeq ($(US_MODEL),M6410)
    TARGET_T= libmydbcont.a
	TARGET_O= mydbcontempty.o
else
    TARGET_T= libmydbcont.a
    TARGET_O= mydbcont.o
endif


############LIB COMPILE####################
$(TARGET_T): $(TARGET_O)
	$(BUILD_LIB)


