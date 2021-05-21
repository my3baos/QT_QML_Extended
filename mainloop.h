#include <QtQuick/QQuickPaintedItem>
#include <QTimer>
#include <QCursor>
#include <memory>
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock_guard


class MainLoop : public QQuickPaintedItem
{
    Q_OBJECT
public:
    MainLoop(QQuickItem *parent=0);
    virtual ~MainLoop();
    //virtual QSize sizeHint() const;
    Q_INVOKABLE void onTaskTimer();
    void paint(QPainter *painter);

public slots:


signals:


private:
    typedef QQuickPaintedItem super;
    const int taskInterval;
    QTimer m_taskTimer;
    std::mutex m_mutex;
};
