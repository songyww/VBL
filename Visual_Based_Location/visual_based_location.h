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

/*****  opencv的头文件  *****/
#include <opencv2/opencv.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/legacy/compat.hpp>
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>



/***  VC 的头文件 ***/
#include <vector>

/*****  SURF算法头文件 *****/
#include "SURF.h"

/*****使用CSrting时需要用到的头文件*****/
#include <atlstr.h>

/***自己编写的头文件***/
#include "Pyramid_with_GDAL.h"
#include "process.h"
#include "process_with_surf.h"

#include "ximage.h"



class Visual_Based_Location : public QMainWindow
{
	Q_OBJECT

public:
	Visual_Based_Location(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Visual_Based_Location();

private:
	Ui::Visual_Based_LocationClass ui;


private slots:
	bool OpenFile1();//打开数字地图



public:
	/*数字地图加载控件定义*/
	IMapControl3Ptr m_pMapControl1;
	IToolbarControlPtr m_pToolbarControl1;
	ITOCControlPtr m_pTOCControl1;

	/*估计的大致区域图像加载控件定义*/
	IMapControl3Ptr m_pMapControl2;
	IToolbarControlPtr m_pToolbarControl2;
	ITOCControlPtr m_pTOCControl2;

	/*目标图像加载控件定义*/
	IMapControl3Ptr m_pMapControl3;
	IToolbarControlPtr m_pToolbarControl3;
	ITOCControlPtr m_pTOCControl3;
public:
	/*控件工具条设置函数*/
	void AddMapToolBarCtr(IToolbarControlPtr pToolbar);//map

};

#endif // VISUAL_BASED_LOCATION_H
