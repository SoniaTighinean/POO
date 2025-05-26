#ifndef BILET_H
#define BILET_H

#include <string>
#include <memory>
#include "concert.h"


namespace Festival_Manager {
    class Bilet {
    public:
        Bilet(const std::string& tip, double pret, std::shared_ptr<Concert> concert);

        void Afiseaza() const;

        std::string GetTip() const;
        double GetPret() const;
        std::shared_ptr<Concert> GetConcert() const;

    private:
        std::string m_tip;
        double m_pret;
        std::shared_ptr<Concert> m_concert;
    };

} 

#endif 
