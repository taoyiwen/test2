#include "ShowImage.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());
	
	HRESULT hr=::CoInitialize(NULL);//以单线程方式加入com库

	if(FAILED(hr)) 
		return 0;
	ShowImage *showImage=new ShowImage(); 
	if(showImage==NULL)
		return 0;
	showImage->Create(NULL,_T("ShowImage_re"),UI_WNDSTYLE_FRAME,0L,0,0,800,572);
	showImage->CenterWindow(); 
	showImage->ShowWindow(*showImage,SW_SHOW); 
	CPaintManagerUI::MessageLoop();
	::CoUninitialize();
	return 0;


}



