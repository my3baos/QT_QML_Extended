#ifndef _GLOBALS_H_
#define _GLOBALS_H_


#include <QPainter>
#include <QQmlContext>
#include <string>


#define CARBLUE     "pics/RadarCarSmall1.png"
#define CARGREEN    "pics/RadarCarSmall2.png"
#define CARORANGE   "pics/RadarCarSmall3.png"
#define CARRED      "pics/RadarCarSmall4.png"
#define CARYELLOW   "pics/RadarCarSmall5.png"


int getFontWidth();
void saveRootContext(QQmlContext *context);
QQmlContext* getRootContext();

void initGlobalStateModel();


void initGlobals();
void closeGlobals();

#endif // _GLOBALS_H_
