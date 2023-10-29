#include <iostream>

using namespace std;

int licz_zagniezdzenie=0;
template <typename T, typename... Args>
void fun(T& pierwszy,Args&...arg){
    cout << "Pracuje konstruktor: " << __PRETTY_FUNCTION__ << endl;
    pierwszy++;
        if constexpr (sizeof...(Args) >0){
        cout << "Wykonanie zagniezdzenia nr: " << licz_zagniezdzenie++<<endl;
        fun(arg...);
    }

}


int main(){
cout << "Wykonujemy: " << "OpusMagMisjaC14C14_Rozdz1_Zad10"<< endl;
int el_pierwszy{1};
double el_drugi{2.2};
int el_trzeci{3};
cout << "Elementy przed wykonaniem funkcji: " << el_pierwszy << ", " << el_drugi << ", " << el_trzeci << endl;
fun(el_pierwszy, el_drugi, el_trzeci);
cout << endl << "Elementy po wykonaniu funkcji: " << el_pierwszy << ", " << el_drugi << ", " << el_trzeci << endl;

}
