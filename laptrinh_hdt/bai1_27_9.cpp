#include <bits/stdc++.h>
using namespace std;

class Diem
{
private:
    float hd, td;

public:
    Diem()
    {
        hd = 0;
        td = 0;
    }
    Diem(float x, float y)
    {
        hd = x;
        td = y;
    }
    float get_hd()
    {
        return this->hd;
    }
    float get_td()
    {
        return this->td;
    }
    void nhap()
    {
        cout << "Nhap hoanh do:";
        cin >> hd;
        cout << "Nhap tung do:";
        cin >> td;
    }
    void xuat()
    {
        cout << hd << " " << td << " ";
    }
};

class DiemMoi : public Diem
{
private:
    short color;
    // Diem diem;
public:
    DiemMoi() {}
    DiemMoi(Diem diem, short color) : Diem(diem), color(color) {}

    void get_color()
    {
        if (color == 1)
        {
            cout << "do\n";
        }
        if (color == 2)
        {
            cout << "xanh\n";
        }
        if (color == 3)
        {
            cout << "vang\n";
        }
    }
    void nhap()
    {
        float x, y;
        Diem::nhap();

        cout << "Nhap mau:";
        cin >> color;
        Diem diem(x, y);
    }
    void xuat()
    {
        Diem::xuat();
        get_color();
    }
    short get_diem_vang()
    {
        if (this->color == 3)
            return 3;
    }
};
class Ungdung
{
    int n;
    DiemMoi *ds;

public:
    void nhap();
    void thongke();
    void xuat();
};
void Ungdung::nhap()
{
    cin >> n;
    ds = new DiemMoi[n];
    for (int i = 0; i < n; i++)
        ds[i].nhap();
}
void Ungdung::xuat()
{
    for (int i = 0; i < n; i++)
    {
        ds[i].xuat();
    }
}
void Ungdung::thongke()
{
    int cnt = 0;
    if (this->ds->get_diem_vang())
    {
        cnt++;
    }
    cout << "Co " << cnt << " diem vang" << "\n";
}
int main()
{
    Ungdung ds;
    ds.nhap();
    ds.xuat();
}