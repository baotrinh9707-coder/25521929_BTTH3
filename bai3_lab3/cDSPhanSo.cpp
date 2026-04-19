#include "cDSPhanSo.h"
#include <cmath>

cDSPhanSo::cDSPhanSo() { n = 0; }

bool cDSPhanSo::isPrime(int num) {
  if (num < 2)
    return false;
  for (int i = 2; i <= std::sqrt(num); i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

void cDSPhanSo::nhap() {
  std::cout << "Nhap so luong phan so: ";
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cout << "--- Nhap phan so thu " << i + 1 << " ---\n";
    ds[i].nhap();
  }
}

void cDSPhanSo::xuat() {
  for (int i = 0; i < n; i++) {
    ds[i].xuat();
    if (i < n - 1)
      std::cout << ", ";
  }
}

cPhanSo cDSPhanSo::tinhTong() {
  cPhanSo tong(0, 1);
  for (int i = 0; i < n; i++) {
    tong = tong.cong(ds[i]);
  }
  return tong;
}

cPhanSo cDSPhanSo::timMax() {
  if (n == 0)
    return cPhanSo(0, 1);
  cPhanSo max = ds[0];
  for (int i = 1; i < n; i++) {
    if (ds[i].soSanh(max) > 0) {
      max = ds[i];
    }
  }
  return max;
}

cPhanSo cDSPhanSo::timMin() {
  if (n == 0)
    return cPhanSo(0, 1);
  cPhanSo min = ds[0];
  for (int i = 1; i < n; i++) {
    if (ds[i].soSanh(min) < 0) {
      min = ds[i];
    }
  }
  return min;
}

bool cDSPhanSo::timTuSoNguyenToLonNhat(cPhanSo &kq) {
  bool found = false;
  int maxPrime = -1;

  for (int i = 0; i < n; i++) {
    int tu = ds[i].getTuSo();
    if (isPrime(tu)) {
      if (!found || tu > maxPrime) {
        maxPrime = tu;
        kq = ds[i];
        found = true;
      }
    }
  }
  return found;
}

void cDSPhanSo::sapXepTangDan() {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (ds[i].soSanh(ds[j]) > 0) {
        cPhanSo temp = ds[i];
        ds[i] = ds[j];
        ds[j] = temp;
      }
    }
  }
}

void cDSPhanSo::sapXepGiamDan() {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (ds[i].soSanh(ds[j]) < 0) {
        cPhanSo temp = ds[i];
        ds[i] = ds[j];
        ds[j] = temp;
      }
    }
  }
}
