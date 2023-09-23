#include <bits/stdc++.h>
using namespace std;

// Xây dựng lớp Diem
class Diem
{
private:
    string ht;  // họ tên
    char *sbd;  // số báo danh
    float diem; // điểm thi
public:
    // Hàm tạo mặc định
    Diem()
    {
        ht = "";
        sbd = NULL;
        diem = 0;
    }
    // Hàm tạo có tham số
    Diem(string ht, char *sbd, float diem)
    {
        this->ht = ht;
        this->sbd = new char[strlen(sbd) + 1];
        strcpy(this->sbd, sbd);
        this->diem = diem;
    }
    // Hàm hủy
    ~Diem()
    {
        delete[] sbd;
    }
    // Hàm nhập dữ liệu
    void nhap()
    {
        cout << "Nhap ho ten: ";
        getline(cin, ht);
        cout << "Nhap so bao danh: ";
        sbd = new char[10];
        cin.getline(sbd, 10);
        cout << "Nhap diem thi: ";
        cin >> diem;
        cin.ignore();
    }
    // Hàm in dữ liệu
    void in()
    {
        cout << ht << "\t" << sbd << "\t" << diem << endl;
    }
    // Hàm lấy điểm thi
    float lay_diem()
    {
        return diem;
    }
};

bool cmp(Diem a, Diem b)
{
    return a.lay_diem() > b.lay_diem();
}
// Xây dựng lớp Bang_Diem
class Bang_Diem
{
private:
    vector<Diem> ds; // danh sách điểm thi của n sinh viên
public:
    // Hàm tạo mặc định
    Bang_Diem()
    {
        ds.clear();
    }
    // Hàm nhập dữ liệu
    void nhap()
    {
        int n; // số lượng sinh viên
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
            Diem d;
            d.nhap();
            ds.push_back(d);
        }
    }
    // Hàm in dữ liệu
    void in()
    {
        cout << "Danh sach diem thi cua mon hoc" << endl;
        cout << "Ho ten\tSo bao danh\tDiem thi" << endl;
        for (int i = 0; i < ds.size(); i++)
        {
            ds[i].in();
        }
    }
    // Hàm sắp xếp danh sách theo thứ tự giảm dần của điểm thi

    void sap_xep()
    {
        sort(ds.begin(), ds.end(), cmp);
    }
};

// Viết chương trình chính
int main()
{
    Bang_Diem bd;
    bd.nhap();
    bd.sap_xep();
    bd.in();
    return 0;
}