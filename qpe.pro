TEMPLATE = subdirs

SUBDIRS += include
SUBDIRS += src

OTHER_FILES += \
    qpe-include.pri


OTHER_FILES += \
    script/tool/qdoc_wrapper.bat \
    script/tool/expand_path.bat \
    doc/style/style.css \
    doc/common.qdocconf \
    doc/qpe-cpp-ignore.qdocconf \
    doc/qt-cpp-ignore.qdocconf \
    qpe-include.pri \
    README.md
