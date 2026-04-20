#include "cDSNhanVienVP.h"
#include <algorithm>

cDSNhanVienVP::cDSNhanVienVP() {}

void cDSNhanVienVP::Nhap() {
  int n;
  cout << "Nhap so luong nhan vien van phong: ";
  cin >> n;
  ds.resize(n);
  for (int i = 0; i < n; ++i) {
    cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---" << endl;
    ds[i].Nhap();
  }
}

void cDSNhanVienVP::Xuat() const {
  cout << "\n--- Danh sach nhan vien van phong ---" << endl;
  for (const auto &nv : ds) {
    nv.Xuat();
  }
}

void cDSNhanVienVP::XuatNVLuongCaoNhat() const {
  if (ds.empty())
    return;

  double maxLuong = ds[0].getLuong();
  for (const auto &nv : ds) {
    if (nv.getLuong() > maxLuong) {
      maxLuong = nv.getLuong();
    }
  }

  cout << "\n--- Nhan vien co luong cao nhat (" << maxLuong << ") ---" << endl;
  for (const auto &nv : ds) {
    if (nv.getLuong() == maxLuong) {
      nv.Xuat();
    }
  }
}

double cDSNhanVienVP::TinhTongLuong() const {
  double tong = 0;
  for (const auto &nv : ds) {
    tong += nv.getLuong();
  }
  return tong;
}

void cDSNhanVienVP::XuatNVLonTuoiNhat() const {
  if (ds.empty())
    return;

  int minNamSinh = ds[0].getNamSinh();
  for (const auto &nv : ds) {
    if (nv.getNamSinh() < minNamSinh) {
      minNamSinh = nv.getNamSinh();
    }
  }

  cout << "\n--- Nhan vien lon tuoi nhat (Sinh nam " << minNamSinh << ") ---"
       << endl;
  for (const auto &nv : ds) {
    if (nv.getNamSinh() == minNamSinh) {
      nv.Xuat();
    }
  }
}

void cDSNhanVienVP::SapXepTangDanTheoLuong() {
  sort(ds.begin(), ds.end(), [](const cNhanVienVP &a, const cNhanVienVP &b) {
    return a.getLuong() < b.getLuong();
  });
}