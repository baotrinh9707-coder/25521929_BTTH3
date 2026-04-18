#ifndef CTAMGIAC_H
#define CTAMGIAC_H

#include "cDiem.h"
#include <string>

class cTamGiac {
private:
    cDiem A, B, C;

public:
    cTamGiac() {}
    
    ~cTamGiac() {}

    void Nhap();

    void Xuat() const;

    bool HopLe() const;

    double TinhChuVi() const;

    double TinhDienTich() const;

    string KiemTraLoai() const;

    void TinhTien(double dx, double dy);

    void Quay(double gocDo);

    void ThuPhong(double k);
};

#endif
