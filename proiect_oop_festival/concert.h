#ifndef CONCERT_H
#define CONCERT_H

#include <string>
#include <memory>
#include "artist.h"
#include "data_timp.h" 

namespace Festival_Manager {

    class Concert {
    private:
        std::shared_ptr<Artist> m_artist;
        DataTimp m_data_timp;
        int m_durata;

    public:
        
        Concert(std::shared_ptr<Artist> artist, const DataTimp& data_timp, int durata);

        void AfiseazaConcert() const;

        std::shared_ptr<Artist> GetArtist() const;
        DataTimp GetDataTimp() const;
        int GetDurata() const;

    
    };

} 


#endif