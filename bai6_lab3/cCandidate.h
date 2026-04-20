#ifndef CCANDIDATE_H
#define CCANDIDATE_H

#include <iostream>
#include <string>

using namespace std;

class cCandidate {
private:
  string id;
  string name;
  string birthDate;
  float mathScore;
  float literatureScore;
  float englishScore;

public:
  cCandidate();
  void Input();
  void Output() const;
  float GetTotalScore() const;
  string GetName() const;
};

#endif
