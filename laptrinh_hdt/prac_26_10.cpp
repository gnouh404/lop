#include<bits/stdc++.h>
using namespace std;

class HT{
    float x,y,r;
    public:
    HT(){
        x = y = 0;
        r = 1;
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
    friend float dientich(const HT &h){
        return M_PI*h.r*h.r;
    }
    bool check(){
        if((x < 0 && y > 0) && (r <= min(abs(x),abs(y)))){
            return true;
        }
        return false;
    }
    float getx(){return x;}
    float gety(){return y;}
    float getr(){return r;}
};

class DS{
    vector<HT> ds;
    int n;
    public:
    void nhap(){
        cout << "Nhap so hinh tron:";
        cin >> n;
        ds.resize(n);
        for(int i=0; i < n; i++){
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
			cout << "Dien tich: " << dientich(ds[i]) << endl;
		}
    }
    void sapxep(){
        for(int i = 0; i < n - 1; i++)
            for(int j = i + 1; j < n; j++){
                if(dientich(ds[i]) < dientich(ds[j])){
                    HT tmp = ds[i];
					ds[i] = ds[j];
					ds[j] = tmp;
                }
            }
    }
    void thongke(){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(ds[i].check()){
                if(cnt == 0){
                    cout << "Cac hinh tron nam tron ven thuoc goc phan tu thu hai:\n";
                }
                cnt++;
                cout << "Hinh tron thu " << cnt << " :\n";
				cout << ds[i];
            }
        }
    }
};
class HTmau:public HT{
    friend class DSmau;
    int mau;
    public:
        friend istream &operator>>(istream &cin, HTmau &a){
            HT &tmp = a;
            cin >> tmp;
            cout << "Nhap mau: "; cin >> a.mau;
            return cin;
        }
        friend ostream &operator<<(ostream &cout, HTmau &a){
            HT &tmp = a;
            cout << tmp;
            cout << "Mau: ";
            if(a.mau == 1) cout << "Do\n";
            else if(a.mau == 2) cout << "Xanh\n";
            else if(a.mau == 3) cout << "Vang\n";
            return cout;
        }
        friend float dientich(HTmau &a){
            return M_PI*a.getr()*a.getr();
        }
        int getmau(){return mau;}
};
class Dsmau:public HTmau{
    int m;
    vector<HTmau> dsmau;
    public:
        void nhap(){
            cout << "Nhap so luong hinh tron co mau:";
            cin >> m;
            dsmau.resize(m);
            for(int i = 0; i < m; i++){
                cin >> dsmau[i];
            }
        }
        void smax(){
            float max = -1;
            int max_index = -1;
            for(int i = 0; i < m; i++){
                if( dsmau[i].getmau() == 1){
                    if(dientich(dsmau[i]) > max){
                        max = dientich(dsmau[i]);
                        max_index = i;
                    }
                }
            }
            if( max == -1) cout << "Khong co hinh tron mau do\n";
            else cout << "Hinh tron mau co dien tich lon nhat:\n" << dsmau[max_index]; 
        }
        void sosanh(){
            int xanh=0, vang = 0;
            for( int i = 0; i < m; i++){
                if(dsmau[i].getmau() == 2){
                    xanh++;
                }
                else if(dsmau[i].getmau() == 3){
                    vang++;
                }
            }
            if ( xanh > vang ) cout << "So hinh tron mau xanh lon hon so hinh tron mau vang";
            else cout << "So hinh tron mau xanh khong lon hon so hinh tron mau vang";
        }   
};
int main(){
    DS ht;
    ht.nhap();
    ht.sapxep();
    ht.xuat();
    ht.thongke();
    Dsmau htmau;
    htmau.nhap();
    htmau.smax();
    htmau.sosanh();
}