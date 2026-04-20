#ifndef CLISTCANDIDATE_H
#define CLISTCANDIDATE_H

#include "cCandidate.h"
#include <vector>

class cListCandidate {
private:
  vector<cCandidate> candidates;

public:
  cListCandidate();
  void Input();
  void OutputAbove15() const;
  void OutputHighestScore() const;
  void SortDescending();
  void OutputAll() const;
};

#endif
