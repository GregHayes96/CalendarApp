#include "Calendar.h"

//Date copy constructor
Date::Date(const Date& source) 
    :Date{ source.day , source.mon , source.year }
{

}

//-------------------------------------------------------------------------------------
//Date member functions

void Date::add_days(int n) {
    if (n < 0) throw "Can only add a positive amount of days";

    std::vector<int> days = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int temp = days[get_month() - 1];
    
    if (temp >= n + get_day()) { 
        day += n; 
        return;
    };

    for (int i = 0; n >= days[get_month() - 1]; ++i) { // n larger than days in the month
        //if its a leap year it changes the days used to 29 instead of 28 for feb
        if (leap_year(get_year()) == true && get_month() == 2) {
            n -= 29;
            add_months(1);
        }
        else {
            n -= days[get_month() - 1];
            add_months(1);
        }
    }

    if (n > 0) { //start from next month
        day = 1;
        day += n;
    }
    else if (n == 0) {
        day = 1;
    }
    else if (n < 0) { //add days on to current month
        day += n;
    }
}

void Date::add_months(int n){
    if (n < 0) throw "Can only add a positive amount of months";
    int temp = mon + n;
    if (leap_year(get_year()) == false && get_month() == 1 && get_day() == 29) {
        mon = mar;
        day = 1;
    }
    //this takes the month and casts it into the enum
    else if (temp > 12) {
        temp -= 12;
        mon = (Months)temp;
        year++;
    }
    else if (temp <= 12) {
        mon = (Months)temp;
    }
}

void Date::add_years(int n){
    if (n < 0) throw "Can only add a positive amount of months";

    if (mon == feb && day == 29 && leap_year(year + n) == false) {
        mon = mar;       
        day = 1;
    }
    year += n;
}

//-------------------------------------------------------------------------------------
//Print Date

void Date::print_date() {
    std::cout << get_day() << "/"
              << get_month() << "/"
              << get_year() << std::endl;
}




//-------------------------------------------------------------------------------------
//function to find and set which day of the week it is

Days Date::get_NoD() {

    return NoD;
}

//calculates how many days have been added, in reference to the starting date. 
Days Date::calculate_NoD(int n) {

    while (n >= 7) {
        n -= 7;
    }

    int temp = static_cast<int>(NoD);
    temp += n;
    if (temp > 7) { temp -= 7; }

    NoD = static_cast<Days>(temp);

    return NoD;
}

//-------------------------------------------------------------------------------------
//helper functions

bool leap_year(int y)
{
    if (y % 4 != 0)
        return false;
    else if (y % 100 != 0)
        return true;
    else if (y % 400 == 0)
        return true;
    else
        return false;
}

