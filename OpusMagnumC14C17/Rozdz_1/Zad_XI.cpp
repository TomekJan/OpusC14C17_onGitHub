#include<iostream>

using namespace std;

int licznik{0};
//Szablon funkcji START
template <typename T, typename...Args>
void fun(const T& pierwszy,const Args&...arg){
    cout << "Dziala: " << __PRETTY_FUNCTION__ << endl;
    cout <<"el nr: " << licznik++ << " to: "<< pierwszy << endl;

    if constexpr(sizeof...(Args)){
        fun(arg...);
    }
}
//Szablon funkcji STOP

const int pierwszy{1};
const double drugi{2.2};
const string trzeci{"trzeci, jako tekst"};

int main(){
cout << "Rozdz I, Zadanie XI start" <<endl <<endl;

licznik=1;
fun(pierwszy,drugi,trzeci);
licznik=1;

}
