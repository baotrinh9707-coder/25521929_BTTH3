#pragma once
#include <iostream>
#include <string>

using namespace std;

class cNhanVienSX {
private:
  string maNV;
  string hoTen;
  string ngaySinh;
  int soSanPham;
  double donGia;

public:
  cNhanVienSX();

  string getMaNV() const;
  void setMaNV(string ma);

  string getHoTen() const;
  void setHoTen(string ten);

  string getNgaySinh() const;
  void setNgaySinh(string ngay);

  int getSoSanPham() const;
  void setSoSanPham(int so);

  double getDonGia() const;
  void setDonGia(double gia);

  void Nhap();
  void Xuat() const;
  double TinhLuong() const;
  int getNamSinh() const;
};