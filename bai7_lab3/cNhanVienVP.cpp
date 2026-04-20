#include "cNhanVienVP.h"
#include <sstream>

bool IsValidDateVP(int d, int m, int y) {
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

cNhanVienVP::cNhanVienVP() {
  maNV = "";
  hoTen = "";
  ngaySinh = "";
  luong = 0.0;
}

string cNhanVienVP::getMaNV() const { return maNV; }
void cNhanVienVP::setMaNV(string ma) { maNV = ma; }

string cNhanVienVP::getHoTen() const { return hoTen; }
void cNhanVienVP::setHoTen(string ten) { hoTen = ten; }

string cNhanVienVP::getNgaySinh() const { return ngaySinh; }
void cNhanVienVP::setNgaySinh(string ngay) { ngaySinh = ngay; }

double cNhanVienVP::getLuong() const { return luong; }
void cNhanVienVP::setLuong(double l) { luong = l; }

void cNhanVienVP::Nhap() {
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
    if (ss >> d >> m >> y && IsValidDateVP(d, m, y)) {
      validDate = true;
      stringstream formatted;
      formatted << (d < 10 ? "0" : "") << d << "/" << (m < 10 ? "0" : "") << m
                << "/" << y;
      ngaySinh = formatted.str();
    } else {
      cout << "=> Loi: Ngay sinh khong hop le! Vui long nhap lai.\n";
    }
  } while (!validDate);

  cout << "Nhap luong: ";
  cin >> luong;
}

void cNhanVienVP::Xuat() const {
  cout << "Ma NV: " << maNV << " | Ho ten: " << hoTen
       << " | Ngay sinh: " << ngaySinh << " | Luong: " << luong << endl;
}

int cNhanVienVP::getNamSinh() const { return stoi(ngaySinh.substr(6, 4)); }