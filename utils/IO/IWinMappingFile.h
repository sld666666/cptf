#pragma once
#include "windows.h"
#include "../core/Log.h"

template <typename T>
class IWinMappingFile{

public:
	IWinMappingFile(){}
	virtual ~IWinMappingFile(){}

	char*	readFile(const wstring& filename);

private:
	HANDLE	openFile(const wstring& filename);
	HANDLE	createFileMap(const HANDLE fileHandle);
	char*	getData(const HANDLE handleMapping);
};

template<typename T>
char* IWinMappingFile<T>::readFile(const wstring& fileName)
{
	HANDLE handelFile = openFile(fileName);
	HANDLE handleMapping = createFileMap(handelFile);
	char* rtn = getData(handleMapping);
	CloseHandle(handleMapping);
	CloseHandle(handelFile);

	return rtn;
}

template<typename T>
HANDLE IWinMappingFile<T>::openFile(const wstring& fileName)
{
	HANDLE handel = ::CreateFile(fileName.c_str()
					, GENERIC_READ | GENERIC_WRITE
					, 0
					, NULL
					, OPEN_EXISTING
					, FILE_FLAG_SEQUENTIAL_SCAN
					, NULL);

	if (INVALID_HANDLE_VALUE == handel)
		LOG(ERROR) <<"can not open "<<fileName.c_str();

	return handel;
}

template<typename T>
HANDLE	IWinMappingFile<T>::createFileMap(const HANDLE fileHandle)
{
	ulong fileSize =  ::GetFileSize(fileHandle, NULL);
	HANDLE handel = ::CreateFileMapping(fileHandle
										, NULL
										, PAGE_READWRITE
										, 0
										, fileSize + 1
										, NULL);
	if (!handel)LOG(ERROR) <<"CreateFileMapping failed";

	return handel;
}

template<typename T>
char* IWinMappingFile<T>::getData(const HANDLE handleMapping)
{
	char* rtn = (char *)::MapViewOfFile(handleMapping
									, FILE_MAP_WRITE
									, 0
									, 0
									, 0);
	if (!rtn)LOG(ERROR) <<"Can't map file";
	return rtn;
}