#ifndef SISTEM_FESTIVAL_H
#define SISTEM_FESTIVAL_H

#include "participant.h"
#include "artist.h"
#include "concert.h"
#include "bilet.h"
#include <vector>


namespace Festival_Manager {

    class SistemFestival {

    private:
        std::vector<std::shared_ptr<Participant>> m_participanti;
        std::vector<std::shared_ptr<Artist>> m_artisti;
        std::vector<std::shared_ptr<Concert>> m_concerte;

    public:
       
        SistemFestival();

        void CreeazaParticipant();
        void CreeazaArtist();
        void CreeazaConcert();
        void CumparaBilet();
        void AfiseazaParticipantiCuBilete() const;
        void AfiseazaArtisti() const;
        void AfiseazaProgramFestival() const;
        void IncarcaParticipantiDinFisier(const std::string& nume_fisier);
        void IncarcaArtistiDinFisier(const std::string& nume_fisier);
        void IncarcaConcerteDinFisier(const std::string& nume_fisier);
        void AfiseazaStatisticiFestival() const;

    };

} 

#endif


