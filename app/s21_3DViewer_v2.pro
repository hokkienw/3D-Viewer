QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets openglwidgets

CONFIG += c++17

include(../QtGifImage/src/gifimage/qtgifimage.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += GL_SILENCE_DEPRECATION
SOURCES += \
    main.cc \
    controller/controller.cc \
    model/facade.cc \
    model/parcer.cc \
    model/transform.cc \
    view/scene3d.cc \
    view/strategy_wired_renderer.cc \
    view/singltone_scene_renderer_manager.cc \
    view/viewer.cc


HEADERS += \
    controller/controller.h \
    model/facade.h \
    model/parcer.h \
    model/data.h \
    model/transform.h \
    view/scene3d.h \
    view/strategy_wired_renderer.h \
    view/strategy_renderer.h \
    view/strategy_filled_renderer.h \
    view/singltone_scene_renderer_manager.h \
    view/viewer.h

FORMS += \
    view/viewer.ui

LIBS += -framework GLUT

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

macx:ICON = $${PWD}/4.icns
