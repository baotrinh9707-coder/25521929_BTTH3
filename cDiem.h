#ifndef CDIEM_H
#define CDIEM_H

#include <bits/stdc++.h>

using namespace std;

const double EPSILON = 1e-5;
const double PI = 3.14159265358979323846;

bool isEqual(double a, double b);

class cDiem {
private:
    double x, y;

public:
    cDiem(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    void Nhap();

    void Xuat() const;

    double KhoangCach(const cDiem& d) const;

    void TinhTien(double dx, double dy);

    void Quay(double gocDo);

    void ThuPhong(double k);
};

#endif
