#include <bits/stdc++.h>
using namespace std;

class Diem
{
    friend class Bang_Diem;

private:
    string ht;
    char *sbd;
    float diem;

public:
    Diem()
    {
        this->ht = "";
        this->sbd = strdup("");
        this->diem = 0;
    }

    Diem(string ht, char *sbd, float diem)
    {
        this->ht = ht;
        this->sbd = strdup(sbd);
        this->diem = diem;
    }
    

    void nhap()
    {

        cout << "\nHo va ten: ";
        cin.ignore();
        getline(cin, ht);
        sbd = new char[30];
        cout << "So bao danh: ";
        cin.getline(sbd, 30);
        cout << "Diem: ";
        cin >> diem;
        cin.ignore();
    }

    void in()
    {
        cout << "Ho ten:" << ht << endl;
        cout << "So bao danh:" << sbd << endl;
        cout << "Diem:" << diem << endl;
    }

    float get_diem()
    {
        return this->diem;
    }
};

bool cmp(Diem a, Diem b)
{
    return a.get_diem() > b.get_diem();
}

class Bang_Diem
{
    vector<Diem> ds;

public:
    // Bang_Diem()
    // {
    //     ds.clear();
    // }
    void nhap()
    {
        int n;
        cout << "Nhap so sinh vien:";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
            Diem d;
            d.nhap();
            ds.push_back(d);
        }
    }

    void in()
    {
        cout << "\nDanh sach diem thi:\n";
        for (int i = 0; i < ds.size(); i++)
        {
            ds[i].in();
        }
    }
    void sap_xep()
    {
        sort(ds.begin(), ds.end(), cmp);
    }
};

int main()
{
    Bang_Diem bd;
    bd.nhap();
    bd.in();
    bd.sap_xep();
    cout << "\nDs sau khi sap xep:\n";
    bd.in();
    return 0;
}