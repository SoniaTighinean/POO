#ifndef PARTICIPANT_H
#define PARTICIPANT_H


#include <string>
#include "persoana.h"
#include "bilet.h"


namespace Festival_Manager {  
   class Participant : public Persoana {  

   private:  
	   Bilet m_bilet;

   public:  
       Participant(const std::string& nume, const std::string& email, int varsta);  

       void AfiseazaInfo() const override;  
       void SetBilet(const Bilet& bilet);
       void AfiseazaBilet() const;
       bool AreBilet() const;

   };  
}

#endif

