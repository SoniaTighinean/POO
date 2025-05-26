#include "persoana.h"

using namespace Festival_Manager;

Persoana::Persoana(const std::string& nume, const std::string& email, int varsta)
    : m_nume(nume), m_email(email), m_varsta(varsta) {
}



std::string Persoana::GetNume() const {
    return m_nume;
}

std::string Persoana::GetEmail() const {
    return m_email;
}

int Persoana::GetVarsta() const {
    return m_varsta;
}

