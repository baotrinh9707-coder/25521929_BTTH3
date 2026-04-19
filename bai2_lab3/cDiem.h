#ifndef CDIEM_H
#define CDIEM_H

#include <cmath>
#include <iostream>

using namespace std;

const double PI = 3.14159265358979323846;

class cDiem {
private:
  double x, y;

public:
  cDiem(double _x = 0, double _y = 0) : x(_x), y(_y) {}

  double GetX() const { return x; }
  double GetY() const { return y; }

  void Nhap();
  void Xuat() const;
  double KhoangCach(const cDiem &d) const;
  void TinhTien(double dx, double dy);
  void Quay(double gocDo);
  void ThuPhong(double k);
};

#endif
