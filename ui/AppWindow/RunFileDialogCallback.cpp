#include "StdAfx.h"
#include "RunFileDialogCallback.h"
#include "../../utils/IO/FileReader.h"
#include "service/ServiceContainer.h"
#include "AppWindow.h"


using namespace cptf::core;

RunFileDialogCallback::RunFileDialogCallback(void)
{
}

RunFileDialogCallback::~RunFileDialogCallback(void)
{
}

void RunFileDialogCallback::OnFileDialogDismissed( CefRefPtr<CefBrowserHost> browser_host,
												 const std::vector<CefString>& file_paths)
{
	if(file_paths.empty()) return;

	CefRefPtr<CefProcessMessage> message =
		CefProcessMessage::Create("Editor.FileOpen");
	CefRefPtr<CefListValue> args = message->GetArgumentList();
	CefRefPtr<CefListValue> val = CefListValue::Create();

	ServiceContainer<CptfModule> container(&g_cptfModule);
	IFileReader* fileReader = static_cast<IFileReader*>(container.getService(
		MappingFileReader_IID, IFileReader_IID));
	if (fileReader){
		fileReader->setFileName(file_paths[0].c_str());
		char* content = fileReader->read();
		val->SetString(0, content);
	}

	args->SetList(0, val);

	// This will result in a call to the callback registered via JavaScript in
	// dialogs.html.
	browser_host->GetBrowser()->SendProcessMessage(PID_RENDERER, message);
}
