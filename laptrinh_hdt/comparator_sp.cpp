#include<iostream>
using namespace std;

struct sp{
	float thuc, ao;
};

istream &operator>> (istream &inp, sp &p){
	cout << "Nhap phan thuc:"; inp >> p.thuc;
	cout << "Nhap phan ao:"; inp >> p.ao;
	cout << "\n";
	return inp;
}
ostream &operator<< (ostream &out, sp &p){
	out << "So phuc co dang:\n";
	if ( p.ao > 0) return out << p.thuc << "+" << p.ao << "i";
	if ( p.ao == 0 ) return out << p.thuc;
	else return out << p.thuc << p.ao << "i";
}

int main(){
	sp a,b;
	cin >> a;
	cout << a;
	
}
