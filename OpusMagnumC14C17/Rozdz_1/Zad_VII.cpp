#include<iostream>

using namespace std;


template <char...Pznaki>
class Tkacz{
    //ciekawe czy musi byc unsigned?
    static constexpr unsigned int ilosc_znakow=sizeof...(Pznaki);
    //char tabl[sizeof...(Pznaki)+1]={Pznaki... };
    char tabl[ilosc_znakow+1]{Pznaki... };
public:
    void tkaj_rzad(int przesuniecie){
        for (int i=0; i<ilosc_znakow ; i++){
            cout << tabl[(przesuniecie+i)%ilosc_znakow];
        }
        for (int i=ilosc_znakow-1; i>-1 ; --i){
            cout << tabl[(przesuniecie+i)%ilosc_znakow];
        }
    };

};

int main(){
    Tkacz <'0','1','2','3','4','5','6','.'> n;
    n.tkaj_rzad(0);
}
