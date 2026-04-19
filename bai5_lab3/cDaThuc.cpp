#include "cDaThuc.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

cDaThuc::cDaThuc() {
  n = 0;
  a = new double[1];
  a[0] = 0;
}

cDaThuc::cDaThuc(int bac) {
  if (bac < 0)
    bac = 0;
  n = bac;
  a = new double[n + 1];
  for (int i = 0; i <= n; i++) {
    a[i] = 0;
  }
}

cDaThuc::cDaThuc(const cDaThuc &other) {
  n = other.n;
  a = new double[n + 1];
  for (int i = 0; i <= n; i++) {
    a[i] = other.a[i];
  }
}

cDaThuc::~cDaThuc() { delete[] a; }

cDaThuc &cDaThuc::operator=(const cDaThuc &other) {
  if (this != &other) {
    delete[] a;
    n = other.n;
    a = new double[n + 1];
    for (int i = 0; i <= n; i++) {
      a[i] = other.a[i];
    }
  }
  return *this;
}

void cDaThuc::nhap() {
  do {
    cout << "Nhap bac cua da thuc: ";
    cin >> n;
    if (n < 0)
      cout << "Bac cua da thuc phai >= 0. Vui long nhap lai!" << endl;
  } while (n < 0);

  delete[] a;
  a = new double[n + 1];

  for (int i = n; i >= 0; i--) {
    cout << "Nhap he so cua x^" << i << ": ";
    cin >> a[i];
  }
}

void cDaThuc::xuat() const {
  if (n == 0 && a[0] == 0) {
    cout << "0" << endl;
    return;
  }

  bool first = true;
  for (int i = n; i >= 0; i--) {
    if (a[i] != 0) {
      if (a[i] > 0 && !first)
        cout << " + ";
      else if (a[i] < 0) {
        if (first)
          cout << "-";
        else
          cout << " - ";
      }

      double absVal = abs(a[i]);
      if (absVal != 1 || i == 0) {
        cout << absVal;
      }

      if (i > 0) {
        cout << "x";
        if (i > 1)
          cout << "^" << i;
      }
      first = false;
    }
  }
  if (first)
    cout << "0";
  cout << endl;
}

double cDaThuc::tinhGiaTri(double x) const {
  double result = 0;
  for (int i = 0; i <= n; i++) {
    result += a[i] * pow(x, i);
  }
  return result;
}

cDaThuc cDaThuc::cong(const cDaThuc &other) const {
  int maxBac = max(n, other.n);
  cDaThuc result(maxBac);

  for (int i = 0; i <= maxBac; i++) {
    double heSo1 = (i <= n) ? a[i] : 0;
    double heSo2 = (i <= other.n) ? other.a[i] : 0;
    result.a[i] = heSo1 + heSo2;
  }

  while (result.n > 0 && result.a[result.n] == 0) {
    result.n--;
  }

  return result;
}

cDaThuc cDaThuc::tru(const cDaThuc &other) const {
  int maxBac = max(n, other.n);
  cDaThuc result(maxBac);

  for (int i = 0; i <= maxBac; i++) {
    double heSo1 = (i <= n) ? a[i] : 0;
    double heSo2 = (i <= other.n) ? other.a[i] : 0;
    result.a[i] = heSo1 - heSo2;
  }

  while (result.n > 0 && result.a[result.n] == 0) {
    result.n--;
  }

  return result;
}
