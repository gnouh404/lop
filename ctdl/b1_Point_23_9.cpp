#include<bits/stdc++.h>
using namespace std;

class Diem{
private:
    float x, y;
public:
    
    Diem(float x = 0, float y = 0){
        this->x = x;
        this->y = y;
    }
    void xuat(){
        cout << "( " << x << ", " << y << " )" << endl; 
    }
    float kc( Diem B){
        return sqrt( pow( (this->x - B.x), 2 ) + pow( (this->y - B.y), 2 ) );
    }

};

int main(){
    Diem O, A(-2, 5), B(3, 1);
    O.xuat();
    A.xuat();
    B.xuat();
    cout << "\n";
    cout << A.kc(B);
}