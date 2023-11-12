#include<iostream>
#include<bitset>
#include<sstream>

using namespace std;

/*Funkcja ma wypisywaæ na ekranie przys³an¹ jej liczbê.  Ma tê liczbê wypisaæ w zapisie binarnym,
ale tak, aby  opuœciæ ewentualne nieznacz¹ce zera.  */
void binarnie(short int liczba){
    cout << "Dziala: " << __PRETTY_FUNCTION__ << endl;
    bitset<sizeof(liczba)*8> liczba_bitowo(liczba);
    cout << "liczba bitowo: " << liczba_bitowo << endl;
    string liczba_string;
    liczba_string=liczba_bitowo.to_string();
    const char* liczba_char =liczba_string.c_str();
    cout << "liczba jako c-string: " << liczba_char << endl;

    cout << "Rusza iteracja po petli." << endl;
    int i{0};
    while ((liczba_char[i]) || (i<100)){
        cout << "i=" << i++ << ", liczba[i]=" << liczba_char[i] << " || ";
    }
}


int main(){
    cout << "Rozdz_II zad_01 Start:" << endl;
    cout << "Podaj liczbe: " ;

    short int liczba_wpisana;
    cin >> liczba_wpisana;
    binarnie(liczba_wpisana);
}
