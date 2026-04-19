#include "cPhanSo.h"
#include <cmath>

// Hàm tìm UCLN
int UCLN(int a, int b) {
  a = std::abs(a);
  b = std::abs(b);
  if (a == 0 || b == 0)
    return a + b;
  while (a != b) {
    if (a > b)
      a -= b;
    else
      b -= a;
  }
  return a;
}

cPhanSo::cPhanSo() {
  tuSo = 0;
  mauSo = 1;
}

cPhanSo::cPhanSo(int tu, int mau) {
  tuSo = tu;
  mauSo = mau;
}

void cPhanSo::nhap() {
  std::cout << "Nhap tu so: ";
  std::cin >> tuSo;
  do {
    std::cout << "Nhap mau so (khac 0): ";
    std::cin >> mauSo;
    if (mauSo == 0) {
      std::cout << "Mau so phai khac 0. Vui long nhap lai.\n";
    }
  } while (mauSo == 0);
}

void cPhanSo::xuat() {
  rutGon();
  if (mauSo == 1) {
    std::cout << tuSo;
  } else if (tuSo == 0) {
    std::cout << 0;
  } else {
    std::cout << tuSo << "/" << mauSo;
  }
}

void cPhanSo::rutGon() {
  int ucln = UCLN(tuSo, mauSo);
  if (ucln != 0) {
    tuSo /= ucln;
    mauSo /= ucln;
  }
  if (mauSo < 0) {
    tuSo = -tuSo;
    mauSo = -mauSo;
  }
}

cPhanSo cPhanSo::cong(cPhanSo b) {
  cPhanSo kq;
  kq.tuSo = tuSo * b.mauSo + b.tuSo * mauSo;
  kq.mauSo = mauSo * b.mauSo;
  kq.rutGon();
  return kq;
}

int cPhanSo::getTuSo() { return tuSo; }

int cPhanSo::getMauSo() { return mauSo; }

int cPhanSo::soSanh(cPhanSo b) {
  this->rutGon();
  b.rutGon();
  int left = this->tuSo * b.mauSo;
  int right = b.tuSo * this->mauSo;
  if (left > right)
    return 1;
  if (left < right)
    return -1;
  return 0;
}
