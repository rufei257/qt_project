#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>
#include "math.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}



#define XRECT_S 400
#define YRECT_S 55 /*temp yrect */
#define RECT_XLEN 1080
#define RECT_YLEN 1020
#define Q_MAX_P  4096  /*JI ZUO BIAO */
#define GRAY_MAX 8

void Get_OPIont(QPoint* point)
{
#if 0
    point->x() = XRECT_S+RECT_XLEN/2;
    point->y() = YRECT_S+RECT_YLEN/2;
#else
    point->setX(XRECT_S+RECT_XLEN/2);
    point->setY(YRECT_S+RECT_YLEN/2);
    //qDebug("O point x:%d, y:%d\n",point->x(),point->y());
#endif
}


/***********************
 * q: jiaodu
 * p: len
 * x:
 * y:
 *
 * *********************/
void covertXY(int q, int p, QPoint* point)
{
    double q_temp=q*1.0*360/Q_MAX_P;
    QPoint oPoInt;

    Get_OPIont(&oPoInt);
#if 0
    point->x() =oPoInt.x() + p*sin(q_temp);
    point->y() =oPoInt.y() - p*cos(q_temp);
#else
    point->setX(oPoInt.x() + p*sin(q_temp));
    point->setY(oPoInt.y() - p*cos(q_temp));
#endif
}

int covertGay2Colour(int gray)
{
    return (0xff*gray/GRAY_MAX)&0xff;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //int x, y;
    //painter.drawLine(QPoint(0, 0), QPoint(100, 100));
    //painter.drawPoint(QPoint(110, 110));


#if 0
    QPoint point_new;
    covertXY(4096,400,&point_new);
    qDebug("new point x:%d, y:%d\n",point_new.x(),point_new.y());

    painter.drawPoint(point_new.x(),point_new.y());
#else
    for(int j=100;j<=500;j+=100)
    {
        int red = covertGay2Colour(j/100);

        qDebug("gay:%d covert red:%d\n",j/100,red);

        QColor clour(red,red,red);
        QPen pen(clour);
        painter.setPen(pen);

        for(int i=0;i<Q_MAX_P;i++)
        {
            QPoint point_new;
            covertXY(i,j,&point_new);
            painter.drawPoint(point_new.x(),point_new.y());
        }
    }
#endif

    //创建画笔
    QPen pen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    //使用画笔
    painter.setPen(pen);

    //绘制一个矩形
    //painter.drawRect(160, 20, 50, 40);
    painter.drawRect(XRECT_S, YRECT_S, RECT_XLEN, RECT_YLEN);
#if 0
    QRectF rectangle(70.0, 40.0, 80.0, 60.0);
    int startAngle = 30 * 16;
    int spanAngle = 120 * 16;
    //绘制圆弧
    painter.drawArc(rectangle, startAngle, spanAngle);


    //重新设置画笔
    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    //绘制一个矩形
    painter.drawRect(160, 20, 50, 40);
    // 创建画刷
    QBrush brush(QColor(0, 0, 255), Qt::Dense4Pattern);
    // 使用画刷
    painter.setBrush(brush);
    // 绘制椭圆
    painter.drawEllipse(220, 20, 50, 50);
    // 设置纹理
    brush.setTexture(QPixmap("../mydrawing/yafeilinux.png"));
    // 重新使用画刷
    painter.setBrush(brush);
    // 定义四个点
    static const QPointF points[4] = {
        QPointF(270.0, 80.0),
        QPointF(290.0, 10.0),
        QPointF(350.0, 30.0),
        QPointF(390.0, 70.0)
    };
    // 使用四个点绘制多边形
    painter.drawPolygon(points, 4);

    // 使用画刷填充一个矩形区域
    painter.fillRect(QRect(10, 100, 150, 20), QBrush(Qt::darkYellow));
    // 擦除一个矩形区域的内容
    painter.eraseRect(QRect(50, 0, 50, 120));
#endif

#if 0
    // 线性渐变
    QLinearGradient linearGradient(QPointF(40, 190), QPointF(70, 190));
    // 插入颜色
    linearGradient.setColorAt(0, Qt::yellow);
    linearGradient.setColorAt(0.5, Qt::red);
    linearGradient.setColorAt(1, Qt::green);
    // 指定渐变区域以外的区域的扩散方式
    linearGradient.setSpread(QGradient::RepeatSpread);
    // 使用渐变作为画刷
    painter.setBrush(linearGradient);
    painter.drawRect(10, 170, 90, 40);

    // 辐射渐变
    QRadialGradient radialGradient(QPointF(200, 190), 50, QPointF(275, 200));
    radialGradient.setColorAt(0, QColor(255, 255, 100, 150));
    radialGradient.setColorAt(1, QColor(0, 0, 0, 50));
    painter.setBrush(radialGradient);
    painter.drawEllipse(QPointF(200, 190), 50, 50);

    // 锥形渐变
    QConicalGradient conicalGradient(QPointF(350, 190), 60);
    conicalGradient.setColorAt(0.2, Qt::cyan);
    conicalGradient.setColorAt(0.9, Qt::black);
    painter.setBrush(conicalGradient);
    painter.drawEllipse(QPointF(350, 190), 50, 50);

    // 画笔使用线性渐变来绘制直线和文字
    painter.setPen(QPen(linearGradient,2));
    painter.drawLine(0, 280, 100, 280);
    //painter.drawText(150, 280, tr("helloQt!"));
#endif
    //painter.drawText(150, 280, tr("hello804!"));
}
