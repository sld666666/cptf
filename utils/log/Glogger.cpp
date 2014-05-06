#include "StdAfx.h"
#include "Glogger.h"
#include "glog/include/logging.h"
Glogger::Glogger()
{
}

Glogger::~Glogger()
{
}

void Glogger::init()
{
	google::InitGoogleLogging("");
	google::SetLogDestination(google::GLOG_INFO, "log/info.log");
	google::SetLogDestination(google::GLOG_ERROR, "log/error.log");
	google::SetLogDestination(google::GLOG_WARNING, "log/warning.log");
}

void Glogger::log(int level
				  , const string& msg)
{
	switch(level){
		case LL_ERROR:
			LOG(ERROR) << msg;
			break;
		case LL_INFO:
			LOG(INFO) << msg;
			break;
		case LL_WARNING:
			LOG(WARNING) << msg;
			break;
		default:
			break;
	}
}