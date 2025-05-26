#ifndef DATA_TIMP_H
#define DATA_TIMP_H

#include <string>
#include <iomanip>
#include <iostream>

namespace Festival_Manager {

	struct DataTimp {
		int an;
		int luna;
		int zi;
		int ora;
		int minut;

		void Afiseaza() const {
			std::cout << "Data: " << std::setw(2) << std::setfill('0') << zi << "-"
				<< std::setw(2) << std::setfill('0') << luna << "-"
				<< an << ", Ora: "
				<< std::setw(2) << std::setfill('0') << ora << ":"
				<< std::setw(2) << std::setfill('0') << minut << "\n";
		}
	};
}

#endif