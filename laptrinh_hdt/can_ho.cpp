#include<bits/stdc++.h>
using namespace std;

class canho
{

    string dia_chi;
    float dt;
    int so_phong;
    short huong;
    long long price;

public:
    friend istream &operator>>(istream &cin, canho &h)
    {
        cout << "Nhap dia chi:";
        cin.ignore();
        getline(cin, h.dia_chi);
        cout << "Nhap so phong:";
        cin >> h.so_phong;
        cout << "Nhap huong:";
        cin >> h.huong;
        cout << "Nhap gia can ho:";
        cin >> h.price;
        return cin;
    }
    friend ostream &operator<<(ostream &cout, const canho &h)
    {
        cout << "Dia chi: " << h.dia_chi << " ";
        cout << "So phong: " << h.so_phong << " ";
        cout << "Huong: " << h.huong << " ";
        cout << "Gia: " << h.price << "\n";
        return cout;
    }
};


class DSCH {
    canho *ch;
    int n;
    public:
        friend istream &operator>>(istream &cin, DSCH &lst){
            cout << "so can ho:"; cin >> lst.n;
            lst.ch = new canho[lst.n];
            for ( int i = 0; i < lst.n; i++){
                cin >> lst.ch[i];
            }
            return cin;
        }
        friend ostream &operator<<(ostream &cout, const DSCH &lst){
            for (size_t i = 0; i < lst.n; i++)
            {
                cout << lst.ch[i];  
            }
            return cout;
        }
};
int main()
{
    DSCH x;
    cin >> x;
    cout << x;

   
}