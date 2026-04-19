#include "cDaThuc.h"
#include <iostream>

using namespace std;

int main() {
  cDaThuc P, Q;

  cout << "=== KHOI TAO VA NHAP DA THUC P(x) ===" << endl;
  P.nhap();
  cout << "-> Da thuc P(x) = ";
  P.xuat();

  cout << "\n=== KHOI TAO VA NHAP DA THUC Q(x) ===" << endl;
  Q.nhap();
  cout << "-> Da thuc Q(x) = ";
  Q.xuat();

  double x;
  cout << "\n=== TINH GIA TRI DA THUC P(x) ===" << endl;
  cout << "Nhap gia tri x: ";
  cin >> x;
  cout << "-> P(" << x << ") = " << P.tinhGiaTri(x) << endl;

  cout << "\n=== CONG / TRU HAI DA THUC ===" << endl;
  cDaThuc sum = P.cong(Q);
  cout << "-> Tong hai da thuc: P(x) + Q(x) = ";
  sum.xuat();

  cDaThuc diff = P.tru(Q);
  cout << "-> Hieu hai da thuc: P(x) - Q(x) = ";
  diff.xuat();

  return 0;
}
