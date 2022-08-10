#include "Calendar.h"

int main() {

	try {
		
		Date Today(28,feb,2001);

		//testing of the adding functions of date class
		Today.add_days(56);
		Today.print_date();

		Today.add_months(14);
		Today.print_date();

		Today.add_years(4);
		Today.print_date();

		Today.Add_note();

	}

	catch (const char* txtException) {
		std::cerr << "Exception: " << txtException;
	}
	catch (...) {
		std::cerr << "Exception: Unknown error";
	}

	return 0;
}