#include<iostream>
#include<functional>
#include<bitset>
#include<vector>

using namespace std;

long int wpisana_liczba;
int spr_pozycja;

int main (){

cout << "Rozdz_II zad_10 Start:" << endl;
cout << "Podaj liczbe do sprawdzenia: " << endl;
cin >> wpisana_liczba;
bitset<sizeof(wpisana_liczba)*8> liczba_bitowo(wpisana_liczba);
cout << "liczba bitowo: " << liczba_bitowo << endl;

cout << "\nPodaj pozycje ktora sprawdzic: " << endl;
cin >> spr_pozycja;

auto lbd_pozycja_jedynki =
    [liczba_bitowo]
    (int poz)
    {
        cout << "Liczba na pozycji: " << poz << " to: " << liczba_bitowo[poz] << endl;
        return liczba_bitowo[poz];

    };
 lbd_pozycja_jedynki(spr_pozycja);


cout << "Oficjalna wersja rozwiazania: " << endl;
cout << boolalpha ;

	auto zmienna  { 9'999'999 };

	bitset<sizeof(zmienna)*8> liczba_bitow(zmienna);
    cout << "liczba bitowo: " << liczba_bitow << endl;

	auto czy_bit_zapalony = [](auto x, int nr) { return  (x &  (1  << nr)) ?  true : false; };

	for(unsigned int nr = 0 ; nr < 8*sizeof(zmienna) ; ++nr)
	{
		cout << "czy_bit " << nr << " zapalony? "
    			<< czy_bit_zapalony(zmienna, nr)<< endl;
	}

}
