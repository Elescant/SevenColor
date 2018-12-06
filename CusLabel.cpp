#include "CusLabel.h"
#include <QPalette>
#include <QDebug>

CusLabel::CusLabel(QWidget *parent, Qt::WindowFlags f):
    QLabel(parent,f)
{

}

CusLabel::CusLabel(const QString &text, QWidget *parent, Qt::WindowFlags f):
    QLabel(text,parent,f)
{

}

CusLabel::~CusLabel()
{

}

void CusLabel::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    emit clicked();
    QString str=QString("rgb(%1,%2,%3)").arg(color.red()).arg(color.green()).arg(color.blue());
    this->setStyleSheet("background-color:"+str);
}

void CusLabel::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    QPalette pat = palette();
    color = pat.color(QPalette::Background);

    QColor temp = lightenDarkenColor(color,-20);
    this->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(temp.red()).arg(temp.green()).arg(temp.blue()));
}

QColor CusLabel::lightenDarkenColor(QColor color,int factor)
{
    QColor newColor;
    newColor.setRed(qBound(0,color.red() + factor,255));
    newColor.setGreen(qBound(0,color.green() + factor,255));
    newColor.setBlue(qBound(0,color.blue() + factor,255));
    return newColor;
}











