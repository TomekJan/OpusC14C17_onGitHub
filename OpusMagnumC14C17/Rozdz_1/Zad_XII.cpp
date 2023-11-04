#include <iostream>

using namespace std;

//Szablon START
template <typename T, typename ...Arg>
void fun(T*const el_pierwszy, Arg*const...args){
    (*el_pierwszy)++;
    cout << "element: " << *el_pierwszy << endl;

    if constexpr (sizeof...(Arg)){
        fun(args...);
    }
}

//Szablon STOP

int main(){
    cout << "Rozdz: 1, Zad: 12, Start:" << endl <<endl;

    int pierwszy{1};
    double drugi{2.2};
    char trzeci{'a'};

    cout << "Elementy przed funkcja: " << pierwszy << ", " << drugi <<", " << trzeci << endl << "A po funkcji: " << endl;
    fun(&pierwszy,&drugi,&trzeci);
}
