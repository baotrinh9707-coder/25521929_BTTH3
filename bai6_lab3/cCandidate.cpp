#include "cCandidate.h"
#include <sstream>

bool IsValidDate(int d, int m, int y) {
  if (y < 1900 || y > 2100)
    return false;
  if (m < 1 || m > 12)
    return false;

  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
    daysInMonth[2] = 29;
  }

  return d > 0 && d <= daysInMonth[m];
}

cCandidate::cCandidate() {
  id = "";
  name = "";
  birthDate = "";
  mathScore = 0;
  literatureScore = 0;
  englishScore = 0;
}

void cCandidate::Input() {
  cout << "Nhap ma thi sinh: ";
  cin >> id;
  cin.ignore();
  cout << "Nhap ten thi sinh: ";
  getline(cin, name);

  bool validDate = false;
  do {
    cout << "Nhap ngay thang nam sinh (dd/mm/yyyy): ";
    string tempInput;
    getline(cin, tempInput);
    for (char &c : tempInput) {
      if (c == '/' || c == '-')
        c = ' ';
    }

    int d, m, y;
    stringstream ss(tempInput);

    if (ss >> d >> m >> y && IsValidDate(d, m, y)) {
      validDate = true;
      stringstream formatted;
      formatted << (d < 10 ? "0" : "") << d << "/" << (m < 10 ? "0" : "") << m
                << "/" << y;
      birthDate = formatted.str();
    } else {
      cout << "=> Loi: Ngay thang nam khong hop le! Vui long nhap lai.\n";
    }
  } while (!validDate);

  cout << "Nhap diem Toan: ";
  cin >> mathScore;
  cout << "Nhap diem Van: ";
  cin >> literatureScore;
  cout << "Nhap diem Anh: ";
  cin >> englishScore;
}

void cCandidate::Output() const {
  cout << "Ma: " << id << ", Ten: " << name << ", NTNS: " << birthDate
       << ", Toan: " << mathScore << ", Van: " << literatureScore
       << ", Anh: " << englishScore << ", Tong: " << GetTotalScore() << endl;
}

float cCandidate::GetTotalScore() const {
  return mathScore + literatureScore + englishScore;
}

string cCandidate::GetName() const { return name; }