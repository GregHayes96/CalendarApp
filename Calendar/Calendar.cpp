#include "Calendar.h"

//Date copy constructor
Date::Date(const Date& source) 
    :Date{ source.day , source.mon , source.year }
{

}

//-------------------------------------------------------------------------------------
//Date member functions

void Date::print_note(){
    for (int i = 0; i < note.size(); ++i) {
        std::cout << note[i] << " ";
    }
    std::cout << std::endl;
}

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
    std::cout << "Please enter event details with '|' to finsih" << std::endl;
    bool exit = false;
    while (exit == false) {
        std::cin >> confirm;
        if (confirm == "|") exit = true;
        else {
            note.push_back(confirm);
        }
    }
}

//-------------------------------------------------------------------------------------
//Print Date

void Date::print_date() {
    std::cout << get_day() << "/"
              << get_month() << "/"
              << get_year() << std::endl;
}

void Date::print_NoD() {
    std::vector<std::string> days{ "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
    int temp = NoD;
    std::cout << days[temp] << std::endl;
}

//-------------------------------------------------------------------------------------
//calculates the day of the week, mon, tue etc. uses all the function below to calculate 

Days Date::calculate_NoD() {

    int name = century_code(get_year()) + year_code(get_year()) + month_code(get_month()) + get_day();
    if (leap_year(get_year()) == true && (get_month() == feb || get_month() == jan)) name -= 1;

    while (name >= 7) {
        name -= 7;
    }

    NoD = Days(name);

    return NoD;
}

int year_code(int year) {
    //(YY + (YY / 4)) mod 7
    std::string last_two = std::to_string(year);

    int digit = std::stoi(last_two);
    int sec_dig = digit / 10 % 10;
    digit = digit % 10;
    digit += sec_dig * 10;
   
    digit = digit + (digit / 4);
    while (digit >= 7) {
        digit -= 7;
    }
    return digit;
}

int century_code(int year){
    std::vector<int> century_c{ 4,2,0,6,4,2,0 };
    int temp = 0;

    if (year >= 1700 && year < 1800) { temp = 0; }
    else if(year >= 1800 && year < 1900) { temp = 1; }
    else if (year >= 1900 && year < 2000) { temp = 2; }
    else if (year >= 2000 && year < 2100) { temp = 3; }
    else if (year >= 2100 && year < 2200) { temp = 4; }
    else if (year >= 2200 && year < 2300) { temp = 5; }
    else { throw "Year not in range"; }

    temp = century_c[temp];
    return temp;
}

int month_code(Months m) {
    std::vector<int> month_c{ 0,3,3,6,1,4,6,2,5,0,3,5 };
    int temp = static_cast<int>(m);
    temp = month_c[temp-1];
    return temp;
}

//--------------------------------------------------------------------------------

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

//this is the time which is today, this will keep track of upcoming events against the date today.
void Calendar::add_baseline(Date& obj) {
    Date* event;
    event = &obj;
    Baseline = event;
}

void Calendar::print_events() {
    
    //bubble sort method    -   changed algorithm to trial so DSA methods
    for (int step = 1; step < events.size(); step++) {

        for (int i = 0; i < events.size() - step; ++i) {

            if (events[i]->get_sortcode() > events[i + 1]->get_sortcode()) {

                Date* temp = events[i];
                events[i] = events[i + 1];
                events[i + 1] = temp;
            }
        }
    }
    std::cout << "Events in diary: " << std::endl;
    for (int i = 0; i < events.size(); ++i) {
        std::cout << i + 1 << ". ";
        events[i]->print_date();
        std::cout << "  : ";
        events[i]->print_NoD();
        std::cout << "  -  ";
        events[i]->print_note();
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

void Calendar::update() {
    int count = 0;
    for (int i = 0; i < events.size(); ++i) {
        if (events[i]->get_sortcode() < Baseline->get_sortcode()) {
            events.erase(events.begin() + i);
            count++;
        }
    }
   
    if (count > 0) std::cout << "Past dates in calendar. Total events removed: " << count << std::endl;
}

//------------------------------------------------------------------------------------
//overload operators

//compares dates to see if th RHS is a larger date i.e 22/03/2004 > 21/02/2001
bool Date::operator<(const Date& rhs) const {
    //compare the year which is in reverse format - yyyymmdd - the smaller the number the closer the date
    return  (this->sort_code < rhs.sort_code);

}

bool Date::operator==(const Date& rhs) const {

    return (this->sort_code == rhs.sort_code);
}

bool Date::operator>(const Date& rhs) const {

    return (this->sort_code > rhs.sort_code);
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
