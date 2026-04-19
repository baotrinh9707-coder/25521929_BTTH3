#include "cDSPhanSo.h"
#include <iostream>

int main() {
  cDSPhanSo ds;

  std::cout << "--- NHAP DANH SACH PHAN SO ---\n";
  ds.nhap();

  std::cout << "\nDanh sach phan so vua nhap: ";
  ds.xuat();
  std::cout << "\n";

  std::cout << "\n1. Tong cac phan so la: ";
  cPhanSo tong = ds.tinhTong();
  tong.xuat();
  std::cout << std::endl;

  std::cout << "2. Phan so lon nhat la: ";
  cPhanSo max = ds.timMax();
  max.xuat();
  std::cout << std::endl;

  std::cout << "3. Phan so nho nhat la: ";
  cPhanSo min = ds.timMin();
  min.xuat();
  std::cout << std::endl;

  std::cout << "4. Phan so co tu la so nguyen to lon nhat: ";
  cPhanSo kq;
  if (ds.timTuSoNguyenToLonNhat(kq)) {
    kq.xuat();
  } else {
    std::cout << "Khong co phan so nao co tu la so nguyen to.";
  }
  std::cout << std::endl;

  std::cout << "5. Danh sach sau khi sap xep tang dan:\n";
  ds.sapXepTangDan();
  ds.xuat();
  std::cout << "\n";

  std::cout << "6. Danh sach sau khi sap xep giam dan:\n";
  ds.sapXepGiamDan();
  ds.xuat();
  std::cout << "\n";

  return 0;
}
