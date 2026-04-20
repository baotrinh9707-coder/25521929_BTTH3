#pragma once
#include <iostream>
#include <string>

using namespace std;

class cNhanVienVP {
private:
  string maNV;
  string hoTen;
  string ngaySinh;
  double luong;

public:
  cNhanVienVP();

  string getMaNV() const;
  void setMaNV(string ma);

  string getHoTen() const;
  void setHoTen(string ten);

  string getNgaySinh() const;
  void setNgaySinh(string ngay);

  double getLuong() const;
  void setLuong(double l);

  void Nhap();
  void Xuat() const;
  int getNamSinh() const;
};