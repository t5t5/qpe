# Qpe

## Building project

### build exutable
Shadow build only available (out of source build).
```
cd path-to-shadow-build
qmake "DEFINES += QPE_CORE_LIB_STATIC QPE_CORE_MAKE_TESTS DOCS_MAKE DOCS_DEBUG" path-to-src-dir/ids-core.pro
make
```
**qmake** build parameters:
- QPE_CORE_LIB_STATIC - optional DEFINE parameter - for static build qpecore library;
- QPE_CORE_MAKE_TESTS - optional DEFINE parameter - for build tests qpecore library;
- QPE_LOGGER_LIB_STATIC - optional DEFINE parameter - for static build logger library;
- QPE_LOGGER_MAKE_TESTS - optional DEFINE parameter - for build tests logger library;
- DOCS_MAKE - optional DEFINE parameter - for build documentation;
- DOCS_DEBUG - optional DEFINE parameter - for debug build documentaion (if DOCS_MAKE is set).

### build documentation
Documentation can be built separately:
```
make docs
```
Additional processing is used to assemble the documentation, it's for complete logging and suppress of some error (script/tool/qdoc_wrapper.bat).
Documenation build tested on QDoc 5.15.2 on Windows.

#### example build documentation on Windows

core:
```
call C:\sources\qpe\script\tool\qdoc_wrapper.bat ^
   --qdoc C:\Qt\5.15.2\mingw81_64\bin\qdoc.exe ^
   --setenv "QPE_SRC_DIR=C:\sources\qpe" ^
   --setenv "QT_INSTALL_DOCS=C:\Qt\Docs\Qt-5.15.2" ^
   --setenv "QT_INSTALL_HEADERS=C:\Qt\5.15.2\mingw81_64\include" ^
   --outputdir C:\sources\qpe-build\doc\qpecore ^
   C:\sources\qpe\src\core\doc\core.qdocconf
```

logger:
```
call C:\sources\qpe\script\tool\qdoc_wrapper.bat ^
   --qdoc C:\Qt\5.15.2\mingw81_64\bin\qdoc.exe ^
   --setenv "QPE_SRC_DIR=C:\sources\qpe" ^
   --setenv "QT_INSTALL_DOCS=C:\Qt\Docs\Qt-5.15.2" ^
   --setenv "QT_INSTALL_HEADERS=C:\Qt\5.15.2\mingw81_64\include" ^
   --outputdir C:\sources\qpe-build\doc\qpelogger ^
   C:\sources\qpe\src\logger\doc\logger.qdocconf
```

### clean
Clean (and remove documentation if exists):
```
make clean
```
