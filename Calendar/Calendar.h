#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//enum of months to stop the entry of the wrong date
enum Months {
	jan = 1, feb, mar, apr, may, jun, july, aug, sep, oct, nov, dec
};

//-----------------------------------------------------------------------------

enum Days
{
	sun = 0, mon, tue, wed, thu, fri, sat
};

//-----------------------------------------------------------------------------

class Date {
	//format: DD/MM/YYYY
private:
	int day;
	Months mon;
	int year;
	Days NoD;	//NoD - Name of Day , i.e. mon, tue etc.
	std::vector<std::string> note;
	static int dateInDiary;
	int sort_code;
public:
	//getters
	int get_day() const { return day; }
	Months get_month() const { return mon; }
	int get_year() const { return year; }
	Days get_NoD() const { return NoD; }
	int get_sortcode() const { return sort_code; }

	void print_date();
	void print_NoD();
	void print_note();

	//constructor
	Date(int day = 01, Months mon = jan, int year = 2000, Days NoD = sat) : day(day), mon(mon), year(year), NoD(NoD), sort_code(0) {
		valid_day();
		sort_days();
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
	Days calculate_NoD();

	int sort_days();

	//overload operators
	bool operator<(const Date& rhs) const;
	bool operator==(const Date& rhs) const;
	bool operator>(const Date& rhs) const;

};

//-----------------------------------------------------------------------------

//will contain information about the yearly plan, contain important dates, compare them to the current date
class Calendar {
private:
	std::vector<Date*> events;
	Date *Baseline;
public:
	void add_event(Date& obj);
	void add_baseline(Date& obj);
	void print_events();
	Date next_event();
	void update();

};

//Date class helper functions
//-----------------------------------------------------------------------------
bool leap_year(int y);

int month_code(Months m);

int century_code(int year);

int year_code(int year);

//auto sortRuleLambda = [](Date const& d1, Date const& d2)->bool {};

//Calendar class helper functions
//-----------------------------------------------------------------------------

