#pragma once

#include "TypeDefine.h"
#include "service/IDispatch.h"

const wstring IBundleTestor1_IID = L"333333";
interfacecptf IBundleTestor1 : public cptf::core::IDispatch{
	virtual cptf::IID getIID(){
		return IBundleTestor1_IID;
	}

	virtual bool test() = 0;

};

const wstring BundleTestor1_IID = L"114003cf-505f-11e3-9ce6-222222222222";