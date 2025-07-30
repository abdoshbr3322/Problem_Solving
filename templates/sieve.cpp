vector<int> sieve(int n) { // O (n . log(n))
   vector<int> divide(n+1);
   vector<int> primes;
   vector<bool> is_prime(n+1, true);
   is_prime[0] = is_prime[1] = false;
   for (int i = 2; i <= n; i++) {
      if (is_prime[i]) {
         primes.push_back(i);
         divide[i] = i;
         for (int j = 2 * i; j <= n; j+=i) {
            is_prime[j] = false;
            if (divide[j] == 0) {
               divide[j] = i;
            }
         }
      }
   }
   return divide;
}


vector<int> prime_factors_sieve(int n, vector<int>& divide) { // O(log(n))
   vector<int> res;
   while (n != 1) {
      int p = divide[n];
      res.push_back(p);
      n /= p;
   }
   return res;
}