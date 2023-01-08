long long int IncDecRec(long long int n) {
      if (n == 0)
            return 1;
      else {
            int rez = 0, p = 1;
            while (n > 0) {
                  int c = n % 10;
                  if (c % 2 == 0)
                        rez = rez + (c + 1) * p;
                  else 
                        rez = rez + (c - 1) * p;
                  p = p * 10;
                  n = n / 10;
            } return rez;
      }
}