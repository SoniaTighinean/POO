#include "participant.h"
#include <iostream>

using namespace Festival_Manager;

Participant::Participant(const std::string& nume, const std::string& email, int varsta)
    : Persoana(nume, email, varsta), m_bilet("Empty") {
}

void Participant::AfiseazaInfo() const {
    std::cout << "Participant: " << m_nume << 
                " | Email: " << m_email <<
                " | Varsta: " << m_varsta << " ani\n";
}

void Participant::SetBilet(const Bilet& bilet) {
    if (m_bilet.GetTip() != "Empty") {
        std::cout << "Participantul are deja un bilet!\n";
        return;
    }
    m_bilet = bilet;
}

void Participant::AfiseazaBilet() const {
    if (AreBilet()) {
        std::cout << "Bilet detinut:\n";
        std::cout << m_bilet << "\n";
    }
    else {
        std::cout << "Participantul nu are niciun bilet.\n";
    }
}

bool Participant::AreBilet() const {
    return m_bilet.GetTip() != "Empty";
}
