#include "artist.h"
#include <iostream>

using namespace Festival_Manager;

Artist::Artist(const std::string& nume, const std::string& email, int varsta,
	const std::string& gen_muzical, double taxa_performanta)
	: Persoana(nume, email, varsta), m_gen_muzical(gen_muzical), m_taxa_performanta(taxa_performanta) {
}

void Artist::AfiseazaInfo() const{
	std::cout << "Artist: " << m_nume 
			  << " | Email: " << m_email
			  << " | Varsta: " <<m_varsta
			  << " | Gen Muzical: " << m_gen_muzical
			  << " | Taxa Performanta: " << m_taxa_performanta << " euro\n";
}


std::string Artist::GetGenMuzical() const {
	return m_gen_muzical;
}

double Artist::GetTaxaPerformanta() const {
	return m_taxa_performanta;
}	