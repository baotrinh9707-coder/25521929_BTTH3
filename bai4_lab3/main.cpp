#include "cArray.h"
#include <iostream>

using namespace std;

int main() {
  cArray arr;
  int n;

  cout << "--- CHUONG TRINH XU LY MANG MOT CHIEU ---" << endl;
  cout << "Nhap so luong phan tu muon tao ngau nhien (n): ";
  cin >> n;

  arr.createRandom(n);
  cout << "\n1. Mang ngau nhien vua tao: ";
  arr.print();

  int x;
  cout << "\n2. Nhap gia tri x can dem: ";
  cin >> x;
  cout << "   -> So lan xuat hien cua " << x
       << " trong mang la: " << arr.countOccurrences(x) << endl;

  cout << "\n3. Kiem tra mang tang dan: ";
  if (arr.isAscending()) {
    cout << "Mang dang sap xep tang dan." << endl;
  } else {
    cout << "Mang KHONG tang dan." << endl;
  }

  int minOdd;
  cout << "\n4. Tim phan tu le nho nhat: ";
  if (arr.findMinOdd(minOdd)) {
    cout << minOdd << endl;
  } else {
    cout << "Khong co phan tu le nao trong mang." << endl;
  }

  int maxPrime;
  cout << "\n5. Tim so nguyen to lon nhat: ";
  if (arr.findMaxPrime(maxPrime)) {
    cout << maxPrime << endl;
  } else {
    cout << "Khong co so nguyen to nao trong mang." << endl;
  }

  cout << "\n6. Sap xep mang tang dan..." << endl;
  arr.sortAscending();
  cout << "   -> Mang sau khi sap xep tang dan: ";
  arr.print();

  cout << "\n7. Sap xep mang giam dan..." << endl;
  arr.sortDescending();
  cout << "   -> Mang sau khi sap xep giam dan: ";
  arr.print();

  return 0;
}
