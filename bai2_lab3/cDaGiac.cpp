#include "cDaGiac.h"

cDaGiac::cDaGiac() {
  n = 0;
  dinh = nullptr;
}

cDaGiac::~cDaGiac() {
  if (dinh != nullptr) {
    delete[] dinh;
  }
}

void cDaGiac::Nhap() {
  do {
    do {
      cout << "Nhap so dinh cua da giac (n >= 3): ";
      cin >> n;
    } while (n < 3);

    if (dinh != nullptr)
      delete[] dinh;
    dinh = new cDiem[n];

    for (int i = 0; i < n; i++) {
      cout << "Nhap toa do dinh " << i + 1 << " (x y): ";
      dinh[i].Nhap();
    }

    if (TinhDienTich() == 0) {
      cout << "Loi: Cac dinh bi trung hoac thang hang (Dien tich = 0)! Vui "
              "long nhap lai.\n\n";
    }

  } while (TinhDienTich() == 0);
}

void cDaGiac::Xuat() const {
  cout << "Da giac co " << n << " dinh: ";
  for (int i = 0; i < n; i++) {
    dinh[i].Xuat();
    if (i < n - 1)
      cout << " - ";
  }
  cout << endl;
}

double cDaGiac::TinhChuVi() const {
  if (n < 3)
    return 0;
  double chuVi = 0;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    chuVi += dinh[i].KhoangCach(dinh[j]);
  }
  return chuVi;
}

double cDaGiac::TinhDienTich() const {
  if (n < 3)
    return 0;
  double dienTich = 0;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    dienTich +=
        (dinh[i].GetX() * dinh[j].GetY()) - (dinh[j].GetX() * dinh[i].GetY());
  }
  return abs(dienTich) / 2.0;
}

void cDaGiac::TinhTien(double dx, double dy) {
  for (int i = 0; i < n; i++) {
    dinh[i].TinhTien(dx, dy);
  }
}

void cDaGiac::Quay(double gocDo) {
  for (int i = 0; i < n; i++) {
    dinh[i].Quay(gocDo);
  }
}

void cDaGiac::ThuPhong(double k) {
  for (int i = 0; i < n; i++) {
    dinh[i].ThuPhong(k);
  }
}
