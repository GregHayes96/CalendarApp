#include "Calendar.h"

int main() {

	try {
		//testing of the adding functions of date class
		Date Today(29);
		Today.add_days(-999);
		Today.print_date();
		Today.add_months(14);
		Today.print_date();
		Today.add_years(4);
		Today.print_date();

	}

	catch (const char* txtException) {
		std::cerr << "Exception: " << txtException;
	}
	catch (...) {
		std::cerr << "Exception: Unknown error";
	}

	return 0;
}