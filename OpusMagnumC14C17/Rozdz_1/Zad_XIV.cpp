#include <iostream>
using namespace std;

int el_pierwszy{0};

//Szablon Glowny START
template <typename T, typename ...Elem>
void pokaz(T pierwszy, Elem... args){
    (el_pierwszy)++;
    cout << "Dziala: " << __PRETTY_FUNCTION__ << endl;
    cout << "element nr: " << el_pierwszy << " o wartosci: " << pierwszy << endl << endl;

    if constexpr (sizeof...(Elem)){
        pokaz(args...);
    }
}
//Szablon Glowny STOP


//Szablon fun_sum START
template <typename T, typename... Tpakiet>
auto suma(T arg, Tpakiet... reszta){
    if constexpr(sizeof...(Tpakiet)){
        return arg+suma(reszta...);
    }
    else return arg;
}
//Szablon fun_sum STOP

int main(){
    cout << "Rozdz: 1, Zad: 14, Start:" << endl <<endl;

    int pierwszy{1};
    double drugi{2.2};
    char trzeci{'a'};

    cout << "Elementy przed funkcja: " << pierwszy << ", " << drugi <<", " << trzeci << endl << endl << "A po funkcji: " << endl;
    pokaz(pierwszy,drugi,trzeci);
}
