#include<iostream>
#include<string>

using namespace std;

//Nowe typy START
struct Dobry {
int wartosc=1;
};
struct Zly {
int wartosc=0;
};
//Nowe typy STOP

// Szablony F-cji decydujacej START
template <typename T>
Zly czy_lubiany_typ;

template<>
Dobry czy_lubiany_typ<const char*>;

template<>
Dobry czy_lubiany_typ<string>;
// Szablony F-cji decydujacej STOP

// Szablon nadrzedny START
//// Typ Lubiany START
template <typename T>
void fun_dwoista(T arg, Dobry){
    cout << "\tF. dwoista wg szablonu A dla typow lubianych" << endl;
    string tekst(arg);
    cout << "\tTekst:>" << tekst <<"<, \n\ta litera nr[2] to " << arg[2] << "\"" << endl;
}
//// Typ Lubiany STOP

//// Typ NIE Lubiany START
template <typename T>
void fun_dwoista(T arg, Zly){
    cout << "\tF. dwoista wg szablonu B dla typow NIE-lubianych" << endl;
    T tmp = arg;
    cout <<"\tWydruk nie-tekstowego arg=" << tmp << endl;
}
//// Typ NIE Lubiany STOP
// Szablon nadrzedny STOP

// Szablon Glowny START
template <typename T>
void funkcja_robocza(T arg){
    fun_dwoista(arg, czy_lubiany_typ<T>);
    cout << "Czy ten typ T jest aprobowany? ";
    if(czy_lubiany_typ<T>.wartosc){
        cout << "TAK" << endl;
    }
    else {
        cout << "NIE" << endl;
    }
}
// Szablon Glowny STOP

int main(){
    cout << "Rozdz_II zad_05 Start:" << endl;

    cout << "\nProba z liczba typu T---> int\n";
    funkcja_robocza(5);

    cout << "\nProba z C-stringiem (typ const char*)\n";
    funkcja_robocza("abc");

    cout << "\nProba z obj. kl. string\n";
    string s("Nowosci w C++14");
    funkcja_robocza(s);

    cout << "\nProba ze wskaznikiem int*\n";
    int roboczy =4;
    int* wsk = &roboczy;
    funkcja_robocza(wsk);

}
