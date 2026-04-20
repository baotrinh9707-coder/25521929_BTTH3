#pragma once
#include "cNhanVienSX.h"
#include <vector>

class cDSNhanVienSX {
private:
  vector<cNhanVienSX> ds;

public:
  cDSNhanVienSX();
  void Nhap();
  void Xuat() const;
  void XuatNVLuongThapNhat() const;
  double TinhTongLuong() const;
  void XuatNVLonTuoiNhat() const;
  void SapXepTangDanTheoLuong();
};