#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <vector>
#include <string>
#include <memory>
#include "persoana.h"
#include "bilet.h"
namespace Festival_Manager {  
   class Participant : public Persoana {  
   private:  
       std::vector<Bilet> m_bilete;  

   public:  
       Participant(const std::string& nume, const std::string& email, int varsta);  

       void AfiseazaInfo() const override;  
       void AdaugaBilet(const Bilet& bilet);  
       void AfiseazaBilete() const;  
   };  
}

#endif

