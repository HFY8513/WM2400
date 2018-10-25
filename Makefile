#############################################################################
# Makefile for building: ZE_WM2400
# Generated by qmake (2.01a) (Qt 4.8.4) on: ?? 10? 24 16:54:28 2018
# Project:  ZE_WM2400.pro
# Template: app
# Command: c:/Qt/4.8.4/bin/qmake.exe -spec c:/Qt/4.8.4/mkspecs/win32-g++ -o Makefile ZE_WM2400.pro
#############################################################################

first: debug
install: debug-install
uninstall: debug-uninstall
MAKEFILE      = Makefile
QMAKE         = c:/Qt/4.8.4/bin/qmake.exe
DEL_FILE      = rm
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp
COPY_FILE     = $(COPY)
COPY_DIR      = cp -r
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = mv
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
SUBTARGETS    =  \
		debug \
		release

debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: ZE_WM2400.pro  c:/Qt/4.8.4/mkspecs/win32-g++/qmake.conf c:/Qt/4.8.4/mkspecs/features/device_config.prf \
		c:/Qt/4.8.4/mkspecs/qconfig.pri \
		c:/Qt/4.8.4/mkspecs/modules/qt_webkit_version.pri \
		c:/Qt/4.8.4/mkspecs/features/qt_functions.prf \
		c:/Qt/4.8.4/mkspecs/features/qt_config.prf \
		c:/Qt/4.8.4/mkspecs/features/exclusive_builds.prf \
		c:/Qt/4.8.4/mkspecs/features/default_pre.prf \
		c:/Qt/4.8.4/mkspecs/features/win32/default_pre.prf \
		api/api.pri \
		c:/Qt/4.8.4/mkspecs/features/debug.prf \
		c:/Qt/4.8.4/mkspecs/features/debug_and_release.prf \
		c:/Qt/4.8.4/mkspecs/features/default_post.prf \
		c:/Qt/4.8.4/mkspecs/features/win32/default_post.prf \
		c:/Qt/4.8.4/mkspecs/features/win32/rtti.prf \
		c:/Qt/4.8.4/mkspecs/features/win32/exceptions.prf \
		c:/Qt/4.8.4/mkspecs/features/win32/stl.prf \
		c:/Qt/4.8.4/mkspecs/features/shared.prf \
		c:/Qt/4.8.4/mkspecs/features/warn_on.prf \
		c:/Qt/4.8.4/mkspecs/features/qt.prf \
		c:/Qt/4.8.4/mkspecs/features/win32/thread.prf \
		c:/Qt/4.8.4/mkspecs/features/moc.prf \
		c:/Qt/4.8.4/mkspecs/features/win32/windows.prf \
		c:/Qt/4.8.4/mkspecs/features/resources.prf \
		c:/Qt/4.8.4/mkspecs/features/uic.prf \
		c:/Qt/4.8.4/mkspecs/features/yacc.prf \
		c:/Qt/4.8.4/mkspecs/features/lex.prf \
		c:/Qt/4.8.4/mkspecs/features/include_source_dir.prf \
		c:/Qt/4.8.4/lib/qtmaind.prl
	$(QMAKE) -spec c:/Qt/4.8.4/mkspecs/win32-g++ -o Makefile ZE_WM2400.pro
c:/Qt/4.8.4/mkspecs/features/device_config.prf:
c:/Qt/4.8.4/mkspecs/qconfig.pri:
c:/Qt/4.8.4/mkspecs/modules/qt_webkit_version.pri:
c:/Qt/4.8.4/mkspecs/features/qt_functions.prf:
c:/Qt/4.8.4/mkspecs/features/qt_config.prf:
c:/Qt/4.8.4/mkspecs/features/exclusive_builds.prf:
c:/Qt/4.8.4/mkspecs/features/default_pre.prf:
c:/Qt/4.8.4/mkspecs/features/win32/default_pre.prf:
api/api.pri:
c:/Qt/4.8.4/mkspecs/features/debug.prf:
c:/Qt/4.8.4/mkspecs/features/debug_and_release.prf:
c:/Qt/4.8.4/mkspecs/features/default_post.prf:
c:/Qt/4.8.4/mkspecs/features/win32/default_post.prf:
c:/Qt/4.8.4/mkspecs/features/win32/rtti.prf:
c:/Qt/4.8.4/mkspecs/features/win32/exceptions.prf:
c:/Qt/4.8.4/mkspecs/features/win32/stl.prf:
c:/Qt/4.8.4/mkspecs/features/shared.prf:
c:/Qt/4.8.4/mkspecs/features/warn_on.prf:
c:/Qt/4.8.4/mkspecs/features/qt.prf:
c:/Qt/4.8.4/mkspecs/features/win32/thread.prf:
c:/Qt/4.8.4/mkspecs/features/moc.prf:
c:/Qt/4.8.4/mkspecs/features/win32/windows.prf:
c:/Qt/4.8.4/mkspecs/features/resources.prf:
c:/Qt/4.8.4/mkspecs/features/uic.prf:
c:/Qt/4.8.4/mkspecs/features/yacc.prf:
c:/Qt/4.8.4/mkspecs/features/lex.prf:
c:/Qt/4.8.4/mkspecs/features/include_source_dir.prf:
c:\Qt\4.8.4\lib\qtmaind.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -spec c:/Qt/4.8.4/mkspecs/win32-g++ -o Makefile ZE_WM2400.pro

qmake_all: FORCE

make_default: debug-make_default release-make_default FORCE
make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile

check: first

debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
