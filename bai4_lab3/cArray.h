#ifndef CARRAY_H
#define CARRAY_H

class cArray {
private:
  int *arr;
  int n;

  bool isPrime(int num) const;

public:
  cArray();
  cArray(int size);
  ~cArray();

  void createRandom(int size);
  void print() const;
  int countOccurrences(int x) const;
  bool isAscending() const;
  bool findMinOdd(int &minOdd) const;
  bool findMaxPrime(int &maxPrime) const;
  void sortAscending();
  void sortDescending();
};

#endif
