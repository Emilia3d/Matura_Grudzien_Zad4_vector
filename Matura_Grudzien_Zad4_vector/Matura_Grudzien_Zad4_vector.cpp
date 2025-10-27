#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream plik("prostokaty_przyklad.txt");

    //ZWYKŁY WEKTOR
    vector<int> wysokosc;
    vector<int> szerokosc;
    int a, b;

    while (plik >> a >> b) {
        wysokosc.push_back(a);
        szerokosc.push_back(b);
    }

    cout << "Pierwsze liczby:" << endl;
    for (int liczba : wysokosc) {
        cout << liczba << " ";
    }
    cout << endl;

    cout << "Drugie liczby:" << endl;
    for (int liczba : szerokosc) {
        cout << liczba << " ";
    }
    cout << endl;

    //WEKTOR PAR
    vector<pair<int, int>> dane;  // Wektor, który będzie przechowywał pary liczb całkowitych
    int ap, bp;

    while (plik >> ap >> bp) {
        dane.push_back(make_pair(a, b));  // Dodajemy parę liczb do wektora
    }

    cout << "Wczytane dane:" << endl;
    for (auto wys_szer : dane) {
        cout << wys_szer.first << " " << wys_szer.second << endl;
    }

    //Zad. 4.1
    cout << "4.1" << endl;
    int min_pole = INT_MAX, max_pole = INT_MIN;
    for (size_t i = 0; i < wysokosc.size(); ++i) {
        int pole = wysokosc[i] * szerokosc[i];
        min_pole = min(min_pole, pole);
        max_pole = max(max_pole, pole);
    }
    cout << min_pole << endl;
    cout << max_pole << endl;
    int max_dlugosc = 1, dlugosc = 1;
    int ostatnia_wysokosc = wysokosc[0], ostatnia_szerokosc = szerokosc[0];

    //Zad. 4.2
    cout << "4.2" << endl;
    for (int i = 1; i < wysokosc.size(); ++i) {
        if (wysokosc[i] <= ostatnia_wysokosc && szerokosc[i] <= ostatnia_szerokosc) {
            dlugosc++;
        }
        else {
            dlugosc = 1; // Resetujemy ciąg
        }
        max_dlugosc = max(max_dlugosc, dlugosc);

        ostatnia_wysokosc = wysokosc[i];
        ostatnia_szerokosc = szerokosc[i];
    }

    cout << max_dlugosc << endl;

    //Zad. 4.3
    cout << "4.3" << endl;

    vector<vector<int>> szerokosci_po_wysokosciach(40001); // 40001, ponieważ maksymalna wysokość to 40 000

    // Grupujemy prostokąty po wysokościach
    for (int i = 0; i < wysokosc.size(); ++i) {
        szerokosci_po_wysokosciach[wysokosc[i]].push_back(szerokosc[i]);
    }

    int suma2s = 0;

    // Przechodzimy po wszystkich wysokościach
    for (int i = 0; i <= 40000; ++i) {
        if (szerokosci_po_wysokosciach[i].size() >= 2) {
            sort(szerokosci_po_wysokosciach[i].rbegin(), szerokosci_po_wysokosciach[i].rend()); // Sortujemy szerokości malejąco
            int suma = szerokosci_po_wysokosciach[i][0] + szerokosci_po_wysokosciach[i][1]; // Suma szerokości dwóch pierwszych prostokątów
            suma2s = max(suma2s, suma);
        }
    }

    cout << "Największa szerokość przy sklejaniu 2 prostokątów: " << suma2s << endl;


    return 0;
}
