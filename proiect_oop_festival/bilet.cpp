#include "bilet.h"
#include <iostream>

using namespace Festival_Manager;
Bilet::Bilet(const std::string& tip, double pret, std::shared_ptr<Concert> concert)
    : m_tip(tip), m_pret(pret), m_concert(concert) {
}


void Bilet::Afiseaza() const {
    std::cout << "Bilet [Tip: " << m_tip << ", Pret: " << m_pret << " lei]\n";
    if (m_concert != nullptr) {
        std::cout << "Concert asociat:\n";
        m_concert->AfiseazaConcert();
    }
    else {
        std::cout << "Concert inexistent!\n";
    }
}

std::string Bilet::GetTip() const {
    return m_tip;
}


double Bilet::GetPret() const {
    return m_pret;
}


std::shared_ptr<Concert> Bilet::GetConcert() const {
    return m_concert;
}
