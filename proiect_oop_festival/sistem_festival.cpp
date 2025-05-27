#include "sistem_festival.h"
#include "concert.h"
#include "sponsor.h"

#include <fstream>    
#include <sstream>   
#include <iostream>    
#include <string>   
#include <algorithm>


using namespace Festival_Manager;

SistemFestival::SistemFestival() {
    IncarcaParticipantiDinFisier("participanti.txt");
    IncarcaArtistiDinFisier("artisti.txt");
    IncarcaConcerteDinFisier("concerte.txt");
    Bilet::ResetStatistici();
    Sponsor::ResetSponsorizari();

    Festival_Manager::Sponsor s1("Vodafone", 1000.0);     
    Festival_Manager::Sponsor s2("Kaufland", 1500.0);     
    Festival_Manager::Sponsor s3("Coca-Cola", 800.0);     
   
    m_sponsori.push_back(s1);
    m_sponsori.push_back(s2);
    m_sponsori.push_back(s3);

}

void SistemFestival::CreeazaParticipant() {
    std::string nume, email;
    int varsta;

    std::cout << "Nume participant: ";
    std::getline(std::cin >> std::ws, nume);
    std::cout << "Email: ";
    std::getline(std::cin >> std::ws, email);
    std::cout << "Varsta: ";
    std::cin >> varsta;

    auto participant = std::make_shared<Participant>(nume, email, varsta);
    m_participanti.push_back(participant);

    std::cout << "Participant creat cu succes!\n";
}

void SistemFestival::CreeazaArtist() {
    std::string nume, email, gen;
    int varsta;
    double taxa;

    std::cout << "Nume artist: ";
    std::getline(std::cin >> std::ws, nume);
    std::cout << "Email: ";
    std::getline(std::cin >> std::ws, email);
    std::cout << "Varsta: ";
    std::cin >> varsta;
    std::cout << "Gen muzical: ";
    std::getline(std::cin >> std::ws, gen);
    std::cout << "Taxa performanta: ";
    std::cin >> taxa;

    auto artist = std::make_shared<Artist>(nume, email, varsta, gen, taxa);
    m_artisti.push_back(artist);

    std::cout << "Artist creat cu succes!\n";
}

void SistemFestival::AfiseazaArtisti() const {
    if (m_artisti.empty()) {
        std::cout << "Nu exista artisti inregistrati.\n";
        return;
    }

    for (const auto& artist : m_artisti) {
        artist->AfiseazaInfo();
    }
}

void SistemFestival::AfiseazaParticipantiCuBilete() const {
    if (m_participanti.empty()) {
        std::cout << "Nu exista participanti inregistrati.\n";
        return;
    }

    std::cout << "\n====== LISTA PARTICIPANTI ======\n";

    for (const auto& participant : m_participanti) {
        participant->AfiseazaInfo();
        participant->AfiseazaBilet();
        std::cout << "------------------------------\n";
    }
}


void SistemFestival::CreeazaConcert() {
    if (m_artisti.empty()) {
        std::cout << "Nu exista artisti. Creeaza mai intai un artist.\n";
        return;
    }

    std::cout << "Selecteaza un artist pentru concert:\n";
    for (size_t i = 0; i < m_artisti.size(); ++i) {
        std::cout << i + 1 << ". " << m_artisti[i]->GetNume() << "\n";
    }

    size_t optiune;
    std::cin >> optiune;
    if (optiune < 1 || optiune > m_artisti.size()) {
        std::cout << "Optiune invalida.\n";
        return;
    }

    Festival_Manager::DataTimp dt;
    std::string data_input, ora_input;


    std::cout << "Data concertului (format dd-mm-yyyy): ";
    std::getline(std::cin >> std::ws, data_input);
    std::stringstream ss_data(data_input);
    std::string zi_str, luna_str, an_str;
    getline(ss_data, zi_str, '-');
    getline(ss_data, luna_str, '-');
    getline(ss_data, an_str, '-');
    dt.zi = std::stoi(zi_str);
    dt.luna = std::stoi(luna_str);
    dt.an = std::stoi(an_str);

    std::cout << "Ora concertului (format hh:mm): ";
    std::getline(std::cin >> std::ws, ora_input);
    std::stringstream ss_ora(ora_input);
    std::string ora_str, minut_str;
    getline(ss_ora, ora_str, ':');
    getline(ss_ora, minut_str, ':');
    dt.ora = std::stoi(ora_str);
    dt.minut = std::stoi(minut_str);

    int durata;
    std::cout << "Durata concertului (minute): ";
    std::cin >> durata;

    auto concert = std::make_shared<Concert>(m_artisti[optiune - 1], dt, durata);
    m_concerte.push_back(concert);

    std::cout << "Concert creat cu succes!\n";
}


