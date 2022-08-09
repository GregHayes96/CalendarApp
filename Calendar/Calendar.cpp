#include "Calendar.h"

//Date copy constructor
Date::Date(const Date& source) 
    :Date{ source.day , source.mon , source.year }
{

}

//-------------------------------------------------------------------------------------
//Date member functions

void Date::add_days(int n) {

    //issue
    //this is not adding on the corect amount of days.
    //when adding on days starting on the 29th of jan on a leap year has an error going past the leap year point

    std::vector<int> days = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int temp = days[get_month() - 1];
    temp -= get_day();
    n -= temp;
    bool skip = false;

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
        skip = true;    //this stops an extra month being added on when it breaks out of the for loop
    }

    if (n > 0) { //start from next month
        day = n;
        if (skip == false) add_months(1);
    }
    else if (n == 0) {
        day = 1;
        if (skip == false)add_months(1);
    }
    else if (n < 0) { //add days on to current month


    }
}

void Date::add_months(int n){

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

    if (mon == feb && day == 29 && leap_year(year + n) == false) {
        mon = mar;       
        day = 1;
    }
    year += n;
}

//-------------------------------------------------------------------------------------
//Member function to find and set which day of the week it is

Days Date::get_NoD() {

    return NoD;
}

Days Date::calculate_NoD() {

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

