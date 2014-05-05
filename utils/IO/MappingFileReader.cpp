#include "StdAfx.h"
#include "MappingFileReader.h"

MappingFileReader::MappingFileReader(void)
{
}

MappingFileReader::~MappingFileReader(void)
{
}

void MappingFileReader::setFileName(const wstring& fileName)
{
	fileName_ = fileName;
}

char* MappingFileReader::read()
{
	return readFile(fileName_);
}