void Festival_Manager::SistemFestival::CreeazaSponsor() {
    std::string nume;
    double suma;

    std::cout << "Nume sponsor: ";
    std::getline(std::cin >> std::ws, nume);
    std::cout << "Suma oferita: ";
    std::cin >> suma;

    Festival_Manager::Sponsor s(nume, suma);
    m_sponsori.push_back(s);

    std::cout << "Sponsor adaugat cu succes!\n";
}


void SistemFestival::CumparaBilet() {
    if (m_participanti.empty()) {
        std::cout << "Nu exista participanti inregistrati.\n";
        return;
    }

    std::cout << "Selecteaza participantul:\n";
    for (size_t i = 0; i < m_participanti.size(); ++i) {
        std::cout << i + 1 << ". " << m_participanti[i]->GetNume() << "\n";
    }

    size_t p_idx;
    std::cin >> p_idx;
    if (p_idx < 1 || p_idx > m_participanti.size()) {
        std::cout << "Optiune invalida.\n";
        return;
    }

    std::shared_ptr<Participant> participant = m_participanti[p_idx - 1];

    if (participant->AreBilet()) {
        std::cout << "Participantul are deja un bilet.\n";
        return;
    }

    std::string tip;
    std::cout << "Tip bilet (VIP / General / Student): ";
    std::getline(std::cin >> std::ws, tip);

    Bilet bilet(tip);
    participant->SetBilet(bilet);
    Bilet::AdaugaStatistici(bilet.GetPret());
    std::cout << "Bilet cumparat cu succes!\n";
}


void SistemFestival::AfiseazaProgramFestival() const {
    std::vector<std::shared_ptr<Concert>> program = m_concerte;

    std::sort(program.begin(), program.end(),
        [](const std::shared_ptr<Concert>& a, const std::shared_ptr<Concert>& b) {
            const DataTimp& d1 = a->GetDataTimp();
            const DataTimp& d2 = b->GetDataTimp();

            if (d1.an != d2.an) return d1.an < d2.an;
            if (d1.luna != d2.luna) return d1.luna < d2.luna;
            if (d1.zi != d2.zi) return d1.zi < d2.zi;
            if (d1.ora != d2.ora) return d1.ora < d2.ora;
            return d1.minut < d2.minut;
        });

    for (const auto& concert : program) {
        concert->AfiseazaConcert();
    }


}

void Festival_Manager::SistemFestival::AfiseazaSponsori() const {
    if (m_sponsori.empty()) {
        std::cout << "Nu exista sponsori inregistrati.\n";
        return;
    }

    std::cout << "\n====== LISTA SPONSORI ======\n";
    for (const auto& s : m_sponsori) {
        s.Afiseaza();
    }
}


