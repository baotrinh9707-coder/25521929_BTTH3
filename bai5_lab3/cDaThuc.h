#ifndef CDATHUC_H
#define CDATHUC_H

class cDaThuc {
private:
  int n;
  double *a;

public:
  cDaThuc();
  cDaThuc(int bac);

  cDaThuc(const cDaThuc &other);
  ~cDaThuc();

  cDaThuc &operator=(const cDaThuc &other);
  double tinhGiaTri(double x) const;

  void nhap();
  void xuat() const;

  cDaThuc cong(const cDaThuc &other) const;
  cDaThuc tru(const cDaThuc &other) const;
};

#endif
