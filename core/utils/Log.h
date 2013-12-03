#ifndef CORE_UTILS_LOG_H
#define CORE_UTILS_LOG_H
#include "glog/include/logging.h"

//在程序运行目录下简历个log 文件夹
void initLog()
{
	google::InitGoogleLogging("");
	google::SetLogDestination(google::GLOG_INFO, "log/info.log");
	google::SetLogDestination(google::GLOG_ERROR, "log/error.log");
	google::SetLogDestination(google::GLOG_WARNING, "log/warning.log");
}

#endif