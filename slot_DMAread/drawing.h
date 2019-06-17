#ifndef DRAWING_H
#define DRAWING_H

#include <QDialog>
#include <QPainter>
#include <QFile>
#include <QDebug>
#include <QMouseEvent>
#include <QPoint>

#define BEGIN 37

extern QString path;
struct place{
    int id;
    QString name;
    float x;
    float y;
    QList<int> value;
};

namespace Ui {
class drawing;
}

class drawing : public QDialog
{
    Q_OBJECT

public:
    explicit drawing(QWidget *parent = 0);
    ~drawing();

private:
    Ui::drawing *ui;
    QPixmap pix;
    QList<struct place> placeList;
    QPoint mousePoint;
    QPoint lastmousePoint;

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent*);
};

#endif // DRAWING_H
