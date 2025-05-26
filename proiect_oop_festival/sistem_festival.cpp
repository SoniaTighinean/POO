#include "sistem_festival.h"
#include "concert.h"
#include <fstream>    
#include <sstream>   
#include <iostream>    
#include <string>     


using namespace Festival_Manager;
using namespace std;



void SistemFestival::CreeazaParticipant() {
    string nume, email;
    int varsta;

    cout << "Nume participant: ";
    getline(cin >> ws, nume);
    cout << "Email: ";
    getline(cin >> ws, email);
    cout << "Varsta: ";
    cin >> varsta;

    auto participant = make_shared<Participant>(nume, email, varsta);
    m_participanti.push_back(participant);

    cout << "Participant creat cu succes!\n";
}

void SistemFestival::CreeazaArtist() {
    string nume, email, gen;
    int varsta;
    double taxa;

    cout << "Nume artist: ";
    getline(cin >> ws, nume);
    cout << "Email: ";
    getline(cin >> ws, email);
    cout << "Varsta: ";
    cin >> varsta;
    cout << "Gen muzical: ";
    getline(cin >> ws, gen);
    cout << "Taxa performanta: ";
    cin >> taxa;

    auto artist = make_shared<Artist>(nume, email, varsta, gen, taxa);
    m_artisti.push_back(artist);

    cout << "Artist creat cu succes!\n";
}

void SistemFestival::AfiseazaArtisti() const {
    if (m_artisti.empty()) {
        cout << "Nu exista artisti inregistrati.\n";
        return;
    }

    for (const auto& artist : m_artisti) {
        artist->AfiseazaInfo();
    }
}

void SistemFestival::AfiseazaParticipantiCuBilete() const {
    if (m_participanti.empty()) {
        cout << "Nu exista participanti inregistrati.\n";
        return;
    }

    for (const auto& participant : m_participanti) {
        participant->AfiseazaInfo();
        participant->AfiseazaBilete();
    }
}

void SistemFestival::CreeazaConcert() {
    if (m_artisti.empty()) {
        cout << "Nu exista artisti. Creeaza mai intai un artist.\n";
        return;
    }

    cout << "Selecteaza un artist pentru concert:\n";
    for (size_t i = 0; i < m_artisti.size(); ++i) {
        cout << i + 1 << ". " << m_artisti[i]->GetNume() << "\n";
    }

    size_t optiune;
    cin >> optiune;
    if (optiune < 1 || optiune > m_artisti.size()) {
        cout << "Optiune invalida.\n";
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

void SistemFestival::CumparaBilet() {
    if (m_participanti.empty() || m_concerte.empty()) {
        cout << "Trebuie sa existe cel putin un participant si un concert.\n";
        return;
    }

    cout << "Selecteaza participantul:\n";
    for (size_t i = 0; i < m_participanti.size(); ++i) {
        cout << i + 1 << ". " << m_participanti[i]->GetNume() << "\n";
    }

    size_t p_idx;
    cin >> p_idx;
    if (p_idx < 1 || p_idx > m_participanti.size()) {
        cout << "Optiune invalida.\n";
        return;
    }

    cout << "Selecteaza concertul:\n";
    for (size_t i = 0; i < m_concerte.size(); ++i) {
        cout << i + 1 << ". ";
        m_concerte[i]->AfiseazaConcert();
    }

    size_t c_idx;
    cin >> c_idx;
    if (c_idx < 1 || c_idx > m_concerte.size()) {
        cout << "Optiune invalida.\n";
        return;
    }

    string tip;
    double pret;

    cout << "Tip bilet (ex: VIP, General): ";
    getline(cin >> ws, tip);
    cout << "Pret: ";
    cin >> pret;

    Bilet bilet(tip, pret, m_concerte[c_idx - 1]);
    m_participanti[p_idx - 1]->AdaugaBilet(bilet);

    cout << "Bilet cumparat cu succes!\n";
}

void SistemFestival::AfiseazaProgramFestival() const {
    if (m_concerte.empty()) {
        cout << "Nu exista concerte programate.\n";
        return;
    }

    for (const auto& concert : m_concerte) {
        concert->AfiseazaConcert();
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




SistemFestival::SistemFestival() {
    IncarcaParticipantiDinFisier("participanti.txt");
    IncarcaArtistiDinFisier("artisti.txt");
    IncarcaConcerteDinFisier("concerte.txt");
}
