#include "cListCandidate.h"
#include <iostream>

using namespace std;

int main() {
  cListCandidate list;

  list.Input();

  list.OutputAbove15();

  list.OutputHighestScore();

  cout << "\n--- Tien hanh sap xep danh sach giam dan theo tong diem ---"
       << endl;
  list.SortDescending();
  list.OutputAll();

  return 0;
}
