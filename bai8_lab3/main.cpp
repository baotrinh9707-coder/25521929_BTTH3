#include "cDSNhanVienSX.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  cout << fixed << setprecision(2);

  cDSNhanVienSX congTy;

  congTy.Nhap();
  congTy.Xuat();

  congTy.XuatNVLuongThapNhat();

  cout << "\n-> Tong luong cong ty phai tra cho khoi San Xuat: "
       << congTy.TinhTongLuong() << endl;

  congTy.XuatNVLonTuoiNhat();

  cout << "\n--- Danh sach SAU KHI SAP XEP TANG DAN theo luong ---" << endl;
  congTy.SapXepTangDanTheoLuong();
  congTy.Xuat();

  return 0;
}