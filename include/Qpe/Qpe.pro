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
    Core/DateStringifier \
    Core/Math \
    Core/SimpleConversionPattern \
    Core/StaticStringifierDec \
    Core/StaticStringifierHex \
    Core/Stringifier \
    Core/TypeTraits

# global
HEADERS += \
    Global \
    Qpe
