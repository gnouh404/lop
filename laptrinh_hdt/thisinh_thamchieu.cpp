#include<iostream>
#include<cstdlib>
using namespace std;
struct thisinh{
	char sbd[20],ht[50];
	float diem;
}ts;

void nhap_1ts(thisinh &a){
	cout<< "Nhap thong tin thi sinh:" << endl;
	cout << "Nhap so bao danh:"; 
	cin>>a.sbd;
	cout << "Nhap ho ten thi sinh:"; 
	cin>>a.ht;
	do{
		cout << "Nhap diem thi sinh:"; cin>>a.diem;
	}while(a.diem<0||a.diem>10);
}

istream &operator>>(istream &inp, thisinh &a){
	cout<< "Nhap thong tin thi sinh:" << endl;
	cout << "Nhap so bao danh:"; 
	inp>>a.sbd;
	cout << "Nhap ho ten thi sinh:"; 
	inp>>a.ht;
	do{
		cout << "Nhap diem thi sinh:"; inp>>a.diem;
	}while(a.diem<0||a.diem>10);
	return inp;
}

ostream & operator<<(ostream &out, const thisinh &a){
	out << "\n";
	out << "Thong tin thi sinh:" << endl;
	out << "So bao danh: " << a.sbd << endl;
	out << "Ho ten: " << a.ht << endl;
	out << "Diem: " << a.diem << endl;
	return out;
}

void in(const thisinh &a){
	cout << "\n";
	cout << "Thong tin thi sinh:" << endl;
	cout << "So bao danh: " << a.sbd << endl;
	cout << "Ho ten: " << a.ht << endl;
	cout << "Diem: " << a.diem << endl;
	cout << "\n";
}
thisinh* nhap_ds(int &n){
	cout << "Nhap so thi sinh can luu vao danh sach:";
	cin >> n;
	thisinh *a;
	a = new thisinh[n];
	for (int i=0;i<n;i++){
		cout<< "Nhap thong tin thi sinh thu "<< i+1 << ":" << endl;
		cout << "Nhap so bao danh:"; 
		cin>>a[i].sbd;
		cout << "Nhap ho ten thi sinh:"; 
		cin>>a[i].ht;
		do{
			cout << "Nhap diem thi sinh:"; cin>>a[i].diem;
		}while(a[i].diem<0||a[i].diem>10);
		cout << "\n";
	}
	return a;
}

void in_ds(thisinh *a, int n){
	for (int i=0;i<n;i++){
		cout<< "Nhap thong tin thi sinh thu "<< i+1 << ":" << endl;
		cout << "So bao danh: " << a[i].sbd << endl;
		cout << "Ho ten: " << a[i].ht << endl;
		cout << "Diem: " << a[i].diem << endl;
	}
	cout << "\n";
}

void sort(thisinh *a, int n){
    for (int i = (n-1); i >= 0; i--) {
        for (int j = 1; j <= i; j++){
            if (a[j-1].diem < a[j].diem)
            swap(a[j-1],a[j]);
        }
    }
} 

void sapxep(thisinh *a, int n){
	cout << "Danh sach thi sinh sau khi sap xep:"<< endl;
	for (int i=0;i<n;i++){
		cout<< "Nhap thong tin thi sinh thu "<< i+1 << ":" << endl;
		cout << "So bao danh: " << a[i].sbd << endl;
		cout << "Ho ten: " << a[i].ht << endl;
		cout << "Diem: " << a[i].diem << endl;
	}
}

int cmp(const void *a, const void *b){
	thisinh *x = (thisinh*)a;
	thisinh *y = (thisinh*)b;
	return x->diem < y->diem;
}

int main(){
	int n;
	thisinh a;
	thisinh *x = nhap_ds(n);;
//	nhap_1ts(a);
//	in(a);
	cout << "Danh sach thi sinh truoc khi sap xep:";
	cout << "\n" << "\n";
	in_ds(x,n);
	qsort(x,n,sizeof(thisinh),cmp);
	sapxep(x,n);
	
}
