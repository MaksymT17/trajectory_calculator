#include "TLOG.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>


TLOG::TLOG(const char* fileName):
mFileName(fileName)
{

}

TLOG::~TLOG()
{
}

const std::string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	struct tm timeinfo;
	localtime_s(&timeinfo, &now);
	sprintf_s(buf, "[%d:%d:%d] ", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
	return std::string(buf);
}

const std::string getPositionStr(float x, float y) {
	char       buf[50];
	sprintf_s(buf, "Position x=%f y=%f", x,y);
	return std::string(buf);
}

char* TLOG::getMessageTypeString(MessageType type)
{
	if (type == MT_InitError)
		return "INIT_ERROR:";
	else if (type == MT_Error)
		return "ERROR:";
	else if (type == MT_Warning)
		return "WARNING:";
	else
		return "INFO";
}

void TLOG::ConsoleLog(MessageType type, const char* Msg, float x, float y, const char* className )
{
	if (className == nullptr)
		printf("%s %s %s", currentDateTime().c_str(), getMessageTypeString(type), Msg);
	else
		printf("%s %s class %s: %s", currentDateTime().c_str(), getMessageTypeString(type), Msg);

	if (type == MT_Changed_Pos)
		printf("%s", getPositionStr(x,y).c_str());

	printf("\n");
}

void TLOG::FileLog(MessageType type, const char* Msg, float x, float y, const char* className)
{
	mOfStream.open(mFileName, std::ofstream::app);
	if (className == nullptr)
		mOfStream << currentDateTime() << getMessageTypeString(type) << " " << Msg;
	else
		mOfStream << currentDateTime() << getMessageTypeString(type) << " class " << className << ": " << Msg;

	if (type == MT_Changed_Pos)
		mOfStream << getPositionStr(x, y);

	mOfStream << "\n";

	mOfStream.close();
}

void TLOG::ConsoleAndFileLog(MessageType type, const char* Msg, float x, float y, const char* className)
{
	ConsoleLog(type, Msg, x,y,className);
	FileLog(type, Msg, x,y,className);
}
