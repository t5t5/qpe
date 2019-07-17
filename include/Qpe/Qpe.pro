TEMPLATE = aux

# core mpl
HEADERS += \
    Core/mpl/math_power

# core private
HEADERS += \
    Core/Private/conversionpattern_defines.h \
    Core/Private/conversionpattern_impl.h \
    Core/Private/digitscount_dec.h \
    Core/Private/digitscount_hex.h \
    Core/Private/static_stringifier.h

# core
HEADERS += \
    Core/ConversionPattern \
    Core/CronTimer \
    Core/CronTimerExpression \
    Core/DateStringifier \
    Core/Enum \
    Core/Math \
    Core/SimpleConversionPattern \
    Core/StaticStringifierDec \
    Core/StaticStringifierHex \
    Core/Stringifier \
    Core/TypeTraits

# logger private
HEADERS += \
    Logger/Private/abstractpatternloggerappender_p.h

# logger
HEADERS += \
    Logger/AbstractPatternLoggerAppender \
    Logger/EventType \
    Logger/Logger \
    Logger/LoggerAppender \
    Logger/LoggerEvent \
    Logger/LoggerFilter

# global
HEADERS += \
    Global \
    Qpe
