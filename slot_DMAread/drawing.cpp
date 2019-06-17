#include "drawing.h"
#include "ui_drawing.h"


drawing::drawing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drawing)
{
    ui->setupUi(this);
    resize(6000,1000);
    pix=QPixmap(6000,1000);
    pix.fill(Qt::white);
}

drawing::~drawing()
{
    delete ui;
}

void drawing::paintEvent(QPaintEvent *)
{
    QStringList time_QString;
    int time_count;


    QPainter pp(this);
    pp.drawPixmap(0,0,pix);
    QPainter pai(&pix);
    QPen pen;
    pen.setWidth(2);//设置线宽
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
     //设定画刷
    QBrush brush;
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    //将画笔交给“画家”
    pai.setPen(pen);
    //将画刷交给“画家”
    pai.setBrush(brush);
    //设置字体
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setLetterSpacing(QFont::AbsoluteSpacing,0);
    font.setPointSize(10);
    //将字体交给“画家”
    pai.setFont(font);


    QFile DMAreadFile(path);
    if(!DMAreadFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"没有数据！";
    }
    else
    {
        while(!DMAreadFile.atEnd())
        {
            QByteArray array;
            QString thisLine;
            QRegExp rx("(\\d+)");
            int pos=0;
            array=DMAreadFile.readLine();
            thisLine=QString(array);
            if(thisLine[0]=='=')
            {
                continue;
            }
            else
            {
                QStringList LineData;
                for(int i=0;i<2;i++)
                {
                    pos = rx.indexIn(thisLine, pos);
                    LineData<<rx.cap(0);
                    pos += rx.matchedLength();
                }
                time_QString<<LineData[1];
            }
        }

    }
    DMAreadFile.close();
    time_count=time_QString.count();
    for(int i=0;i<14;i++)
    {
        struct place newplace;
        newplace.id=i;
        placeList<<newplace;
    }
    placeList[0].name="a";
    placeList[1].name="b";
    placeList[2].name="c";
    placeList[3].name="d";
    placeList[4].name="e";
    placeList[5].name="cl";
    placeList[6].name="cp";
    placeList[7].name="cv";
    placeList[8].name="s1";
    placeList[9].name="s2";
    placeList[10].name="s3";
    placeList[11].name="dish";
    placeList[12].name="compote";
    placeList[13].name="meet";
    for(int i=0;i<time_count;i++)
    {
        for(int j=0;j<14;j++)
        {
            QString thisdata=time_QString[i].mid(BEGIN+5*j,5);
            bool ok;
            int num=thisdata.toInt(&ok,2);
            placeList[j].value<<num;
        }
    }

    //for(int i=0;i<14;i++)
    //{
        //qDebug()<<placeList[i].value;
    //}
    //qDebug()<<time_QString;
    //qDebug()<<time_count;
    int x_axis_f = 100;
    for (int i = 0; i < time_count; i++)
    {
        QString times_str=QString::number(i, 10);
        pai.drawText(x_axis_f, 40,QString(times_str));
        x_axis_f = x_axis_f + 50;
    }
    for(int i = 0; i < 14; i++)
    {
        placeList[i].x=78;
        placeList[i].y=100+50*i;
    }
    for(int i = 0; i < 14; i++)
    {
        float x_axis=placeList[i].x;
        float y_axis=placeList[i].y;
        pai.drawText(15, y_axis,placeList[i].name);
        pai.drawLine(x_axis, y_axis + 15,x_axis + 50, y_axis + 15);
        pai.drawLine(x_axis, y_axis - 15,x_axis + 50, y_axis - 15);
        QString color_str=QString::number(placeList[i].value[0], 10);
        pen.setColor(Qt::red);
        pai.setPen(pen);
        pai.drawText(x_axis + 10, y_axis+5,QString("0x"+color_str));
        pen.setColor(Qt::black);
        pai.setPen(pen);
        for(int j = 1; j < time_count; j++)
        {
            if(placeList[i].value[j]==placeList[i].value[j-1])
            {
                pai.drawLine(x_axis+j*50, y_axis+15,x_axis+50+j*50, y_axis+15);
                pai.drawLine(x_axis+j*50, y_axis-15,x_axis+50+j*50, y_axis-15);
            }
            else if(placeList[i].value[j]!=placeList[i].value[j-1])
            {
                pai.drawLine(x_axis+j*50, y_axis+15,x_axis+10+j*50, y_axis+15);
                pai.drawLine(x_axis+j*50, y_axis-15,x_axis+10+j*50, y_axis-15);
                pai.drawLine(x_axis+10+j*50, y_axis-15,x_axis+40+j*50, y_axis+15);
                pai.drawLine(x_axis+10+j*50, y_axis+15,x_axis+40+j*50, y_axis-15);
                pai.drawLine(x_axis+40+j*50, y_axis+15,x_axis+50+j*50, y_axis+15);
                pai.drawLine(x_axis+40+j*50, y_axis-15,x_axis+50+j*50, y_axis-15);
                color_str=QString::number(placeList[i].value[j], 10);
                pen.setColor(Qt::red);
                pai.setPen(pen);
                pai.drawText(x_axis+30+j*50, y_axis+5,QString("0x"+color_str));
                pen.setColor(Qt::black);
                pai.setPen(pen);
            }
        }
    }
    if(mousePoint.rx()>78&&mousePoint.ry()<(100+50*13+15))
    {
        qDebug()<<placeList.count();
        qDebug()<<mousePoint.rx();
        qDebug()<<mousePoint.ry();
        pen.setColor(Qt::green);
        pai.setPen(pen);
        pai.drawLine(mousePoint.rx(), 100-20,mousePoint.rx(), 100+50*13+15);

        pen.setColor(Qt::black);
        lastmousePoint=mousePoint;
    }

}

void drawing::mousePressEvent(QMouseEvent*event)
{
    if(event->button()==Qt::LeftButton)
    {
        mousePoint=event->pos();
        repaint();
    }
}












































