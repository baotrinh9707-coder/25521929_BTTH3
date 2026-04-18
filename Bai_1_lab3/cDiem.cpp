#include "cDiem.h"

bool isEqual(double a, double b) {
    return abs(a - b) < EPSILON;
}

void cDiem::Nhap() {
    cin >> x >> y;
}

void cDiem::Xuat() const {
    cout << "(" << x << ", " << y << ")";
}

double cDiem::KhoangCach(const cDiem& d) const {
    return sqrt((x - d.x) * (x - d.x) + (y - d.y) * (y - d.y));
}

void cDiem::TinhTien(double dx, double dy) {
    x += dx;
    y += dy;
}

void cDiem::Quay(double gocDo) {
    double rad = gocDo * PI / 180.0;
    double newX = x * cos(rad) - y * sin(rad);
    double newY = x * sin(rad) + y * cos(rad);
    x = newX;
    y = newY;
}

void cDiem::ThuPhong(double k) {
    x *= k;
    y *= k;
}
