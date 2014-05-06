#pragma once

#include "TypeDefine.h"
#include "service/IDispatch.h"

enum LoggerLevel{
	LL_ERROR = 0,
	LL_INFO,
	LL_WARNING
};

const wstring ILogger_IID = L"20aca551-d358-11e3-826c-bc305bacf447";
interfacecptf ILogger: public cptf::core::IDispatch {
	virtual void	init() = 0;
	virtual void	log(int level, const string& msg) = 0;
};