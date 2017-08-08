
#include "ShowImage.h"



ShowImage::ShowImage() { };
LPCTSTR  ShowImage::GetWindowClassName() const { return _T("ShowImage"); };//��ȡ��������
void  ShowImage::OnFinalMessage(HWND /*hWnd*/) { delete this; };


	//����ͼƬ
void ShowImage::OpenFileDialog(){
		TCHAR szFileName[MAX_PATH]={0};  //���ô洢�ļ�·�����ַ���
		OPENFILENAME openFileName = {0};  //����һ�����ļ��Ի���ṹ�����
		openFileName.lStructSize = sizeof(OPENFILENAME);  //window2000 ����ʹ������������ṹ���С
		openFileName.nMaxFile = MAX_PATH;  //����������ã������õĻ�������ִ��ļ��Ի���  
		openFileName.lpstrFilter=_T("ͼƬ(*.jpg)\0*.jpg\0ͼƬ(*.png)\0*.png\0�����ļ�(*.*)\0*.*\0\0"); //֧�ֵ�ͼƬ�򿪸�ʽ 
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
		CEditUI *pEdit=static_cast<CEditUI*>(m_PaintManager.FindControl(_T("imageURL")));//��ȡ�ı������
		CControlUI *pControl=static_cast<CControlUI*>(m_PaintManager.FindControl(_T("image")));//��ȡ��ʾͼƬ�ؼ�����
		CDuiString imageurl=pEdit->GetText();   
		pControl->SetBkImage(imageurl.GetData()); //�޸ı���

	}
 
void ShowImage::Notify(TNotifyUI& msg)
    {
        if( msg.sType == _T("click") ) {
            if( msg.pSender->GetName() == _T("closebtn") ) {
                Close();
            }
			else if(msg.pSender->GetName() == _T("makesure")){
				//::MessageBox(NULL, _T("���ǰ�ť"), _T("����˰�ť"), NULL);
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
//		MessageBox(NULL,_T("������Դ�ļ�ʧ��"),_T("Duilib"),MB_OK|MB_ICONERROR);
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


	
