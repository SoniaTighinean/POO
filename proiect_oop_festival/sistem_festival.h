#ifndef SISTEM_FESTIVAL_H
#define SISTEM_FESTIVAL_H

#include "participant.h"
#include "artist.h"
#include "concert.h"
#include "bilet.h"
#include "sponsor.h"
#include <vector>
#include <memory>
#include <string>


namespace Festival_Manager {

    class SistemFestival {

    private:
        std::vector<std::shared_ptr<Participant>> m_participanti;
        std::vector<std::shared_ptr<Artist>> m_artisti;
        std::vector<std::shared_ptr<Concert>> m_concerte;
        std::vector<Sponsor> m_sponsori;

        static SistemFestival* s_instance;

        SistemFestival();

    public:
       
        SistemFestival(const SistemFestival&)= delete;
        SistemFestival& operator=(const SistemFestival&) = delete;

        static SistemFestival* GetInstance();
        void Start();

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


