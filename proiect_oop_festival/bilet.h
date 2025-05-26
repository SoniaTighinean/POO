#ifndef BILET_H
#define BILET_H

#include <string>

namespace Festival_Manager {

    class Bilet {
    private:
        std::string m_tip;
        double m_pret;
        static double s_total_incasari;
        static int s_total_bilete;

    public:
        Bilet(const std::string& tip);

        void Afiseaza() const;

        std::string GetTip() const;
        double GetPret() const;

        static int GetTotalBilete();
        static double GetTotalIncasari();
        static void ResetStatistici();
        static void AdaugaStatistici(double suma);

    };

}

#endif
