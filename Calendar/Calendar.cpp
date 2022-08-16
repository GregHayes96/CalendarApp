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
    sort_days();
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
    sort_days();
}

void Date::add_years(int n){
    if (n < 0) throw "Can only add a positive amount of years";

    if (mon == feb && day == 29 && leap_year(year + n) == false) {
        mon = mar;       
        day = 1;
    }
    year += n;
    sort_days();
}

void Date::Add_note() {
    std::string confirm = "n";
    while (confirm == "n" || confirm == "no" || confirm == "No" || confirm == "N"){
        std::cout << "Please enter event (one word)" << std::endl;
        std::cin >> note;
        std::cout << std::endl;
        std::cout << "Event details: " << note << std::endl << "Confirm? (Y/N)" << std::endl;
        std::cin >> confirm;
    }
}

//-------------------------------------------------------------------------------------
//Print Date

void Date::print_date() {
    std::cout << get_day() << "/"
              << get_month() << "/"
              << get_year() << std::endl;
}

//-------------------------------------------------------------------------------------
//calculates how many days have been added, in reference to the starting date. 

//this function works, but if someone enters a date with the constructor it gets thrown off.
//Need to find a way of offsetting this date to the date entered in the constructor
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

//checks if the date entered by someone is an actual day on the calendar
bool Date::valid_day() {
    if (day > 31 || day < 1) throw "day entered not in range";
    if (year < 1900) throw "Year out of calendar range";

    switch (mon) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (day > 31) throw "Too many days";
            break;
        case 2:
            if (day > 28 && leap_year(get_year()) == false) throw "Too many days";
            else if (day > 29 && leap_year(get_year()) == true) throw "Too many days";
            break;
        case 4: case 6: case 9: case 11:
            if (day > 30) throw "Too many days";
            break;
        default:
            throw "Error in calculating days";
    }

    return true;
}

//-------------------------------------------------------------------------------------
//Calendar Member functions

void Calendar::add_event(Date& obj) {
    Date* event;
    event = &obj;
    events.push_back(event);

}

void Calendar::print_events() {
  
    std::sort(events.begin(), events.end());

    std::cout << "Events in diary: " << std::endl;
    for (int i = 0; i < events.size(); ++i) {
        std::cout << i + 1 << ". " << events[i]->get_note() << "  -  ";
        events[i]->print_date();
        std::cout << std::endl;

    }
}

Date Calendar::next_event() {

    int next_event = 0;
    for (int i = 0; i < events.size(); ++i) {

        if (events[next_event] < events[i] == true) {
            
        }
        else {
            next_event = i;
        }
    }

    events[next_event]->print_date();

    return *events[next_event];
}

//------------------------------------------------------------------------------------
//overload operators

//compares dates to see if th RHS is a larger date i.e 22/03/2004 > 21/02/2001
bool Date::operator<(const Date& rhs) const {
    //compare the year which is in reverse format - yyyymmdd - the smaller the number the closer the date
    return  (this->sort_code <= rhs.sort_code);

}

//this will create a fresh date code for comparison every time it is called. is called in every instance of a day/month/year addition
int Date::sort_days() {

    sort_code = 0;
    sort_code += (get_year() * 10000);
    sort_code += (get_month() * 100);
    sort_code += get_day();

    return sort_code;
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

//-----------------------------------------------------------------------------------
//lambda

//auto sortrulelambda = [](date const& d1, date const& d2) -> bool
//{
//    return (d1.get_sortcode() < d2.get_sortcode());
//
//};