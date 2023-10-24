#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Twalczacy_mieczem
{
public:
    int dlugosc_miecza;
    Twalczacy_mieczem(int dl_m): dlugosc_miecza(dl_m)
    {
        cout << "\n Dziala kontruktor Twalczacy_mieczem " << dlugosc_miecza << "m dlugosci"<< "\n";
    };
};

class Tlatajacy_na_smoku
{
    int liczba_skrzydel;
public:
    Tlatajacy_na_smoku(int l_sk): liczba_skrzydel(l_sk)
    {
        cout << "\n Dziala kontruktor Tlatajacy_na_smoku o " << liczba_skrzydel << " skrzydlach" << "\n";
    };
};

class Tznajacy_magie
{
public:
    int stopien_wtajemniczenia, moc;
    Tznajacy_magie(int st_wt, int m) : stopien_wtajemniczenia(st_wt), moc(m)
    {
        cout << "\n Dziala kontruktor Tznajacy_magie na poziomie " << stopien_wtajemniczenia << " o mocy " << moc << "\n";
    };

};

void zaklete_zamczysko( Tznajacy_magie *p );
void pokonaj_przepasc ( Tlatajacy_na_smoku *p );
void bitwa_rycerska( Twalczacy_mieczem *p );

//Class Template START
template<typename...Tclasses>
class Tpostac_gry: public Tclasses...
{
    string imie;
public:
    Tpostac_gry(const char* im, Tclasses... klasy): Tclasses(klasy)..., imie(im)
    {
        cout << "\n Dziala kontruktor Tpostac_gry: " << imie <<"\n";
    }
};
//Class Template STOP

int main(){
    cout << "Opus 14/17 Rozdz_1 Zad_5: " << __PRETTY_FUNCTION__ <<endl;
    Tpostac_gry<Twalczacy_mieczem> wojownik("mietek waleczny",10);
    Tpostac_gry<Tznajacy_magie, Tlatajacy_na_smoku> magik {"merlin potezny",{100,5},{2}};
    zaklete_zamczysko(&magik);
    //zaklete_zamczysko(&wojownik);
}


// Definicje funkcji START
void zaklete_zamczysko( Tznajacy_magie *p ){
 cout << __PRETTY_FUNCTION__ << " atak z moca: " << p->moc <<endl;
};
void pokonaj_przepasc ( Tlatajacy_na_smoku *p );
void bitwa_rycerska( Twalczacy_mieczem *p );
// Definicje funkcji STOP
