# QT_QML_Extended
The purpose of this project is to practice extending QML using C++ objects and to demonstrate the power of pairing a QML Repeater{} with a C++ object

This project is based upon the QT tutorial code extending-qml. Instead of merely adding a static object, I have added another C++ object called mainLoop{} to the qml.

MainLoop{} has a QTimer in it. Every time the QTimer goes off, it will run some logic which will increment the Y coordinates of blip objects that is drawn on the QML using a Repeater{}.

