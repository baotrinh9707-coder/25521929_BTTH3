#pragma once
#include "cPhanSo.h"

class cDSPhanSo {
private:
  cPhanSo ds[100];
  int n;

  bool isPrime(int num);

public:
  cDSPhanSo();

  void nhap();
  void xuat();

  cPhanSo tinhTong();
  cPhanSo timMax();
  cPhanSo timMin();

  bool timTuSoNguyenToLonNhat(cPhanSo &kq);

  void sapXepTangDan();
  void sapXepGiamDan();
};
