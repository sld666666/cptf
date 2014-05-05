#pragma once

#include "FileReader.h"
#include "IWinMappingFile.h"

class MappingFileReader : public IFileReader
						, public IWinMappingFile<MappingFileReader>
{
public:
	MappingFileReader(void);
	~MappingFileReader(void);

public:
	virtual void	setFileName(const wstring& fileName);
	virtual char*	read();

private:
	wstring		fileName_;
};
