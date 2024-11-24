bool FCrescRec(int32_t n) {
  if(n % 10 > n / 10 % 10 && n > 9) return 0;
  if(n > 99) return FCrescRec(n / 10);
  return 1;
}
