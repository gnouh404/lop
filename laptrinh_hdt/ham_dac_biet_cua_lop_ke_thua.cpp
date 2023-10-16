#include<bits/stdc++.h>
using namespace std;

class A{
    int a1, *a2;
    public:
    A(){
        a2 = new int;
        a1 = *a2 = 0;
    }
    A(int x, int y){
        a1 = x;
        a2 = new int;
        *a2 = y;
    }
    ~A(){
        delete a2;
    }
    A(const A& x){
        a1 = x.a1;
        a2 = new int;
        *a2 = *(x.a2);
    }
    A &operator=(const A& x){
        a1 = x.a1;
        a2 = new int;
        *a2 = *(x.a2);
        return *this;
    }
    friend ostream &operator << (ostream &cout, const A& x){
        cout << x.a1 << " " << x.a2 << endl;
        return cout;
    }
    void xuat(){
        cout << a1 << " " << *a2 << " "; 
    }
};

class B:public A{
    int b;
    public:
    B():A(){
        b = 1;
    }
    B(int x):A(){
        b = x;
    }
    B(int x, int y, int z):A(x,y){
        b = z;
    }
    B(const B&x):A((A)x){
        b =x.b;
    }
    B &operator = (const B&x){
        b = x.b;
        A::operator=((A)x);
        return *this;
    }
    void display(){
        A::xuat();
        cout << b << " ";
        
    }
};

int main(){
    B x(1,2,3);
    x.display();
}