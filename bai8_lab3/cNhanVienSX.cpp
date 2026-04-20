#include "cNhanVienSX.h"
#include <iomanip>
#include <sstream>

bool IsValidDateSX(int d, int m, int y) {
  if (y < 1900 || y > 2100)
    return false;
  if (m < 1 || m > 12)
    return false;
  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
    daysInMonth[2] = 29;
  }
  return d > 0 && d <= daysInMonth[m];
}

cNhanVienSX::cNhanVienSX() {
  maNV = "";
  hoTen = "";
  ngaySinh = "";
  soSanPham = 0;
  donGia = 0.0;
}

string cNhanVienSX::getMaNV() const { return maNV; }
void cNhanVienSX::setMaNV(string ma) { maNV = ma; }

string cNhanVienSX::getHoTen() const { return hoTen; }
void cNhanVienSX::setHoTen(string ten) { hoTen = ten; }

string cNhanVienSX::getNgaySinh() const { return ngaySinh; }
void cNhanVienSX::setNgaySinh(string ngay) { ngaySinh = ngay; }

int cNhanVienSX::getSoSanPham() const { return soSanPham; }
void cNhanVienSX::setSoSanPham(int so) { soSanPham = so; }

double cNhanVienSX::getDonGia() const { return donGia; }
void cNhanVienSX::setDonGia(double gia) { donGia = gia; }

double cNhanVienSX::TinhLuong() const { return soSanPham * donGia; }

void cNhanVienSX::Nhap() {
  cout << "Nhap ma nhan vien: ";
  cin >> maNV;
  cin.ignore();
  cout << "Nhap ho ten nhan vien: ";
  getline(cin, hoTen);

  bool validDate = false;
  do {
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    string tempInput;
    getline(cin, tempInput);

    for (char &c : tempInput) {
      if (c == '/' || c == '-')
        c = ' ';
    }

    int d, m, y;
    stringstream ss(tempInput);
    if (ss >> d >> m >> y && IsValidDateSX(d, m, y)) {
      validDate = true;
      stringstream formatted;
      formatted << (d < 10 ? "0" : "") << d << "/" << (m < 10 ? "0" : "") << m
                << "/" << y;
      ngaySinh = formatted.str();
    } else {
      cout << "=> Loi: Ngay sinh khong hop le! Vui long nhap lai.\n";
    }
  } while (!validDate);

  cout << "Nhap so san pham da gia cong: ";
  cin >> soSanPham;
  cout << "Nhap don gia mot san pham: ";
  cin >> donGia;
}

void cNhanVienSX::Xuat() const {
  cout << "Ma NV: " << maNV << " | Ho ten: " << hoTen
       << " | Ngay sinh: " << ngaySinh << " | So SP: " << soSanPham
       << " | Don gia: " << fixed << setprecision(2) << donGia
       << " | Luong: " << TinhLuong() << endl;
}

int cNhanVienSX::getNamSinh() const { return stoi(ngaySinh.substr(6, 4)); }