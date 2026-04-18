#include <bits/stdc++.h>
#include "cDiem.h"
#include "cTamGiac.h"

using namespace std;

int main() {
    cTamGiac tg;
    
    cout << "--- Nhap thong tin tam giac ---\n";
    tg.Nhap();
    
    cout << "\n--- Ket qua khoi tao ---\n";
    tg.Xuat();
    cout << "Loai tam giac: " << tg.KiemTraLoai() << endl;
    cout << "Chu vi: " << tg.TinhChuVi() << endl;
    cout << "Dien tich: " << tg.TinhDienTich() << endl;

    cout << "\n--- Thuc hien cac phep bien doi ---\n";
    
    double x, y; 
    cout << "Nhap vector can tinh tien (x y): ";
    cin >> x >> y;
    cout << "1. Tinh tien vector (" << x << ", " << y << "):\n";
    tg.TinhTien(x, y);
    tg.Xuat();

    double z; 
    cout << "Nhap do phong to: ";
    cin >> z;
    cout << "2. Phong to " << z << " lan:\n";
    tg.ThuPhong(z); 
    tg.Xuat();

    
    double u; 
    cout << "Nhap so do goc can quay theo chieu nguoc kim dong ho: ";
    cin >> u;
    cout << "3. Quay " << u << " do nguoc chieu kim dong ho:\n";
    tg.Quay(u);
    tg.Xuat();

    return 0;
}