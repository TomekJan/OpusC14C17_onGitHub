#include<iostream>
#include<bitset>
#include<sstream>

using namespace std;

/*Funkcja ma wypisywaæ na ekranie przys³an¹ jej liczbê.  Ma tê liczbê wypisaæ w zapisie binarnym,
ale tak, aby  opuœciæ ewentualne nieznacz¹ce zera.  */
template<typename T>
void binarnie(T liczba){
    cout << "Dziala: " << __PRETTY_FUNCTION__ << endl;
    bitset<sizeof(liczba)*8> liczba_bitowo(liczba);
    cout << "liczba bitowo: " << liczba_bitowo << endl;

    string liczba_string;
    liczba_string=liczba_bitowo.to_string();
    const char* liczba_char =liczba_string.c_str();
    cout << "liczba jako c-string: " << liczba_char << endl;

    //Wypisywanie info START
    /*
    cout << "Rusza iteracja po petli." << endl;
    cout << "Ilosc znakow liczba_bitowo.size(): " << liczba_bitowo.size() << endl;
    cout << "Ilosc znakow liczba_string.size(): " << liczba_string.size() << endl;


    for (int i=0; i<liczba_bitowo.size(); i++){
        cout << "liczba_nr_" << i << " to: " << liczba_bitowo[i] << " | ";
    }
    */
    //Wypisywanie info STOP

    cout << "\n Wydruk z f-cji while:\n";
    // Skip trailing '0':
    int i=(liczba_bitowo.size()-1);
    while (liczba_bitowo[i] == 0) { i--;  };
    do (cout << liczba_bitowo[i], i--);
    while (i>=0);
}


int main(){
    cout << "Rozdz_II zad_01 Start:" << endl;
    cout << "Podaj liczbe: " ;

    short int liczba_wpisana;
    cin >> liczba_wpisana;
    binarnie(liczba_wpisana);
}
