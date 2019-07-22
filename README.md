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
Documenation build support only QDoc 5.10 (not above) on Windows.

### clean
Clean (and remove documentation if exists):
```
make clean
```
