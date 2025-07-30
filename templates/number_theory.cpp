
vi prime_factors(int n) { // O(sqrt(n))
   vi res;
   for (int i = 2; 1ll * i * i <= n; i++) {
      while (n % i == 0) {
         n /= i;
         res.push_back(i);
      }
   }
   if (n != 1) res.push_back(n);
   return res;
}

vi get_divisors(int n) { // O(sqrt(n))
   vi res;
   for (int i = 1; 1ll * i * i <= n; i++) {
      if (n % i == 0) {
         res.push_back(i);
         if (1ll * i * i != n) res.push_back(n / i);
      }
   }
   return res;
}

vvi pre_divisors(int n) { // O(n . log(n))
   vvi res(n+1, vi());
   for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j += i) {
         res[j].push_back(i);
      }
   } 
   return res;
}


bool is_prime(int n) { // O(sqrt(n))
   if (n <= 1) return false;
   for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) return false;
   }
   return true;
}

const int MOD = 1e9+7;

int fast_power(int base, int pow) { // O(log(n))
   int res = 1;
   while(pow) {
      if (pow % 2) {
         res *= base;
         res %= MOD;
         pow--;
      } else {
         base *= base;
         base %= MOD;
         pow /= 2;
      }
   }
   return res;
}

int gcd(int a, int b) {
   if (a < b) swap(a, b);
   if (b == 0) return a;
   return gcd(b, a % b);
}

int lcm(int a, int b) {
   return (a / gcd(a, b)) * b;
}

int big_mod(string a, int b) {
   int ans = 0;
   int n = a.size();
   reverse(all(a));

   int power_10 = 1;
   for (int i = 0; i < n; i++) {
      int d = (a[i] - '0') % b;
      ans += (d * power_10) % b;
      ans %= b;
      power_10 *= 10;
      power_10 %= b;
   }

   return ans;
}
