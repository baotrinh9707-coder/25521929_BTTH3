#pragma once
#include <iostream>

class cPhanSo {
private:
  int tuSo;
  int mauSo;

public:
  cPhanSo();
  cPhanSo(int tu, int mau);

  void nhap();
  void xuat();

  void rutGon();
  cPhanSo cong(cPhanSo b);

  int getTuSo();
  int getMauSo();

  int soSanh(cPhanSo b);
};
