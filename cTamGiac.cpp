#include "cTamGiac.h"

void cTamGiac::Nhap() {
    do {
        cout << "Nhap toa do dinh A (x y): "; A.Nhap();
        cout << "Nhap toa do dinh B (x y): "; B.Nhap();
        cout << "Nhap toa do dinh C (x y): "; C.Nhap();
        if (!HopLe()) {
            cout << "3 diem khong tao thanh tam giac! Vui long nhap lai.\n";
        }
    } while (!HopLe());
}

void cTamGiac::Xuat() const {
    cout << "Tam giac tao boi 3 dinh: A"; A.Xuat();
    cout << ", B"; B.Xuat();
    cout << ", C"; C.Xuat();
    cout << endl;
}

bool cTamGiac::HopLe() const {
    double a = B.KhoangCach(C);
    double b = A.KhoangCach(C);
    double c = A.KhoangCach(B);
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double cTamGiac::TinhChuVi() const {
    double a = B.KhoangCach(C);
    double b = A.KhoangCach(C);
    double c = A.KhoangCach(B);
    return a + b + c;
}

double cTamGiac::TinhDienTich() const {
    double a = B.KhoangCach(C);
    double b = A.KhoangCach(C);
    double c = A.KhoangCach(B);
    double p = (a + b + c) / 2.0; 
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

string cTamGiac::KiemTraLoai() const {
    double a = B.KhoangCach(C);
    double b = A.KhoangCach(C);
    double c = A.KhoangCach(B);

    bool deu = isEqual(a, b) && isEqual(b, c);
    bool can = isEqual(a, b) || isEqual(b, c) || isEqual(a, c);
    bool vuong = isEqual(a*a + b*b, c*c) || isEqual(a*a + c*c, b*b) || isEqual(b*b + c*c, a*a);

    if (deu) return "Tam giac deu";
    if (vuong && can) return "Tam giac vuong can";
    if (vuong) return "Tam giac vuong";
    if (can) return "Tam giac can";
    return "Tam giac thuong";
}

void cTamGiac::TinhTien(double dx, double dy) {
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}

void cTamGiac::Quay(double gocDo) {
    A.Quay(gocDo);
    B.Quay(gocDo);
    C.Quay(gocDo);
}

void cTamGiac::ThuPhong(double k) {
    A.ThuPhong(k);
    B.ThuPhong(k);
    C.ThuPhong(k);
}
