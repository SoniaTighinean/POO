#include "sistem_festival.h"
#include <iostream>

using namespace Festival_Manager;
using namespace std;

int main() {
    Festival_Manager::SistemFestival festival;
    int optiune;

    while (true) {
        cout << "\n======= MENIU FESTIVAL =======\n";
        cout << "1. Creeaza participant\n";
        cout << "2. Creeaza artist\n";
        cout << "3. Creeaza concert\n";
        cout << "4. Cumpara bilet\n";
        cout << "5. Afiseaza participanti cu biletele lor\n";
        cout << "6. Afiseaza artisti\n";
        cout << "7. Afiseaza program festival\n";
        cout << "8. Statistici festival\n";
        cout << "0. Iesire\n";
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune) {
        case 1: festival.CreeazaParticipant(); break;
        case 2: festival.CreeazaArtist(); break;
        case 3: festival.CreeazaConcert(); break;
        case 4: festival.CumparaBilet(); break;
        case 5: festival.AfiseazaParticipantiCuBilete(); break;
        case 6: festival.AfiseazaArtisti(); break;
        case 7: festival.AfiseazaProgramFestival(); break;
		case 8: festival.AfiseazaStatisticiFestival(); break;
        case 0: cout << "La revedere!\n"; return 0;
        default: cout << "Optiune invalida!\n";
        }
    }
}
