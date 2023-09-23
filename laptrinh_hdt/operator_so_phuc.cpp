#include<iostream>
using namespace std;

struct sp{
	float thuc, ao;
};

istream &operator>> (istream &inp, sp &p){
	cout << "Nhap phan thuc:"; inp >> p.thuc;
	cout << "Nhap phan ao:"; inp >> p.ao;
	
	return inp;
}
ostream &operator<< (ostream &out, sp &p){
	out << "\n";
	if ( p.ao > 0) return out << p.thuc << "+" << p.ao << "i";
	if ( p.ao == 0 ) return out << p.thuc;
	else return out << p.thuc << p.ao << "i";
	
}

sp operator+(sp &a, sp &b){
	sp tong;
	tong.thuc = a.thuc + b.thuc;
	tong.ao = a.ao + b.ao;
	return tong;
}

sp operator-(sp &a, sp &b){
	sp hieu;
	hieu.thuc = a.thuc - b.thuc;
	hieu.ao = a.ao - b.ao;
	return hieu;
}
sp operator*(sp &a, sp &b){
	sp tich;
	tich.thuc = a.thuc*b.thuc - a.ao*b.ao;
    tich.ao = a.thuc*b.ao + a.ao*b.thuc;
	return tich;
}
sp operator/(sp &a, sp &b){
	sp thuong;
	thuong.thuc = (a.thuc*b.thuc + a.ao*b.ao)/(b.thuc*b.thuc + b.ao*b.ao);
    thuong.ao = (a.ao*b.thuc - a.thuc*b.ao)/(b.thuc*b.thuc + b.ao*b.ao);
	return thuong;
}
int main(){
	sp p1,p2,tong,hieu,tich,thuong,p3,p4,tmp,ans,res;
	cin >> p1;
	cout << "So phuc p1 co dang:" << p1 << "\n\n";
	cin >> p2;
	cout << "So phuc p2 co dang:" << p2 << "\n\n";
	cin >> p3;
	cout << "So phuc p3 co dang:" << p3 << "\n\n";
	cin >> p4;
	cout << "So phuc p4 co dang:" << p4 << "\n\n";
	tong = p1 + p2;
	cout << "Tong 2 so phuc co dang:" << tong << "\n\n";
	hieu = p1 - p2;
	cout << "Hieu 2 so phuc co dang:" << hieu << "\n\n";
	tich = p1 * p2;
	cout << "Tich 2 so phuc co dang:" << tich << "\n\n";
	thuong = p1 / p2;
	cout << "Thuong 2 so phuc co dang:" << thuong << "\n\n";
	tmp = p3 - p2;
	ans = tong / tmp;
	res = ans * p4;
	cout << "Bieu thuc co ket qua:" << res << "\n\n";
}
