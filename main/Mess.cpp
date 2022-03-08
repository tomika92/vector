#include "Mess.h"

Mess my_mess;

string Mess::messages[] = {
	"E memory alloc error",
	"E open file error",
	"E write file error",
	"E read file error",
	"W empty array",
	"W out of range"
};

void Mess::mess(enum Message mss)
{
	if (messages[mss][0] == 'E')
	{
		cout << "Error: " << messages[mss].substr(1) << endl;
		throw* this;
	}
	else
	{
		cout << "Warning: " << messages[mss].substr(1) << endl;
	}
}