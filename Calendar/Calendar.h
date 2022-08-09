#pragma once
#include <iostream>
#include <vector>

//enum of months to stop the entry of the wrong date
enum Months {
	jan = 1, feb, mar, apr, may, jun, july, aug, sep, oct, nov, dec
};

//-----------------------------------------------------------------------------

enum class Days
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

	//this will track the amount of user defined dates in the diary, to compare the calendar with the amount of upcoming events.
	//intention is to remove one when the current date passes the event date - implementation to come
	static int dateInDiary;
public:
	//getters
	int get_day() const { return day; }
	Months get_month() const { return mon; }
	int get_year() const { return year; }

	//setters

	//constructor
	Date(int day = 01, Months mon = jan, int year = 2000, Days NoD = Days::sat) : day(day), mon(mon), year(year), NoD(NoD) { };
		
	//7++dateInDiary	-	potential implementation of the calendar objects

	//copy constructor
	Date(const Date& source);
	

	//member functions
	void add_days(int n);
	void add_months(int n);
	void add_years(int n);

	//
	Days get_NoD();
	Days calculate_NoD();

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