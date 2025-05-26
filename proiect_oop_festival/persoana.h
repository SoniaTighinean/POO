#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>  

namespace Festival_Manager {  

   class Persoana {  
   protected:  
       std::string m_nume;  
       std::string m_email;  
       int m_varsta;  

   public:  
       Persoana(const std::string& nume, const std::string& email, int varsta);  

       virtual ~Persoana() = default;  
       virtual void AfiseazaInfo() const = 0;  

       std::string GetNume() const;  
       std::string GetEmail() const;  
       int GetVarsta() const;  

   };  

}

#endif