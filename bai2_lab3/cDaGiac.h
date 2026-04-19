#ifndef CDAGIAC_H
#define CDAGIAC_H

#include "cDiem.h"

class cDaGiac {
private:
  int n;
  cDiem *dinh;

public:
  cDaGiac();
  ~cDaGiac();

  void Nhap();
  void Xuat() const;
  double TinhChuVi() const;
  double TinhDienTich() const;
  void TinhTien(double dx, double dy);
  void Quay(double gocDo);
  void ThuPhong(double k);
};

#endif
