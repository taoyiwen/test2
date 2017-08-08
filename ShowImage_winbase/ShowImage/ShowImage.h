#include "StdAfx.h"

#include <commdlg.h>





class ShowImage:public WindowImplBase{
public:
	 ShowImage(); //构造函数
	 LPCTSTR GetWindowClassName() const;
	 void OnFinalMessage(HWND /*hWnd*/);
	 void OpenFileDialog(); //打开文件框选择图片
	 void LoadImage();   // 加载图片
	 void Notify(TNotifyUI& msg); //消息响应
	
	 CDuiString GetSkinFile(); //加载xml文件
	 CDuiString GetSkinFolder();//确定xml路径
	 //LRESULT OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	// LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL& bHandled);
	//LRESULT ShowImage::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

};