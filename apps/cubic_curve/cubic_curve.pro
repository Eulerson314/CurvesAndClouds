QT += gui core widgets network

CONFIG += c++11

DEPENDPATH += . ../../cnc_lib
INCLUDEPATH += ../../cnc_lib
LIBS += -L../../debug -L../../cnc_lib -lcnc_lib

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

