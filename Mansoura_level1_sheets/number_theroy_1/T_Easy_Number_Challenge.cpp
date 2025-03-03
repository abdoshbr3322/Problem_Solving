// بسم الله الرحمن الرحيم

#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>
#include <string>
#include <vector>
#include <array>
#include <set>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <cmath>
using namespace std;

template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
#define FreePalestine                       \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);                    \
   cout.tie(NULL)
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<long long>
#define vvll vector<vll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define float double
#define all(a) a.begin(), a.end()
#define all_r(a) a.rbegin(), a.rend()
#define sum_a(n) n *(n + 1) / 2


const int MOD = 1073741824;

vector<int> sieve(int n) {
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

int d(int n, vector<int>& divide) {
   if (n == 1) return 1;
   int res = 1;
   int prev = 0, cnt = 1;
   while (n != 1) {
      int p = divide[n];
      if (p == prev) cnt++;
      else if (prev != 0) {
         res *= ++cnt;
         cnt = 1;
      }

      prev = p;
      n /= p;
   }
   res *= ++cnt;
   return res;
}


void solve() {
   int a, b, c; cin >> a >> b >> c;
   vi divide = sieve(1e6);
   int ans = 0;
   for (int i = 1; i <= a; i++) {
      for (int j = 1; j <= b; j++) {
         for (int k = 1; k <= c; k++) {
            ans += d(i * j * k, divide);
            ans %= MOD;
         }
      }
   }
   cout << ans << endl;
}


int main() {
   FreePalestine;
   // #ifndef ONLINE_JUDGE 
   //    freopen("input.txt", "r", stdin); 
   //    freopen("output.txt", "w", stdout); 
   // #endif 
   int t; t = 1;
   // cin >> t;
   while (t--) solve();
   return 0;
}
