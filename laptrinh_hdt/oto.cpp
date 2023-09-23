#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

class Car{
    
        string bks;
        float trong_tai;
        char cty;
    public:
        Car(){}
        friend istream &operator>>(istream &cin, Car &car){
            cout << "Nhap bks:"; cin.ignore(); getline(cin, car.bks);
            cout << "Nhap trong tai:"; cin >> car.trong_tai;
            cout << "Nhap cong ty:"; cin >> car.cty;
            return cin;
        }

        friend ostream &operator<<(ostream &cout, const Car &car){
            cout << "Bks:" << car.bks << "\n";
            cout << "Trong tai:" << car.trong_tai << "\n";
            cout << "Cong ty:" << car.cty << "\n";
            return cout;
        }  
        bool isFromA(){
            return this->cty == 'A';
        }
        bool is_bigger(Car car){
            return this->trong_tai > car.trong_tai;
        }
        string tt_bks(){
            return this->bks;
        }
        float tt_trong_tai(){
            return this->trong_tai;
        }
        char tt_cty(){
            return this->cty;
        }
        friend void bbs(Car car[], int n){
            car =  new Car[n];
            for (int i = 0; i < n-1; i++){
                for (int j = i+1; j < n; j++){
                    if(car[i].is_bigger(car[j])){
                        Car temp = car[i];
                            car[i] = car[j];
                            car[j] = temp;
                    }
                }
            }
        }
};

int main(){
    int n;
    cout << "Nhap so xe:"; cin >> n;
    Car a[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        cout << "\n";
        cout << a[i]; 
    }
    int k;
    cout << "\nNhap so xe can kiem tra trong tai:";
    cin >> k;
    bbs(a,n);
    for ( int i = 0; i < k; i++){
        if(a[i].tt_trong_tai() == 12 && a[i].isFromA()){
            cout << a[i];
        }
    }
}
