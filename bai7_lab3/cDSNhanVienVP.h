#pragma once
#include "cNhanVienVP.h"
#include <vector>

class cDSNhanVienVP {
private:
  vector<cNhanVienVP> ds;

public:
  cDSNhanVienVP();
  void Nhap();
  void Xuat() const;
  void XuatNVLuongCaoNhat() const;
  double TinhTongLuong() const;
  void XuatNVLonTuoiNhat() const;
  void SapXepTangDanTheoLuong();
};