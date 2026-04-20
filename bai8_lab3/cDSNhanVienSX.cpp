#include "cDSNhanVienSX.h"
#include <algorithm>
#include <iomanip>

cDSNhanVienSX::cDSNhanVienSX() {}

void cDSNhanVienSX::Nhap() {
  int n;
  cout << "Nhap so luong nhan vien san xuat: ";
  cin >> n;
  ds.resize(n);
  for (int i = 0; i < n; ++i) {
    cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---" << endl;
    ds[i].Nhap();
  }
}

void cDSNhanVienSX::Xuat() const {
  cout << "\n--- Danh sach nhan vien san xuat ---" << endl;
  for (const auto &nv : ds) {
    nv.Xuat();
  }
}

void cDSNhanVienSX::XuatNVLuongThapNhat() const {
  if (ds.empty())
    return;

  double minLuong = ds[0].TinhLuong();
  for (const auto &nv : ds) {
    if (nv.TinhLuong() < minLuong) {
      minLuong = nv.TinhLuong();
    }
  }

  cout << "\n--- Nhan vien co luong THAP NHAT (" << fixed << setprecision(2)
       << minLuong << ") ---" << endl;
  for (const auto &nv : ds) {
    if (nv.TinhLuong() == minLuong) {
      nv.Xuat();
    }
  }
}

double cDSNhanVienSX::TinhTongLuong() const {
  double tong = 0;
  for (const auto &nv : ds) {
    tong += nv.TinhLuong();
  }
  return tong;
}

void cDSNhanVienSX::XuatNVLonTuoiNhat() const {
  if (ds.empty())
    return;

  int minNamSinh = ds[0].getNamSinh();
  for (const auto &nv : ds) {
    if (nv.getNamSinh() < minNamSinh) {
      minNamSinh = nv.getNamSinh();
    }
  }

  cout << "\n--- Nhan vien LON TUOI NHAT (Sinh nam " << minNamSinh << ") ---"
       << endl;
  for (const auto &nv : ds) {
    if (nv.getNamSinh() == minNamSinh) {
      nv.Xuat();
    }
  }
}

void cDSNhanVienSX::SapXepTangDanTheoLuong() {
  sort(ds.begin(), ds.end(), [](const cNhanVienSX &a, const cNhanVienSX &b) {
    return a.TinhLuong() < b.TinhLuong();
  });
}