#include "sponsor.h"

namespace Festival_Manager {

    double Sponsor::s_total_sponsorizari = 0.0;

    Sponsor::Sponsor(const std::string& nume, double suma)
        : m_nume(nume), m_suma(suma)
    {
        s_total_sponsorizari += suma;
    }

    std::string Sponsor::GetNume() const {
        return m_nume;
    }

    double Sponsor::GetSuma() const {
        return m_suma;
    }

    double Sponsor::GetTotalSponsorizari() {
        return s_total_sponsorizari;
    }

    void Sponsor::ResetSponsorizari() {
        s_total_sponsorizari = 0.0;
    }

    void Sponsor::Afiseaza() const {
        std::cout << "Sponsor: " << m_nume
            << " | Suma oferita: " << m_suma << " euro\n";
    }

}
