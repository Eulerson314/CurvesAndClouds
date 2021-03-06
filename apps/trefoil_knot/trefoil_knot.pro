QT += gui core widgets network

CONFIG += c++11

DEFINES += PRECISION DOUBLE

DEPENDPATH += . ../../cnc_lib
INCLUDEPATH += ../../cnc_lib
LIBS += -L../../debug -L../../cnc_lib -lcnc_lib

SOURCES += \
        fibration.cpp \
        geodesy.cpp \
        knot.cpp \
        main.cpp \
        sampler.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    fibration.h \
    geodesy.h \
    knot.h \
    sampler.h
