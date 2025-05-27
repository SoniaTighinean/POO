#ifndef SISTEM_FESTIVAL_H
#define SISTEM_FESTIVAL_H

#include "participant.h"
#include "artist.h"
#include "concert.h"
#include "bilet.h"
#include "sponsor.h"
#include <vector>


namespace Festival_Manager {

    class SistemFestival {

    private:
        std::vector<std::shared_ptr<Participant>> m_participanti;
        std::vector<std::shared_ptr<Artist>> m_artisti;
        std::vector<std::shared_ptr<Concert>> m_concerte;
        std::vector<Festival_Manager::Sponsor> m_sponsori;

    public:
       
        SistemFestival();

        void CreeazaParticipant();
        void CreeazaArtist();
        void CreeazaConcert();
        void CreeazaSponsor();
        void CumparaBilet();
        void AfiseazaParticipantiCuBilete() const;
        void AfiseazaArtisti() const;
        void AfiseazaProgramFestival() const;
        void AfiseazaSponsori() const;
        void IncarcaParticipantiDinFisier(const std::string& nume_fisier);
        void IncarcaArtistiDinFisier(const std::string& nume_fisier);
        void IncarcaConcerteDinFisier(const std::string& nume_fisier);
        void AfiseazaStatisticiFestival() const;

    };

} 

#endif


