#include <iostream>
#include <list>

using namespace std;

// Phần a: Xây dựng lớp biểu diễn đối tượng nhân viên
class NhanVien {
public:
    string ma;
    string hoTen;
    int namSinh;
    string gioiTinh;
    double luong;

    // Toán tử nhập >>
    friend istream& operator>>(istream& input, NhanVien& nv) {
        cout << "Nhap ma nhan vien: ";
        input >> nv.ma;
        cout << "Nhap ho ten: ";
        input.ignore();
        getline(input, nv.hoTen);
        cout << "Nhap nam sinh: ";
        input >> nv.namSinh;
        cout << "Nhap gioi tinh: ";
        input >> nv.gioiTinh;
        cout << "Nhap luong: ";
        input >> nv.luong;

        return input;
    }

    // Toán tử xuất <<
    friend ostream& operator<<(ostream& output, const NhanVien& nv) {
        output << "Ma nhan vien: " << nv.ma << ", Ho ten: " << nv.hoTen << ", Nam sinh: " << nv.namSinh
               << ", Gioi tinh: " << nv.gioiTinh << ", Luong: " << nv.luong;
        return output;
    }

    // Phương thức lấy mã
    string LayMa() const {
        return ma;
    }
};

// Phần b: Xây dựng lớp quản lý danh sách nhân viên
class QuanLyNhanVien {
private:
    list<NhanVien> danhSachNhanVien;

public:
    // Phương thức tạo danh sách có n nhân viên
    void TaoDanhSach(int n) {
        for (int i = 0; i < n; ++i) {
            NhanVien nv;
            cin >> nv; // Sử dụng toán tử nhập đã định nghĩa ở trên
            danhSachNhanVien.push_back(nv);
        }
    }

    // Phương thức xóa một nhân viên có mã là x
    void XoaNhanVien(const string& x) {
        danhSachNhanVien.remove_if([x](const NhanVien& nv) { return nv.LayMa() == x; });
    }

    // Phương thức in danh sách nhân viên có lương lớn hơn 2.000.000
    void InNhanVienLuongLonHon2Trieu() const {
        for (const auto& nv : danhSachNhanVien) {
            if (nv.luong > 2000000) {
                cout << nv << endl; // Sử dụng toán tử xuất đã định nghĩa ở trên
            }
        }
    }
};

int main() {
    QuanLyNhanVien quanLy;

    // Tạo danh sách có 3 nhân viên
    quanLy.TaoDanhSach(3);

    // In danh sách
    cout << "Danh sach sau khi tao:" << endl;
    quanLy.InNhanVienLuongLonHon2Trieu();

    // Xóa nhân viên có mã là 'NV001'
    string maCanXoa;
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> maCanXoa;
    quanLy.XoaNhanVien(maCanXoa);

    // In danh sách sau khi xóa
    cout << "Danh sach sau khi xoa:" << endl;
    quanLy.InNhanVienLuongLonHon2Trieu();

    return 0;
}
