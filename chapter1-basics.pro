QT += qml quick

HEADERS += piechart.h \
    blip.h \
    blipdisplaylistmodel.h \
    globals.h \
    mainloop.h
SOURCES += piechart.cpp \
           BlipDisplayListModel.cpp \
           globals.cpp \
           main.cpp \
           mainloop.cpp

RESOURCES += \
    chapter1-basics.qrc

DESTPATH = $$[QT_INSTALL_EXAMPLES]/qml/tutorials/extending-qml/chapter1-basics
target.path = $$DESTPATH

qml.files = *.qml
qml.path = $$DESTPATH

INSTALLS += target qml

DISTFILES += \
    RadarCarSmall1.png \
    RadarCarSmall2.png \
    RadarCarSmall3.png
