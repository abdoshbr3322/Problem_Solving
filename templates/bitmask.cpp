
bool checkBit(int n, int k) {
   return (n >> k) & 1;
}

int toggleBit(int n, int k) {
   return (n ^ (1LL << k));
}

int bitOn(int n, int k) {
   return (n | (1LL << k));
}

int bitOff(int n, int k) {
   return (n & (~(1LL << k)));
}

bool checkPowerOfTwo(int n) {
   return __builtin_popcountll(n) == 1;
   // return (n & (n-1)) == 0;
}

int xorfromZeroToN(int n) {
   if (n % 4 == 0) return n;
   return n ^ xorfromZeroToN(n-1);
}

vvi getPrefixBit(vi a, int n) {
   vvi prefix_bit(64, vi(n+1));
   for (int bit = 0; bit < 64; bit++) {
      for (int i = 1; i <= n; i++) {
         prefix_bit[bit][i] = prefix_bit[bit][i-1] + checkBit(a[i-1], bit);
      }
   }
   return prefix_bit;
}

int prefixOr(int l, int r, vvi& prefix_bit) {
   int ans = 0;
   for (int bit = 0; bit < 64; bit++) {
      int sum = prefix_bit[bit][r] - prefix_bit[bit][l-1];
      if (sum) ans += (1LL << bit);
   }
   return ans;
}

int prefixAnd(int l, int r, vvi prefix_bit) {
   int ans = 0;
   for (int bit = 0; bit < 64; bit++) {
      int sum = prefix_bit[bit][r] - prefix_bit[bit][l-1];
      if (sum == (r-l+1)) ans += (1LL << bit);
   }
   return ans;
}