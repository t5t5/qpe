!isEmpty(QPE_INCLUDE_PRI_INCLUDED):error(qpe-include.pri already included)
QPE_INCLUDE_PRI_INCLUDED = 1

# отключаем генерацию debug и release (нужны для in-source сборки)
CONFIG -= debug_and_release debug_and_release_target

# пути к исходникам и результирующей сборке
isEmpty(QPE_SRC_DIR):QPE_SRC_DIR = $$PWD
isEmpty(QPE_BUILD_DIR):QPE_BUILD_DIR = $$shadowed($$PWD)

QPE_BUILD_TEST_DIR = $$QPE_BUILD_DIR/tests

QPE_SRC_DIR = $$PWD

# defines for static build qpe core
contains(DEFINES, QPE_CORE_LIB_STATIC) {
    QPE_CORE_BUILD_DIR = $$QPE_BUILD_DIR/lib
    QPE_CORE_CONFIG_STATICLIB = staticlib
} else {
    QPE_CORE_BUILD_DIR = $$QPE_BUILD_DIR
    QPE_CORE_CONFIG_STATICLIB =
}

# defines for static build qpe logger
contains(DEFINES, QPE_LOGGER_LIB_STATIC) {
    QPE_LOGGER_BUILD_DIR = $$QPE_BUILD_DIR/lib
    QPE_LOGGER_CONFIG_STATICLIB = staticlib
} else {
    QPE_LOGGER_BUILD_DIR = $$QPE_BUILD_DIR
    QPE_LOGGER_CONFIG_STATICLIB =
}

# дополнильные пути для include
# вынесено за проект, потому как у каждого разработчика и платформы пути могут отличаться
# эти пути можно задать при сборке проекта:
# qmake qpe.pro "INCLUDEPATH += some_path" ...
exists($$QPE_SRC_DIR/../qpe.includes.pri) {
    include($$QPE_SRC_DIR/../qpe.includes.pri)
}

# INCLUDEPATH
INCLUDEPATH += $$QPE_SRC_DIR/include

# определяем некоторые переменные в зависимости от системы сборки
equals(MAKEFILE_GENERATOR, MSBUILD) \
|equals(MAKEFILE_GENERATOR, MSVC.NET) \
|isEmpty(QMAKE_SH) {
    QPE_REMOVE_EXISTING_TREE = if exist %1 rmdir /s /q %1
    QPE_EXT_SHELL_SCRIPT = bat
} else {
    QPE_REMOVE_EXISTING_TREE = test -e %1 && rm -rf %1
    QPE_EXT_SHELL_SCRIPT = sh
}

# генерация документации
defineTest(documentTarget) {
    # $1 - path to "*.qdocconf" file

    # пока сборка документации возможна только под Windows
    !equals(QPE_EXT_SHELL_SCRIPT, bat) {
        message(Build docs only on Windows!)
        return(false)
    }

    qtPrepareTool(QDOC, qdoc)

    contains(DEFINES, DOCS_DEBUG) {
        QDOC_COMMAND_DEBUG = --debug
    } else {
        QDOC_COMMAND_DEBUG =
    }

    DOC_OUTPUTDIR = $$shell_quote($$shell_path($$QPE_BUILD_DIR/doc/$$TARGET))
    QDOC_COMMAND = \
        $$shell_quote($$shell_path($$QPE_SRC_DIR/script/tool/qdoc_wrapper.$$QPE_EXT_SHELL_SCRIPT)) \
            --qdoc $$shell_quote($$shell_path($$QDOC)) \
            --setenv \"QPE_SRC_DIR=$$shell_path($$QPE_SRC_DIR)\" \
            --outputdir $$DOC_OUTPUTDIR \
            $$QDOC_COMMAND_DEBUG \
            $$shell_quote($$shell_path($$1))

    begin_docs.target = begin_docs
    begin_docs.commands = @echo --------------------- begin generate documentation ---------------------
    begin_docs.depends = $(OBJECTS)
    export(begin_docs.target)
    export(begin_docs.commands)
    export(begin_docs.depends)

    generate_docs.target = generate_docs
    generate_docs.commands = call $$QDOC_COMMAND
    generate_docs.depends = begin_docs

    export(generate_docs.target)
    export(generate_docs.commands)
    export(generate_docs.depends)

    end_docs.target = docs
    end_docs.commands = @echo --------------------- end generate documentation -----------------------
    end_docs.depends = generate_docs
    export(end_docs.target)
    export(end_docs.commands)
    export(end_docs.depends)

    clean_docs.target = clean_docs
    clean_docs.commands = $$sprintf($$QPE_REMOVE_EXISTING_TREE, $$DOC_OUTPUTDIR)
    export(clean_docs.target)
    export(clean_docs.commands)
    export(clean_docs.depends)

    QMAKE_EXTRA_TARGETS += begin_docs generate_docs end_docs clean_docs
    export(QMAKE_EXTRA_TARGETS)
    CLEAN_DEPS += clean_docs
    export(CLEAN_DEPS)

    contains(DEFINES, DOCS_MAKE) {
        PRE_TARGETDEPS += docs
        export(PRE_TARGETDEPS)
    }

    return(true)
}
