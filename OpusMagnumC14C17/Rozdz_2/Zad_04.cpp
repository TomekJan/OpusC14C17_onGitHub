#include<iostream>
#include<bitset>
#include<string>

using namespace std;

int main(){
    cout << "Rozdz_II zad_04 Start:" << endl;
    cout << "Podaj liczbe w systemie dwojkowym: ";
    string tekst;
    cin >> tekst;

    // usuwamy 0b
    auto pozycja=tekst.find("0b");
    if(pozycja != string::npos) tekst.erase(pozycja,2);

    // usuwamy apostrofy
    while(1){
        pozycja = tekst.find("'");
        if(pozycja == string::npos) break;
        tekst.erase(pozycja,1);
    }
    cout << "\nLiczba po czyszczeniu: " << tekst << endl;

    bitset<8*sizeof(unsigned long)> bbb(tekst);
    auto g = bbb.to_ulong();
    cout << "Liczba w obiekcie g wpisana dziesiatkowo = " << g << endl;

    // ZADANIE 1: Umozliwic dodawanie apostrofow dla cyfr
    // ZADANIE 2: Liczbe moge zaczynac od 0b
}
