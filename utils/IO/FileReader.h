#pragma once
#include "../core/base.h"

sld_interface IFileReader{

	virtual void	setFileName(const wstring& fileName) = 0;
	virtual char*	read() = 0;

};
