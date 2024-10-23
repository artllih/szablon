/* #include <iostream>
using namespace std;

template <typename T>
void filtruj(T tab[], int rozmiar, T x) {
    for (int i = 0; i<rozmiar; ++i) {
        if(tab[i] >=x) {
            cout<<tab[i]<< " "<<endl;
        }
    };
};

int main(){
    int liczby[] = {1,4,6,7,8,81,43};
    int rozmiar_liczby = sizeof(liczby) / sizeof(liczby[0]);
    int x = 6;
    
    filtruj<int>(liczby, rozmiar_liczby, x);
    
    return 0;
}
*/

//zad2
#include <iostream>
using namespace std;

template <typename A>
class Wezel {
    public:
    A wartosc;
    Wezel<A>* next;
    
    Wezel (A val) : wartosc(val), next (nullptr) {}
};

template <typename A>
class ListaJednokierunkowa {
    private:
    Wezel<A>* glowa;
    
    public:
    ListaJednokierunkowa() : glowa(nullptr) {}
    
    ~ListaJednokierunkowa() {
        while (!empty()) {
            remove(0);
        }
    }
    bool empty() const {
        return glowa == nullptr;
    }
    
    void push(A wartosc) {
         
            Wezel<A>* nowyWezel = new Wezel<A>(wartosc);
            if(empty()){
                glowa = nowyWezel;
            } else {
                Wezel<A>* aktualny = glowa;
                while(aktualny -> next != nullptr) {
                    aktualny = aktualny->next;
                }
                aktualny->next = nowyWezel;
            }
        }
        
        void remove(int ind) {
            if (empty()) {
                cout<<"lista jest pusta"<<endl;
                return;
            }
            if (ind == 0) {
                Wezel<A>* przedUsunieciem = glowa;
                glowa = glowa->next;
                delete przedUsunieciem;
            } else {
                Wezel<A>* aktualny=glowa;
                Wezel<A>* popredni = nullptr;
                int i = 0;
                
                while (aktualny != nullptr && i < ind) {
                    popredni = aktualny;
                    aktualny = aktualny->next;
                    i++;
                }
                
                if (aktualny == nullptr) {
                    cout<<"index poza zakresem"<<endl;
                    return;
                }
                popredni -> next = aktualny -> next;
                delete aktualny;
                
            }
        }
        void display() {
            if(empty()) {
                cout<<"lista jest pusta"<<endl;
                return;
            }
            Wezel<A>* aktualny = glowa;
            while (aktualny != nullptr) {
                cout<<aktualny -> wartosc << " ";
                aktualny = aktualny->next;
                
            } cout<<endl;
        }
};

int main(){
    ListaJednokierunkowa<int> ListaInt;
    ListaInt.push(10);
    ListaInt.push(20);
    ListaInt.push(30);
    cout<<"lista calkowitych: ";
    ListaInt.display();
    
    ListaJednokierunkowa<double> ListaDouble;
    ListaDouble.push(3.14);
    ListaDouble.push(5.21);
    ListaDouble.push(6.66);
    cout<<"lista double: ";
    ListaDouble.display();
    
    ListaInt.remove(1);
    cout<<"lista calkowitych po usunieciu 2 elementu: ";
    ListaInt.display();
    
    cout<<"Czy lista liczb calkowitych jest pusta? "<<(ListaInt.empty() ? "Tak" : "Nie")<<endl;
    
    ListaJednokierunkowa<string> listaString;
    listaString.push("japppko");
    listaString.push("banananana");
    listaString.push("winogrono");
    cout<<"Lista stringow: ";
    listaString.display();
    
    return 0;
}
