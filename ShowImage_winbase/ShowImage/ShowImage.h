#include "StdAfx.h"

#include <commdlg.h>





class ShowImage:public WindowImplBase{
public:
	 ShowImage(); //���캯��
	 LPCTSTR GetWindowClassName() const;
	 void OnFinalMessage(HWND /*hWnd*/);
	 void OpenFileDialog(); //���ļ���ѡ��ͼƬ
	 void LoadImage();   // ����ͼƬ
	 void Notify(TNotifyUI& msg); //��Ϣ��Ӧ
	
	 CDuiString GetSkinFile(); //����xml�ļ�
	 CDuiString GetSkinFolder();//ȷ��xml·��
	 //LRESULT OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	// LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL& bHandled);
	//LRESULT ShowImage::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

};