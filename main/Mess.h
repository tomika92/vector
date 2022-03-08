#pragma once
#include <iostream>
#include <string>

using namespace std;

enum Message
{
	MEMORY_ALLOC_ERROR,
	OPEN_FILE_ERROR,
	WRITE_FILE_ERROR,
	READ_FILE_ERROR,
	EMPTY_ARRAY_WARN,
	OUT_OF_RANGE_WARN,
	ERROR_TYPE_MAX
};

class Mess
{
public:
	static string messages[ERROR_TYPE_MAX];
	void mess(enum Message mss);
};

extern Mess my_mess;