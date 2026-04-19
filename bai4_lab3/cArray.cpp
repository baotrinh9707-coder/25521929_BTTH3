#include "cArray.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

cArray::cArray() {
  arr = nullptr;
  n = 0;
}

cArray::cArray(int size) {
  n = size;
  arr = new int[n];
}

cArray::~cArray() {
  if (arr != nullptr) {
    delete[] arr;
  }
}

void cArray::createRandom(int size) {
  if (arr != nullptr) {
    delete[] arr;
  }
  n = size;
  arr = new int[n];
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
}

void cArray::print() const {
  if (n == 0) {
    cout << "Mang rong." << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int cArray::countOccurrences(int x) const {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      count++;
    }
  }
  return count;
}

bool cArray::isAscending() const {
  if (n <= 1)
    return true;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }
  return true;
}

bool cArray::findMinOdd(int &minOdd) const {
  bool found = false;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 != 0) {
      if (!found) {
        minOdd = arr[i];
        found = true;
      } else if (arr[i] < minOdd) {
        minOdd = arr[i];
      }
    }
  }
  return found;
}

bool cArray::isPrime(int num) const {
  if (num < 2)
    return false;
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

bool cArray::findMaxPrime(int &maxPrime) const {
  bool found = false;
  for (int i = 0; i < n; i++) {
    if (isPrime(arr[i])) {
      if (!found) {
        maxPrime = arr[i];
        found = true;
      } else if (arr[i] > maxPrime) {
        maxPrime = arr[i];
      }
    }
  }
  return found;
}

void cArray::sortAscending() {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

void cArray::sortDescending() {
  for (int i = 0; i < n - 1; i++) {
    int max_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] > arr[max_idx]) {
        max_idx = j;
      }
    }
    int temp = arr[max_idx];
    arr[max_idx] = arr[i];
    arr[i] = temp;
  }
}
