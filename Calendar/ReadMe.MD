#Calendar project

#version 6
Calendar project which can be used to enter important dates to the user, change the date, compare the dates with upcoming events to check the upcomign schedule. 

Added Functions:

*simplified the operator for comparing the user defined objects. now its a simple one line return statement. achieved with introduction of a 'sort code'.
*This code is the date as one number, but revered. I.E, 01/01/2001 is now 20010101 - yyyymmdd.
*The smaller the number the closer the date to today, makes for easy comparison.
*implementation of sort alogorithm, which is used to organize dates in the calendar vector to print the next upcoming event, not just the first object entered into the vector

Upcoming work:
*implementation of the naming of the day of the week - feature mightbe removed and added later on when overall structure works better


The design goal once the functionality is there is to create other calendars from different dating systems around the world which can integrate with the current used Gregorian calendar
