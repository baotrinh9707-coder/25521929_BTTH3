#include "cDaGiac.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
  cDaGiac dg;

  cout << "--- KHOI TAO DA GIAC ---\n";
  dg.Nhap();

  cout << "\n--- THONG TIN DA GIAC ---\n";
  dg.Xuat();
  cout << "Chu vi: " << dg.TinhChuVi() << endl;
  cout << "Dien tich: " << dg.TinhDienTich() << endl;

  cout << "\n--- PHEP TINH TIEN ---\n";
  double dx, dy;
  cout << "Nhap vector tinh tien (dx dy): ";
  cin >> dx >> dy;
  dg.TinhTien(dx, dy);
  dg.Xuat();

  cout << "\n--- PHEP THU PHONG ---\n";
  double k;
  cout << "Nhap he so thu phong: ";
  cin >> k;
  dg.ThuPhong(k);
  dg.Xuat();

  cout << "\n--- PHEP QUAY ---\n";
  double goc;
  cout << "Nhap so do goc can quay theo chieu nguoc kim dong ho: ";
  cin >> goc;
  dg.Quay(goc);
  dg.Xuat();
  return 0;
}
