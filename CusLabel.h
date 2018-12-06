#ifndef CUSLABEL_H
#define CUSLABEL_H

#include <QObject>
#include <QLabel>
#include <QColor>

class CusLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CusLabel(QWidget *parent = 0,Qt::WindowFlags f=0);
    explicit CusLabel(const QString &text,QWidget *parent=0,Qt::WindowFlags f=0);


    ~CusLabel();
protected:


    // QWidget interface
protected:
    void mouseReleaseEvent(QMouseEvent *event);
signals:
    void clicked(void);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
private:
    QColor color;
    QColor lightenDarkenColor(QColor color, int factor);
};

#endif // CUSLABEL_H
