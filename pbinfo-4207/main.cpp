long long SumProdRec(int n) {
  if(n > 1) return n * (n - 1) + SumProdRec(n - 1);
  return 0;
}