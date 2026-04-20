#include "cDSNhanVienVP.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  cout << fixed << setprecision(2);

  cDSNhanVienVP congTy;

  congTy.Nhap();
  congTy.Xuat();

  congTy.XuatNVLuongCaoNhat();

  cout << "\n-> Tong luong cong ty phai tra: " << congTy.TinhTongLuong()
       << endl;

  congTy.XuatNVLonTuoiNhat();

  cout << "\n--- Sau khi sap xep tang dan theo luong ---" << endl;
  congTy.SapXepTangDanTheoLuong();
  congTy.Xuat();

  return 0;
}