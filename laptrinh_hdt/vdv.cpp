#include<bits/stdc++.h>
using namespace std;
class vdv{
    string ht, monthidau;
    int tuoi;
    float can_nang,chieu_cao;
    public:
    vdv(){
        ht = monthidau = "";
        tuoi = 0;
        can_nang = 0;
        chieu_cao = 0;
    }
    vdv(string ht, int tuoi, string monthidau, float cannang, float chieu_cao){
        this->ht = ht;
        this->tuoi = tuoi;
        this->monthidau = monthidau;
        this->can_nang = can_nang;
        this->chieu_cao = chieu_cao;
    }
    ~vdv(){
        ht = monthidau = "";
        tuoi = 0;
        can_nang = 0;
        chieu_cao = 0;
    }
    friend istream &operator>>(istream &cin, vdv &x){
        cout << "Ho ten:"; getline(cin, x.ht);
        cout << "Tuoi:"; cin >> x.tuoi;
        cin.ignore();
        cout << "Mon thi dau:"; getline(cin, x.monthidau);
        cout << "Can nang:"; cin >> x.can_nang;
        cout << "Chieu cao:"; cin >> x.chieu_cao;
        cin.ignore();
        return cin;
    }
    friend ostream &operator<<(ostream &cout, vdv &x){
        cout << "\nHo ten:" << x.ht << " Tuoi:" << x.tuoi << " Mon thi dau:" << x.monthidau << " Can nang:" << x.can_nang << " Chieu cao:" << x.chieu_cao;
        return cout;
    }
    bool operator>(const vdv &x){
        if(this->chieu_cao > x.chieu_cao) 
            return true;
        else if(this->chieu_cao < x.chieu_cao)
            return false;
        else if(this->can_nang > x.can_nang)
            return true;
        else 
            return false;            
    }
};
void swap(vdv &a, vdv &b){
    vdv tmp = a;
    a = b;
    b = tmp;
}
void sort(vdv arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
        }
    }
}
int main(){
    vdv p("asd",20,"bong da",78.2,180.3);
    cout << p;
    int n;
    cout << "\nNhap so van dong vien:"; cin >> n;
    cin.ignore();
    vdv *arr = new vdv[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << "\n";
    }
    sort(arr, n);
    cout << "\nDanh sach sau sap xep:\n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << "\n";
    }
}