#include <iostream>
#include <iostream>
#include <fstream>

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
    return 0;
}
