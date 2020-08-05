#pragma once

#include <fstream>;

enum MessageType
{
	MT_InitError	= 1,
	MT_Error		= 2,
	MT_Warning		= 3,
	MT_Info			= 4,
	MT_Changed_Pos  = 5
};

class TLOG
{
public:
	TLOG(const char* filename);
	~TLOG();

	char* getMessageTypeString(MessageType type);
	void ConsoleLog(MessageType type, const char* Msg, float x=0.0f, float y=0.0f, const char* className = nullptr);
	void FileLog(MessageType type, const char* Msg, float x = 0.0f, float y = 0.0f, const char* className = nullptr);
	void ConsoleAndFileLog(MessageType type, const char* Msg, float x = 0.0f, float y = 0.0f, const char* className = nullptr);


	const char* mFileName;

	std::fstream mOfStream;;
};

