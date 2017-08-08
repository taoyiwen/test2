
#include "ShowImage.h"



ShowImage::ShowImage() { };
LPCTSTR  ShowImage::GetWindowClassName() const { return _T("ShowImage"); };//获取窗体类名
void  ShowImage::OnFinalMessage(HWND /*hWnd*/) { delete this; };


	//加载图片
void ShowImage::OpenFileDialog(){
		TCHAR szFileName[MAX_PATH]={0};  //设置存储文件路径的字符串
		OPENFILENAME openFileName = {0};  //声明一个打开文件对话框结构体变量
		openFileName.lStructSize = sizeof(OPENFILENAME);  //window2000 以上使用这个来声明结构体大小
		openFileName.nMaxFile = MAX_PATH;  //这个必须设置，不设置的话不会出现打开文件对话框  
		openFileName.lpstrFilter=_T("图片(*.jpg)\0*.jpg\0图片(*.png)\0*.png\0所有文件(*.*)\0*.*\0\0"); //支持的图片打开格式 
		openFileName.lpstrFile =szFileName;  
		openFileName.nFilterIndex = 1;  
		openFileName.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;  
  
		if (GetOpenFileName(&openFileName))  
		{  
			//::MessageBoxA(NULL, (LPCSTR)szFileName[MAX_PATH], "", MB_OK);  
			CEditUI *pEdit=static_cast<CEditUI*>(m_PaintManager.FindControl(_T("imageURL")));
			pEdit->SetText((LPCTSTR)szFileName);
		}
	}
void ShowImage:: LoadImage(){
		CEditUI *pEdit=static_cast<CEditUI*>(m_PaintManager.FindControl(_T("imageURL")));//获取文本框对象
		CControlUI *pControl=static_cast<CControlUI*>(m_PaintManager.FindControl(_T("image")));//获取显示图片控件对象
		CDuiString imageurl=pEdit->GetText();   
		pControl->SetBkImage(imageurl.GetData()); //修改背景

	}
 
void ShowImage::Notify(TNotifyUI& msg)
    {
        if( msg.sType == _T("click") ) {
            if( msg.pSender->GetName() == _T("closebtn") ) {
                Close();
            }
			else if(msg.pSender->GetName() == _T("makesure")){
				//::MessageBox(NULL, _T("我是按钮"), _T("点击了按钮"), NULL);
				LoadImage();
			
			}else if(msg.pSender->GetName() == _T("chooseURL")){
				OpenFileDialog();
			}

        }
    }
	
CDuiString ShowImage::GetSkinFile()
{
	return _T("ShowImageSkin.xml");
}

CDuiString ShowImage::GetSkinFolder()
{

	return _T("");
}

//LRESULT ShowImage::OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
//{
//	/*CEditUI *pEdit=static_cast<CEditUI*>(m_PaintManager.FindControl(_T("imageURL")));
//	pEdit->SetTextColor(#FF4500);
//	Close();*/
//	return 0;
//}
//LRESULT ShowImage::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
//{
//	LONG styleValue = ::GetWindowLong(*this, GWL_STYLE);
//	styleValue &= ~WS_CAPTION;
//	::SetWindowLong(*this, GWL_STYLE, styleValue | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
//	RECT rcClient;
//	::GetClientRect(*this, &rcClient);
//	::SetWindowPos(*this, NULL, rcClient.left, rcClient.top, rcClient.right - rcClient.left, \
//		rcClient.bottom - rcClient.top, SWP_FRAMECHANGED);
//
//	m_PaintManager.Init(m_hWnd);
//	m_PaintManager.AddPreMessageFilter(this);
//
//	CDialogBuilder builder;
//	CDuiString strResourcePath=m_PaintManager.GetInstancePath();
//	strResourcePath=GetSkinFolder().GetData();
//	m_PaintManager.SetResourcePath(strResourcePath.GetData());
//
//	switch(GetResourceType())
//	{
//	case UILIB_ZIP:
//		m_PaintManager.SetResourceZip(GetZIPFileName().GetData(), true);
//		break;
//	case UILIB_ZIPRESOURCE:
//		{
//			HRSRC hResource = ::FindResource(m_PaintManager.GetResourceDll(), GetResourceID(), _T("ZIPRES"));
//			if( hResource == NULL )
//				return 0L;
//			DWORD dwSize = 0;
//			HGLOBAL hGlobal = ::LoadResource(m_PaintManager.GetResourceDll(), hResource);
//			if( hGlobal == NULL ) 
//			{
//#if defined(WIN32) && !defined(UNDER_CE)
//				::FreeResource(hResource);
//#endif
//				return 0L;
//			}
//			dwSize = ::SizeofResource(m_PaintManager.GetResourceDll(), hResource);
//			if( dwSize == 0 )
//				return 0L;
//			m_lpResourceZIPBuffer = new BYTE[ dwSize ];
//			if (m_lpResourceZIPBuffer != NULL)
//			{
//				::CopyMemory(m_lpResourceZIPBuffer, (LPBYTE)::LockResource(hGlobal), dwSize);
//			}
//#if defined(WIN32) && !defined(UNDER_CE)
//			::FreeResource(hResource);
//#endif
//			m_PaintManager.SetResourceZip(m_lpResourceZIPBuffer, dwSize);
//		}
//		break;
//	}
//
//	CControlUI* pRoot=NULL;
//	if (GetResourceType()==UILIB_RESOURCE)
//	{
//		STRINGorID xml(_ttoi(GetSkinFile().GetData()));
//		pRoot = builder.Create(xml, _T("xml"), this, &m_PaintManager);
//	}
//	else
//		pRoot = builder.Create(GetSkinFile().GetData(), (UINT)0, this, &m_PaintManager);
//	ASSERT(pRoot);
//	if (pRoot==NULL)
//	{
//		MessageBox(NULL,_T("加载资源文件失败"),_T("Duilib"),MB_OK|MB_ICONERROR);
//		ExitProcess(1);
//		return 0;
//	}
//	m_PaintManager.AttachDialog(pRoot);
//	m_PaintManager.AddNotifier(this);
//	m_PaintManager.SetBackgroundTransparent(TRUE);
//
//	InitWindow();
//	return 0;
//}


	
