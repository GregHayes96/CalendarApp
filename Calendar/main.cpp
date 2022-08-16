#include "Calendar.h"

int main() {

	try {
		Calendar Plans;
		Date Today(28,feb,2001);
		Date Future1(29, feb, 2004);
		Date Future2(12, dec, 2002);
		Date Future3(15, jan, 2005);

		//outputs true, testing of operator overload for both scenarios
		if (Today < Future1 == true) std::cout << "True!" << std::endl;
		//will output nothing - overload operator works!
		if (Future1 < Today == true) std::cout << "True!" << std::endl;

		Plans.add_event(Today);
		Plans.add_event(Future1);
		Plans.add_event(Future2);
		Plans.add_event(Future3);

		Plans.next_event();

		//testing of the adding functions of date class
		Today.add_days(56);
		Today.print_date();

		Today.add_months(14);
		Today.print_date();

		Today.add_years(4);
		Today.print_date();

		Today.Add_note();

		Plans.print_events();

	}

	catch (const char* txtException) {
		std::cerr << "Exception: " << txtException;
	}
	catch (...) {
		std::cerr << "Exception: Unknown error";
	}

	return 0;
}