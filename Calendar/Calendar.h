#pragma once
#include <iostream>
#include <vector>

//enum of months to stop the entry of the wrong date
enum Months {
	jan = 1, feb, mar, apr, may, jun, july, aug, sep, oct, nov, dec
};

//-----------------------------------------------------------------------------

enum Days
{
	NIL = 0, mon, tue, wed, thu, fri, sat, sun
};

//-----------------------------------------------------------------------------

class Date {
	//format: DD/MM/YYYY
private:
	int day;
	Months mon;
	int year;
	Days NoD;	//NoD - Name of Day , i.e. mon, tue etc.
	std::string note;
	static int dateInDiary;
public:
	//getters
	int get_day() const { return day; }
	Months get_month() const { return mon; }
	int get_year() const { return year; }
	Days get_NoD() const { return NoD; }

	void print_date();

	//constructor
	Date(int day = 01, Months mon = jan, int year = 2000, Days NoD = sat) : day(day), mon(mon), year(year), NoD(NoD) {
		valid_day();
	};
	//copy constructor
	Date(const Date& source);

	//member functions
	void add_days(int n);
	void add_months(int n);
	void add_years(int n);
	void Add_note();
	bool valid_day();

	//Additonal functions for the name of the week day
	Days calculate_NoD(int n);

};

//-----------------------------------------------------------------------------

//will contain information about the yearly plan, contain important dates, compare them to the current date
class calendar {
private:
	std::vector<Date> events;
public:


};

//Date class helper functions
//-----------------------------------------------------------------------------
bool leap_year(int y);



//Calendar class helper functions
//-----------------------------------------------------------------------------

