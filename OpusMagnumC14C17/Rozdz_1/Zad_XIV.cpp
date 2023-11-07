#include <iostream>
using namespace std;

int el_pierwszy{0};

//Szablon Glowny START
template <typename T, typename ...Elem>
void pokaz(T pierwszy, Elem... args){
    (el_pierwszy)++;
    //cout << "Dziala: " << __PRETTY_FUNCTION__ << endl;
    cout << "element nr: " << el_pierwszy << " o wartosci: " << pierwszy << endl;

    if constexpr (sizeof...(Elem)){
        pokaz(args...);
    }
}
//Szablon Glowny STOP


//Szablon fun_sum START
template <typename T, typename... Tpakiet>
auto suma(T arg, Tpakiet... reszta){
    (el_pierwszy)++;
    //cout << "Dziala: " << __PRETTY_FUNCTION__ << endl;
    cout << "element nr: " << el_pierwszy << " o wartosci: " << arg <<endl;
    if constexpr(sizeof...(Tpakiet)){
        return arg+suma(reszta...);
    }
    else {
            cout << "suma to: ";
            return arg;
    }
}
//Szablon fun_sum STOP

//Szablon fun_warsztat START
template <typename... Telem>
void warsztat(Telem... args){
    cout << "Dziala: " << __PRETTY_FUNCTION__ << endl;
    cout << "pokaz( args ... )" <<endl;
    pokaz( args ... );
	cout << "pokaz( 2*args ... )" <<endl;
	pokaz( 2*args ... );
	cout << "pokaz( args + 5 ... )" << endl;
	pokaz( args + 5 ... );
	cout << "pokaz( args*args ... )" << endl;
	pokaz( args*args ... );
	cout << "pokaz( args... , args ... )" << endl;
	pokaz( args... , args ... );
	cout << "pokaz( suma(args...) + args... )" << endl;
	pokaz( suma(args...) + args... );
}
//Szablon fun_warsztat STOP
int main(){
    cout << "Rozdz: 1, Zad: 14, Start:" << endl <<endl;

    int pierwszy{1};
    double drugi{2.2};
    char trzeci{'d'}; // 'c' = 100 in ASCII

    cout << "Elementy przed funkcja: " << pierwszy << ", " << drugi <<", " << trzeci << endl;
    cout << "\nA po funkcji pokaz: " << endl;
    el_pierwszy=0;
    pokaz(pierwszy,drugi,trzeci);
    el_pierwszy=0;
    cout << "\nA teraz funkcja suma: \n" << suma(pierwszy,drugi,trzeci) <<endl;
    el_pierwszy=0;
    cout << "\nA teraz funkcja warsztat: \n";
    warsztat(1, 2.2, 3);
    el_pierwszy=0;
}