void SistemFestival::IncarcaParticipantiDinFisier(const std::string& nume_fisier) {
    std::ifstream fin(nume_fisier);
    if (!fin.is_open()) {
        std::cout << "Eroare la deschiderea fisierului: " << nume_fisier << "\n";
        return;
    }

    std::string linie;
    while (std::getline(fin, linie)) {
        std::stringstream ss(linie);
        std::string nume, email, varsta_str;

        std::getline(ss, nume, ';');
        std::getline(ss, email, ';');
        std::getline(ss, varsta_str, ';');

        int varsta = std::stoi(varsta_str);
        auto p = std::make_shared<Participant>(nume, email, varsta);
        m_participanti.push_back(p);
    }

    std::cout << "Participanti incarcati din fisier.\n";
}
void Festival_Manager::SistemFestival::IncarcaArtistiDinFisier(const std::string& nume_fisier) {
    std::ifstream fin(nume_fisier);
    if (!fin.is_open()) {
        std::cout << "Eroare la deschiderea fisierului: " << nume_fisier << "\n";
        return;
    }

    std::string linie;
    while (std::getline(fin, linie)) {
        std::stringstream ss(linie);
        std::string nume, email, varsta_str, gen_muzical, taxa_str;

        std::getline(ss, nume, ';');
        std::getline(ss, email, ';');
        std::getline(ss, varsta_str, ';');
        std::getline(ss, gen_muzical, ';');
        std::getline(ss, taxa_str, ';');

        int varsta = std::stoi(varsta_str);
        double taxa = std::stod(taxa_str);

        auto a = std::make_shared<Artist>(nume, email, varsta, gen_muzical, taxa);
        m_artisti.push_back(a);
    }

    std::cout << "Artisti incarcati din fisier.\n";
}

void SistemFestival::IncarcaConcerteDinFisier(const std::string& nume_fisier) {
    std::ifstream fin(nume_fisier);
    if (!fin.is_open()) {
        std::cout << "Eroare la deschiderea fisierului: " << nume_fisier << "\n";
        return;
    }

    std::string linie;
    while (std::getline(fin, linie)) {
        std::stringstream ss(linie);
        std::string nume_artist, data_str, ora_str, durata_str;

        std::getline(ss, nume_artist, ';');
        std::getline(ss, data_str, ';');
        std::getline(ss, ora_str, ';');
        std::getline(ss, durata_str, ';');

        std::shared_ptr<Artist> artist_gasit = nullptr;
        for (const auto& artist : m_artisti) {
            if (artist->GetNume() == nume_artist) {
                artist_gasit = artist;
                break;
            }
        }

        if (!artist_gasit) {
            std::cout << "Artistul " << nume_artist << " nu a fost gasit.\n";
            continue;
        }

        // Parsează data
        std::stringstream ss_data(data_str);
        std::string zi_str, luna_str, an_str;
        std::getline(ss_data, zi_str, '-');
        std::getline(ss_data, luna_str, '-');
        std::getline(ss_data, an_str, '-');

        // Parsează ora
        std::stringstream ss_ora(ora_str);
        std::string ora_part, minut_part;
        std::getline(ss_ora, ora_part, ':');
        std::getline(ss_ora, minut_part, ':');

        DataTimp dt;
        dt.zi = std::stoi(zi_str);
        dt.luna = std::stoi(luna_str);
        dt.an = std::stoi(an_str);
        dt.ora = std::stoi(ora_part);
        dt.minut = std::stoi(minut_part);

        int durata = std::stoi(durata_str);

        auto concert = std::make_shared<Concert>(artist_gasit, dt, durata);
        m_concerte.push_back(concert);
    }

    std::cout << "Concerte incarcate din fisier.\n";
}



#include <unordered_set>

void SistemFestival::AfiseazaStatisticiFestival() const {
    int nr_participanti = static_cast<int>(m_participanti.size());
    int nr_bilete = Bilet::GetTotalBilete();
    double incasari_bilete = Bilet::GetTotalIncasari();
    double sponsorizari = Sponsor::GetTotalSponsorizari();


    double cheltuieli = 0.0;
    for (const auto& artist : m_artisti) {
        cheltuieli += artist->GetTaxaPerformanta();
    }

    double incasari = incasari_bilete + sponsorizari;
    double profit = incasari - cheltuieli;

    std::cout << "\n====== STATISTICI FESTIVAL ======\n";
    std::cout << "Numar participanti: " << nr_participanti << "\n";
    std::cout << "Numar bilete vandute: " << nr_bilete << "\n";
    std::cout << "Incasari bilete: " << incasari_bilete << " euro\n";
    std::cout << "Sponsorizari: " << sponsorizari << " euro\n";
    std::cout << "Cheltuieli artisti: " << cheltuieli << " euro\n";
    std::cout << "Profit festival: " << profit << " euro\n";
    std::cout << "=================================\n";
}

