#pragma once
#include <string>


struct Date {
	int day;
	int month;
	int year;
};


struct FIO {
	std::string f;
	std::string i;
	std::string o;
};


struct Key {
	Date date;
	FIO fio;
	int index;
};
