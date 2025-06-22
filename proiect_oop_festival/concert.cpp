#include "concert.h"
#include <iostream>

using namespace Festival_Manager;

Festival_Manager::Concert::Concert(std::shared_ptr<Artist> artist, const DataTimp& data_timp, int durata)
    : m_artist(artist), m_data_timp(data_timp), m_durata(durata) {
}

void Concert::AfiseazaConcert() const {
    std::cout << "Concert sustinut de: " << m_artist->GetNume() 
              << " | Gen muzical: " << m_artist->GetGenMuzical() << "\n";
    m_data_timp.Afiseaza();
    std::cout << " | Durata: " << m_durata << " minute\n";
    std::cout << "--------------------------\n";
}

std::shared_ptr<Artist> Concert::GetArtist() const {
    return m_artist;
}

// Returnează structura DataTimp asociată concertului
DataTimp Concert::GetDataTimp() const {
    return m_data_timp;
}

int Concert::GetDurata() const {
    return m_durata;
}


