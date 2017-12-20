#ifndef VISUAL_BASED_LOCATION_H
#define VISUAL_BASED_LOCATION_H

/*****  ArcGIS 的头文件  *****/
#include <ArcSDK.h>


/******       QT 的头文件  *******/
#include <QtGui/QMainWindow>
#include "ui_visual_based_location.h"
#include <qstring.h>
#include <QtGui/QMessageBox>
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QUuid>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <QTextCodec>///解决qt中文乱码时需要添加的头文件
#include <QFile> //使用QDir定义时需要
#include <QTableWidget> //定义表格界面时需要下面两个头文件的支持 
#include <QTableWidgetItem>//在对表格进行写入时需要该头文件

/***  VC 的头文件 ***/
#include <vector>




class Visual_Based_Location : public QMainWindow
{
	Q_OBJECT

public:
	Visual_Based_Location(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Visual_Based_Location();

private:
	Ui::Visual_Based_LocationClass ui;
};

#endif // VISUAL_BASED_LOCATION_H
