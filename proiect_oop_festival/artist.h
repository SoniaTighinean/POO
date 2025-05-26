#ifndef ARTIST_H
#define ARTIST_H

#include <string>
#include "persoana.h"

namespace Festival_Manager {

	class Artist : public Persoana {
	private:
		std::string m_gen_muzical;
		double m_taxa_performanta;

	public:
		Artist(const std::string& nume, const std::string& email, int varsta,
			const std::string& gen_muzical, double taxa_performanta);
		
		void AfiseazaInfo() const override;

		std::string GetGenMuzical() const;
		double GetTaxaPerformanta() const;
	};

}

#endif