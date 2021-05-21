# QT_QML_Extended
The purpose of this project is to practice extending QML using C++ objects and to demonstrate the power of pairing a QML Repeater{} with a C++ object.  This is a barebones project just meant to showcase certain features of the QT framework. This project is based upon the QT tutorial code extending-qml. When running this project from QTCreator, you will see the piechart object from the original tutorial and 2 emojis moving down the window. 

Instead of merely adding a static object as the original code does, I have added another C++ object called mainLoop{} to the qml.

MainLoop{} has a QTimer in it. Every time the QTimer goes off, it will run some logic which will increment the Y coordinates of blip objects that is drawn on the QML using a Repeater{}.  



QT functionality used:
extended QML with C++ objects using qmlRegisterType<>
extended QMl with C++ objects using setContextProperty()
Use QTimer to control mainLoop frequency
Use Repeater{} in QML to update the view with dynamically changing model information.
