#pragma once

#include "FileReader.h"
#include "IWinMappingFile.h"
#include "service/ServiceCoClass.h"
#include "service/IDispatchImpl.h"
#include "service/ObjectRoot.h"
#include "service/ThreadModel.h"
#include "service/CpftBase.h"

using namespace cptf::core;

class MappingFileReader :  public ServiceCoClass<MappingFileReader>
						, public ObjectRoot<SingleThreadModel>
						, public IDispatchImpl<IFileReader> 
						, public IWinMappingFile<MappingFileReader>
{
public:
	MappingFileReader(void);
	~MappingFileReader(void);

	static wstring	 clsid() {return MappingFileReader_IID;}

public:
	virtual void	setFileName(const wstring& fileName);
	virtual char*	read();

private:
	wstring		fileName_;

	CPTF_BEGIN_SERVICE_MAP(MappingFileReader)
		CPTF_SERVICE_INTERFACE_ENTRY(IFileReader_IID, IFileReader)
	CPTF_END_SERVICE_MAP()
};

CPTF_OBJECT_ENTRY_AUTO(MappingFileReader)
