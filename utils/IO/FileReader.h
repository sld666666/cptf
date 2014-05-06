#pragma once
#include "TypeDefine.h"
#include "service/IDispatch.h"

const wstring IFileReader_IID = L"20aca551-d358-11e3-826c-bc305bacf447";
interfacecptf IFileReader : public cptf::core::IDispatch {

	virtual void	setFileName(const wstring& fileName) = 0;
	virtual char*	read() = 0;

};

const wstring  MappingFileReader_IID= L"30078930-d358-11e3-a119-bc305bacf447";


