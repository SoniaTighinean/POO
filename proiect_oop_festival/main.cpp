#include "sistem_festival.h"
#include <iostream>

using namespace Festival_Manager;


int main() {
    Festival_Manager::SistemFestival festival;
    int optiune;

    while (true) {
        std::cout << "\n======= MENIU FESTIVAL =======\n";
        std::cout << "1. Creeaza participant\n";
        std::cout << "2. Creeaza artist\n";
        std::cout << "3. Creeaza concert\n";
        std::cout << "4. Creeaza Sponsor\n";
        std::cout << "5. Cumpara bilet\n";
        std::cout << "6. Afiseaza participanti si bilete\n";
        std::cout << "7. Afiseaza artisti\n";
        std::cout << "8. Afiseaza program festival\n";
        std::cout << "9. Afiseaza sponsori\n";
        std::cout << "10. Statistici festival\n";
        std::cout << "0. Iesire\n";
        std::cout << "Alege o optiune: ";
        std::cin >> optiune;

        switch (optiune) {
        case 1: festival.CreeazaParticipant(); break;
        case 2: festival.CreeazaArtist(); break;
        case 3: festival.CreeazaConcert(); break;
        case 4: festival.CreeazaSponsor(); break;
        case 5: festival.CumparaBilet(); break;
        case 6: festival.AfiseazaParticipantiCuBilete(); break;
        case 7: festival.AfiseazaArtisti(); break;
        case 8: festival.AfiseazaProgramFestival(); break;
        case 9: festival.AfiseazaSponsori(); break;
		case 10: festival.AfiseazaStatisticiFestival(); break;
        case 0: std::cout << "La revedere!\n"; return 0;
        default: std::cout << "Optiune invalida!\n";
        }
    }
}
