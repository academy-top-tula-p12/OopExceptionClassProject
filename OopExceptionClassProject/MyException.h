#pragma once
#include <iostream>

class MyException
{
	int code;
	std::string message;

public:
	MyException(std::string message, int code = -1)
		: message{ message }, code{ code } {}
	
	std::string Message() const { return message; }
};


class MyRangeException : public MyException
{
public:
	MyRangeException() : MyException("Out of range") {};
};
