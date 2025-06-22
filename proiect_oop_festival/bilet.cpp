#include "bilet.h"
#include <iostream>


using namespace Festival_Manager;

int Bilet::s_total_bilete = 0;
double Bilet::s_total_incasari = 0;

// Constructorul setează prețul în funcție de tipul biletului
Bilet::Bilet(const std::string& tip)
    : m_tip(tip)
{
    if (tip == "VIP") {
        m_pret = 500.0;
    }
    else if (tip == "General") {
        m_pret = 250.0;
    }
    else if (tip == "Student") {
        m_pret = 100.0;
    }
    else {
        m_pret = 0.0; 
    }
}


void Bilet::Afiseaza() const {
    std::cout << "Bilet tip: " << m_tip
        << " | Pret: " << m_pret << " euro\n";
}

std::string Bilet::GetTip() const {
    return m_tip;
}

double Bilet::GetPret() const {
    return m_pret;
}

int Bilet::GetTotalBilete() {
    return s_total_bilete;
}

double Bilet::GetTotalIncasari() {
    return s_total_incasari;
}

void Bilet::ResetStatistici() {
    s_total_bilete = 0;
    s_total_incasari = 0.0;
}

void Bilet::AdaugaStatistici(double suma) {
    s_total_bilete++;
    s_total_incasari += suma;
}

namespace Festival_Manager {
    // Supraincarcare operator << pentru afișarea biletului
    std::ostream& operator<<(std::ostream& os, const Bilet& bilet) {
        os << "Tip bilet: " << bilet.m_tip
            << " | Pret: " << bilet.m_pret << " euro";
        return os;
    }

}

