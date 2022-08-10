#Calendar project

#version 4
Calendar project which can be used to enter important dates to the user, change the date, compare the dates with upcoming events to check the upcomign schedule. 

Added Functions:

*valid date check, this is a form of error handling which is called upon creation of a user defined object. Makes sure it is not breaking calendar rules, I.E, 29 of feb on none leap year
*Add note feature, now when a date is added, you can given a note to give details on the calendar event
*Introduction of a global variable for Date to baseline all dates off. To be used as a reference


Upcoming work:
*implementation of the naming of the day of the week - feature mightbe removed and added later on when overall structure works better


The design goal once the functionality is there is to create other calendars from different dating systems around the world which can integrate with the current used Gregorian calendar
