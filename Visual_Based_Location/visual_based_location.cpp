#include "visual_based_location.h"
#include <comutil.h>
#include <direct.h>  
#include <io.h>  
#include <windows.h>
#include <QUuid>
#include "ximage.h"




/*ȫ�ֱ���*/

/*��������ͼ���·���Լ�����ͼ�������ļ���·��*/
vector<string> BigMap;


using namespace std;
using namespace cv;





Visual_Based_Location::Visual_Based_Location(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	/*�ؼ���������*/
	ui.MapCtr1->setControl("{C552EA94-6FBB-11d5-A9C1-00104BB6FC1C}");
	ui.MapCtr2->setControl("{C552EA94-6FBB-11d5-A9C1-00104BB6FC1C}");
	ui.MapCtr3->setControl("{C552EA94-6FBB-11d5-A9C1-00104BB6FC1C}");

	ui.MapToolBarCtr1->setControl("{B7D4358E-3CBC-11D6-AA09-00104BB6FC1C}");
	ui.MapToolBarCtr2->setControl("{B7D4358E-3CBC-11D6-AA09-00104BB6FC1C}");
	ui.MapToolBarCtr3->setControl("{B7D4358E-3CBC-11D6-AA09-00104BB6FC1C}");

	ui.MapTocCtr1->setControl("{A0F9A9A2-4A3F-4888-826F-CA2BFA23CF17}");;
	ui.MapTocCtr2->setControl("{A0F9A9A2-4A3F-4888-826F-CA2BFA23CF17}");
	ui.MapTocCtr3->setControl("{A0F9A9A2-4A3F-4888-826F-CA2BFA23CF17}");;

	/*�ؼ���ָ�����*/
	ui.MapCtr1->queryInterface(QUuid(IID_IMapControl3),(void**)&m_pMapControl1);
	ui.MapCtr2->queryInterface(QUuid(IID_IMapControl3),(void**)&m_pMapControl2);
	ui.MapCtr3->queryInterface(QUuid(IID_IMapControl3),(void**)&m_pMapControl3);

	ui.MapToolBarCtr1->queryInterface(QUuid(IID_IToolbarControl),(void**)&m_pToolbarControl1);
	ui.MapToolBarCtr2->queryInterface(QUuid(IID_IToolbarControl),(void**)&m_pToolbarControl2);
	ui.MapToolBarCtr3->queryInterface(QUuid(IID_IToolbarControl),(void**)&m_pToolbarControl3);

	ui.MapTocCtr1->queryInterface(QUuid(IID_ITOCControl),(void**)&m_pTOCControl1);
	ui.MapTocCtr2->queryInterface(QUuid(IID_ITOCControl),(void**)&m_pTOCControl2);
	ui.MapTocCtr3->queryInterface(QUuid(IID_ITOCControl),(void**)&m_pTOCControl3);

	/*�ؼ�֮�����������*/
	m_pToolbarControl1->SetBuddyControl(m_pMapControl1);
	m_pToolbarControl2->SetBuddyControl(m_pMapControl2);
	m_pToolbarControl3->SetBuddyControl(m_pMapControl3);

	m_pTOCControl1->SetBuddyControl(m_pMapControl1);
	m_pTOCControl2->SetBuddyControl(m_pMapControl2);
	m_pTOCControl3->SetBuddyControl(m_pMapControl3);

	/*�������ӹ���������*/

	AddMapToolBarCtr(m_pToolbarControl1);
	AddMapToolBarCtr(m_pToolbarControl2);
	AddMapToolBarCtr(m_pToolbarControl3);



	//����pushbutton�ؼ���ͼ��
	connect(ui.pushButton_7,SIGNAL(clicked()),this,SLOT(OpenFile1()));


}

Visual_Based_Location::~Visual_Based_Location()
{

}


void Visual_Based_Location::AddMapToolBarCtr(IToolbarControlPtr pToolbar)
{
	CComVariant varTool;
	long itemIndex;

	if (!pToolbar) 
		return;

	varTool = L"esriControlCommands.ControlsAddDataCommand";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapZoomInTool";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapZoomOutTool";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapZoomInFixedCommand";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapZoomOutFixedCommandl";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapPanTool";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapFullExtentCommand";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapZoomToLastExtentBackCommand";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);
	varTool = L"esriControlCommands.ControlsMapZoomToLastExtentForwardCommand";
	pToolbar->AddItem(varTool, 0, -1, VARIANT_FALSE, 0,
		esriCommandStyleIconOnly, &itemIndex);

}

bool Visual_Based_Location::OpenFile1()
{
	GDALAllRegister();
	PyramidBase pyramid1;
	BigMap.clear();

	QString file_full1,file_name1,m_strFileName1;
	QString file_path1 = NULL;
	String reImg_full,reImg_path;	//reimg_full:ͼ�������·����reimg_path��ͼ�������ļ���·��

	////*�������ļ��Ի���ѡ��򿪵��ļ����������ļ�·��*////
	QFileInfo fi;		  
	file_full1 = QFileDialog::getOpenFileName(this,"open the first picture",file_path1);  
	fi = QFileInfo(file_full1);  
	m_strFileName1=fi.absoluteFilePath();
	/*ͨ��find_last_of()�������ҵ���ǰ�򿪵��ļ������ļ���·����������*/
	reImg_full = m_strFileName1.toStdString();////QString ת��Ϊstring///ͼ������·��
	int po = reImg_full.find_last_of('/');
	reImg_path = reImg_full.substr( 0,po+1); ///�ļ���·��

	/*�����ֵ�ͼ·�����������ļ���·��������ȫ�ֱ�����*/
	/*��������ԭ������Ϊ����ÿһ��ͼ��λ��ɺ���Ҫ��ʾ�ڸ����ֵ�ͼ��  */
	BigMap.push_back(reImg_path);//BigMap[0]:���ֵ�ͼ�����ļ���·��
	BigMap.push_back(reImg_path);//BigMap[1]:���ֵ�ͼ����·��·��

	//*���ο�ͼ�񱣴��������������·���У��Ա��������ͼ�������*/
	pyramid1.InFilePath = reImg_full.c_str();	//�ο�ͼ������·��
	pyramid1.FilePath = reImg_path.c_str();		//�ο�ͼ�������ļ���·��

	pyramid1.InFile = (GDALDataset*)GDALOpen(pyramid1.InFilePath, GA_ReadOnly);		//��·���е��ļ����뵽���ݼ���
	if (pyramid1.InFile == NULL)
	{
		QMessageBox::information(this, tr("Information"),tr("��ͼ��ʧ�ܣ���ѡ����ȷ·����"));
		return false;
	}
	pyramid1.CheckPyramid();

	/*Map�ؼ���ʾ�ο�ͼ��*/
	BSTR bstr_str;

	bstr_str = SysAllocString(m_strFileName1.utf16());

	HRESULT hr;

	IRasterLayerPtr pRasterLy(CLSID_RasterLayer);

	hr=pRasterLy->CreateFromFilePath(bstr_str);

	if(FAILED(hr))

	{
		return false;
	}

	ILayerPtr pLyr(pRasterLy);

	m_pMapControl1->AddLayer(pLyr,0);

	IActiveViewPtr pActiveView(m_pMapControl1);

	m_pMapControl1->Refresh(esriViewAll);  

}