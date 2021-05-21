#include <QtQuick/QQuickPaintedItem>
#include <QPainter>
#include <QCursor>
#include <memory>
#include "blipdisplaylistmodel.h"
#include "globals.h"
#include "mainloop.h"




static BlipDisplayListModel blipDisplayListModel;


void testblips();


MainLoop::MainLoop(QQuickItem *parent)
: super(parent),
  taskInterval(66),
 m_taskTimer(this)
{
    //connect(&m_inputConsole, SIGNAL(commandReceived(QString)), &m_tasks, SLOT(onConsoleCommandReceived(QString)));
    //m_inputConsole.start();
    connect(&m_taskTimer, SIGNAL(timeout()), this, SLOT(onTaskTimer()));
    m_taskTimer.setSingleShot(false);
    m_taskTimer.start(taskInterval);
    getRootContext()->setContextProperty("BlipDisplayListModel", QVariant::fromValue(&blipDisplayListModel));
}

MainLoop::~MainLoop()
{

}


Q_INVOKABLE void MainLoop::onTaskTimer()
{
    std::lock_guard<std::mutex> lck(m_mutex);

    //static int x = 16;
    static int y = 75;
    blipDisplayListModel.clear();
    QString v1 = QString("grin.png");
    QString v2 = QString("cute.png");
    blipDisplayListModel.drawBlip(100, y,v1);
    blipDisplayListModel.drawBlip(200, y,v2);
    y++;

    if(y > 250)
        y = 75;
}

void MainLoop::paint(QPainter *qp)
{
    std::lock_guard<std::mutex> lck(m_mutex);
    qp->save();
    qp->restore();
}
