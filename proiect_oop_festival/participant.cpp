#include "participant.h"  
#include "concert.h"
#include <iostream>  

using namespace Festival_Manager;

Participant::Participant(const std::string& nume, const std::string& email, int varsta)
    : Persoana(nume, email, varsta) {
}

void Participant::AfiseazaInfo() const {
    std::cout << "Participant: " << m_nume
        << " | Email: " << m_email
        << " | Varsta: " << m_varsta << "\n";
}

void Participant::AdaugaBilet(const Bilet& bilet) {
    m_bilete.push_back(bilet);
}

void Participant::AfiseazaBilete() const {
    if (m_bilete.empty()) {
        std::cout << "Nu exista bilete pentru acest participant.\n";
        return;
    }

    for (const auto& bilet : m_bilete) {
        bilet.Afiseaza();
    }
}

