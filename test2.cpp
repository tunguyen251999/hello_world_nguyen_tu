#include <iostream>
using namespace std;

#include <vector>
#include <string>

class NhanVien
{
protected:
    string hoTen;
    string diaChi;
    string maid;
    float luong;

public:
    NhanVien()
    {
        this->hoTen = "";
        this->maid = "";
        this->diaChi = "";
        this->luong = 0.0;
    }

    virtual void nhap()
    {
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, this->hoTen);
        cout << "Nhap dia chi: ";
        cin.ignore();
        getline(cin, this->diaChi);
        cout << "Nhap msid";
        cin.ignore();
        getline(cin, this->maid);
    }

    virtual void xuat()
    {
        cout << "Ho ten: ";
        cout << this->hoTen << endl;
        cout << "Dia chi: ";
        cout << this->diaChi << endl;
        cout << "msnhanvien: ";
        cout << this->maid << endl;
    }

    virtual void tinhLuong() = 0;
    virtual int tinhPhuCap() = 0;
};

class NhanVienSanXuat : public NhanVien
{
private:
    int soSanPham;
    int soGioTangCa;

public:
    NhanVienSanXuat() : NhanVien()
    {
        this->soSanPham = 0;
        this->soGioTangCa = 0;
        this->luongCoBan = 0.0;
    }

    void nhap()
    {
        NhanVien::nhap();
        cout << "So san pham: ";
        cin >> this->soSanPham;
        cout << "So gio tang ca: ";
        cin >> this->soGioTangCa;
        cout << "Luong co ban: ";
        cin >> this->luongCoBan;
    }

    void xuat()
    {
        cout << "So san pham: ";
        cout << this->soSanPham << endl;
        cout << "So gio tang ca: ";
        cout << this->soGioTangCa << endl;
        cout << "Luong: ";
        cout << this->luong << endl;
        cout << "Luong phu cap: ";
    }

    void tinhLuong()
    {
        this->luong = this->soSanPham * this->luongCoBan;
    }
    int tinhPhuCap() {
        this->luong * this->soGioTangCa;
    }
};

class NhanVienVanPhong : public NhanVien
{
private:
    float luongCoBan;
    int soNgayLamViec;
    int soNgaynghi;

public:
    NhanVienVanPhong() : NhanVien()
    {
        this->luongCoBan = 0.0;
    }

    void nhap()
    {
        NhanVien::nhap();
        cout << "Luong co ban: ";
        cin >> this->luongCoBan;
        cout << "So ngay lam viec: ";
        cin >> this->soNgayLamViec;
    }

    void xuat()
    {
        NhanVien::xuat();
        cout << "Luong co ban: ";
        cout << this->luongCoBan << endl;
        cout << "So ngay lam viec: ";
        cout << this->soNgayLamViec << endl;
        cout << "Luong: ";
        cout << this->luong << endl;
    }

    void tinhLuong()
    {
        this->luong = this->soNgayLamViec * this->luongCoBan;
    }
    int tinhPhuCap()
    /////////////////
};

class CongTy
{
private:
    vector<NhanVien *> NV;

public:
    void nhap()
    {
        cout << "Nhap so nhan vien: ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Nhan vien van phong (1), nhan vien san xuat (2): ";
            int k;
            cin >> k;
            NhanVien *nv;
            // T??y v??o ng?????i d??ng ch???n ?????i t?????ng n??o ????? nh???p
            if (k == 1)
                nv = new NhanVienVanPhong;
            else
                nv = new NhanVienSanXuat;
            nv->nhap(); // ta s??? s??? d???ng h??m nh???p c???a ?????i t?????ng m?? ng?????i d??ng ch???n
            this->NV.push_back(nv);
        }
    }

    void xuat()
    {
        cout << "Nhan vien van phong:" << endl;
        for (int i = 0; i < this->NV.size(); i++)
        {
            cout << "STT:" << i + 1 << endl;
            this->NV.at(i)->xuat(); // t??y v??o ?????i t?????ng l?? g?? m?? ph????ng th???c xu???t s??? ???????c g???i theo ????ng ?????i t?????ng ????
        }
    }

    void tinhLuong()
    {
        for (int i = 0; i < this->NV.size(); i++)
            this->NV.at(i)->tinhLuong(); // t??y v??o ?????i t?????ng l?? g?? m?? ph????ng th???c t??nh l????ng s??? ???????c g???i theo ????ng ?????i t?????ng ????
    }
};

int main()
{
    CongTy cty;
    cty.nhap();
    cty.tinhLuong();
    cty.xuat();
    return 0;
}