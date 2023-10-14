#include <iostream>
#include <vector>

using namespace std;

vector<double> vmale;
vector<double> vsrednie;
vector<double> vduze;
void druk(vector<double>, string);


template<typename...Arg>
void rozdzielacz(Arg...arg){
    constexpr int rozmiar_tablicy =sizeof ... (Arg);
    cout << "\n dziala f_rozdzielacz, o " << rozmiar_tablicy << " argumentach" <<endl;
    double tabl[rozmiar_tablicy]{arg...};
    for (int i=0; i<=(rozmiar_tablicy-1); i++){
        if (tabl[i]<10) {
            vmale.push_back(tabl[i]);
        }
        else if (tabl[i]<100) {
            vsrednie.push_back(tabl[i]);
        }
        else if (tabl[i]>100) {
            vduze.push_back(tabl[i]);
        }
        else {
            cout << "\n inny przypadek" << endl;
        }
    }
}

int main()
{
 cout << "\n cokolwiek \n";
 rozdzielacz(5.5, 7.8, 1000, 105, 15);
 druk(vmale, "male");
 druk(vsrednie, "srednie");
 druk(vduze,"duze");

};

void druk(vector<double> wekt, string nazwa){
    cout << "\n wydruk " << nazwa << endl;
for (auto x:wekt){
    cout << " " << x << " ";
}
}
