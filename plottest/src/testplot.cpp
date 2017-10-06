#include"stdio.h"
#include"ros/ros.h"
#include"GUI/mainwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointF>
#include <QVector>
#include "GUI/qcustomplot.h"
int main(int argc, char **argv)
{
  ros::init(argc, argv, "testplot");
  QApplication app(argc, argv);
  MainWindow window;


      //QVector <QPointF> points;
     // Fill in points with n number of points
//     for(int i = 0; i< 10; i++)
//        points.append(QPointF(i*5, i*5));

//     // Create a view, put a scene in it and add tiny circles
//     // in the scene
//     QGraphicsView * view = new QGraphicsView();
//     QGraphicsScene * scene = new QGraphicsScene();
//     view->setScene(scene);

//     for(int i = 0; i< points.size(); i++)
//     {
//         scene->addEllipse(points[i].x(), points[i].y(), 1, 1);
//    }
//     // Show the view
//     view->show();

  window.show();
 return app.exec();
}
