#ifndef SPONSOR_H
#define SPONSOR_H

#include <string>
#include <iostream>

namespace Festival_Manager {

    class Sponsor {
    private:
        std::string m_nume;
        double m_suma;
        static double s_total_sponsorizari;

    public:
        Sponsor(const std::string& nume, double suma);

        std::string GetNume() const;
        double GetSuma() const;

        static double GetTotalSponsorizari();
        static void ResetSponsorizari();

        void Afiseaza() const;
    };

}

#endif 
