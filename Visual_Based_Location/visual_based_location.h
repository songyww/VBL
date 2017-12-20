#ifndef VISUAL_BASED_LOCATION_H
#define VISUAL_BASED_LOCATION_H

/*****  ArcGIS ��ͷ�ļ�  *****/
#include <ArcSDK.h>


/******       QT ��ͷ�ļ�  *******/
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
#include <QTextCodec>///���qt��������ʱ��Ҫ��ӵ�ͷ�ļ�
#include <QFile> //ʹ��QDir����ʱ��Ҫ
#include <QTableWidget> //���������ʱ��Ҫ��������ͷ�ļ���֧�� 
#include <QTableWidgetItem>//�ڶԱ�����д��ʱ��Ҫ��ͷ�ļ�

/***  VC ��ͷ�ļ� ***/
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
