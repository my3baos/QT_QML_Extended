#ifndef BLIP_H
#define BLIP_H


#include <QObject>
#include <QString>

/*
    class Blip is C++ object that represents a car pic with (x,y) coords.
*/
class Blip
{
public:
    Blip()
    : m_x(0)
    , m_y(0)
    , m_Pic()
    {
    }

    Blip(
        int x1,
        int y1,
        QString pic)
    {

        this->m_x = x1;
        this->m_y = y1;
        //qDebug()<<"carpic is "<< carPic;
        this->m_Pic = pic;
        //this->testStr = "testStr";

    }

    void setX(int x) { if (m_x != x) { m_x = x; } }
    int x() const { return m_x; }

    void setY(int y) { if (m_y != y) { m_y = y;  } }
    int y() const { return m_y; }


    void setPic(QString pic) { if (m_Pic != pic) { m_Pic = pic; } }
    QString pic() const { return m_Pic; }

signals:
    void xChanged(int);
    void yChanged(int);
    void picChanged(QString);

public:
    int x1;
    int y1;


private:
    int m_x;
    int m_y;
    QString m_Pic;
    std::string testStr;
};

#endif // BLIP_H
