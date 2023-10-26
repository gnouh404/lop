#include <bits/stdc++.h>
using namespace std;

class HT{
friend class DS;
friend class DSmau;
	float x, y, r;
public:
	HT(float x1 = 0, float y1 = 0, float r1 = 0){
		x = x1;
		y = y1;
		r = r1;
	}
	friend istream &operator >> (istream &cin, HT &a){
		cout << "Nhap hoanh do va tung do cua tam hinh tron: "; cin >> a.x >> a.y;
		cout << "Nhap ban kinh: "; cin >> a.r;
		return cin;
	}
	friend ostream &operator << (ostream &cout, HT &a){
		cout << "Toa do tam: (" << a.x << " , " << a.y << ")\n";
		cout << "Ban kinh: " << a.r << endl;
		return cout;
	}
	friend float dien_tich(HT &a){
		return M_PI*a.r*a.r;
	}
	float get_x(){return x;}
	float get_y(){return y;}
	float get_r(){return r;}
};

class DS{
	vector<HT> ds;
	int n;
public:
	void nhap(){
		cout << "Nhap so luong hinh tron: "; cin >> n;
		ds.resize(n);
		for(int i = 0; i < n; i++){
			cin >> ds[i];
		}
	}
	void xuat(){
		if(n == 0){
			cout << "Khong co hinh tron nao\n";
			return;
		}
		cout << "Danh sach hinh tron:\n";
		for(int i = 0; i < n; i++){
			cout << "Hinh tron thu " << i+1 << " : \n";
			cout << ds[i];
			cout << "Dien tich: " << dien_tich(ds[i]) << endl;
		}
	}
	void sap_xep(){
		for(int i = 0; i < n-1; i++){
			for(int j = i+1; j < n; j++){
				if(dien_tich(ds[i]) < dien_tich(ds[j])){
					HT tmp = ds[i];
					ds[i] = ds[j];
					ds[j] = tmp;
				}
			}
		}
	}
	void goc_phan_tu_thu_2(){
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if((ds[i].get_x() < 0) && (ds[i].get_y() > 0) && ds[i].get_r() <= -1*ds[i].get_x() && ds[i].get_r() <= ds[i].get_y()){
				if(cnt == 0){
					cout << "Cac hinh tron nam tron ven thuoc goc phan tu thu hai:\n";
				}
				++cnt;
				cout << "Hinh tron thu " << cnt << " :\n";
				cout << ds[i];
			}
		}
	}
};

class HTmau: public HT{
friend class DSmau;
	int mau;
public:
	friend istream &operator >> (istream &cin, HTmau &a){
		HT &tmp = a;
		cin >> tmp;
		cout << "Nhap mau: "; cin >> a.mau;
		return cin;
	}
	friend ostream &operator << (ostream &cout, HTmau &a){
		HT &tmp = a;
		cout << tmp;
		cout << "Mau: ";
		if(a.mau == 1) cout << "Do\n";
		else if(a.mau == 2) cout << "Xanh\n";
		else if(a.mau == 3) cout << "Vang\n";
		return cout;
	}
	friend float dien_tich_mau(HTmau &a){
		return M_PI*a.get_r()*a.get_r();
	}
	int get_mau(){return mau;}
};

class DSmau: public HTmau{
	vector<HTmau> dsmau;
	int m;
public:
	void nhap(){
		cout << "Nhap so luong hinh tron co mau: "; cin >> m;
		dsmau.resize(m);
		for(int i = 0; i < m; i++){
			cin >> dsmau[i];
		}
	}
	void tron_do_lon_nhat(){
		float MAX = -1;
		int index;
		for(int i = 0; i < m; i++){
			if(dsmau[i].get_mau() == 1){
				if(dien_tich_mau(dsmau[i]) > MAX){
					MAX = dien_tich_mau(dsmau[i]);
					index = i;
				}
			}
		}
		if(MAX == -1) cout << "Khong co hinh tron nao mau do\n";
		else cout << "Hinh tron mau do co dien tich lon nhat:\n" << dsmau[index];
	}
	void so_sanh_vang_xanh(){
		int vang = 0, xanh = 0;
		for(int i = 0; i < m; i++){
			if(dsmau[i].get_mau() == 2) ++xanh;
			else if(dsmau[i].get_mau() == 3) ++vang;
		}
		if(xanh > vang) cout << "So luong hinh tron mau xanh lon hon so luong hinh tron mau vang\n";
		else cout << "So luong hinh tron mau xanh khong lon hon so luong hinh tron mau vang\n";
	}
};

int main(){
	DS a;
	a.nhap();
	a.sap_xep();
	a.xuat();
	a.goc_phan_tu_thu_2();
	cout << endl;
	DSmau b;
	b.nhap();
	b.tron_do_lon_nhat();
	b.so_sanh_vang_xanh();
}
