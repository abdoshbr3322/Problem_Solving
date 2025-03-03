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

vi prime_factors(int n) {
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


bool semi_prime(int n) {
   vi f = prime_factors(n);
   return (f.size() == 2 && f[0] != f[1]);
}

void solve() {
   int n; cin >> n;
   for (int i = 1; (i * 2) <= n; i++) {
      if (semi_prime(i) && semi_prime(n-i)) {
         // cout << i << ' ' << n - i << endl;
         cout << "YES\n";
         return;
      }
   }
   cout << "NO\n";
}


int main() {
   FreePalestine;
   // #ifndef ONLINE_JUDGE 
   //    freopen("input.txt", "r", stdin); 
   //    freopen("output.txt", "w", stdout); 
   // #endif 
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}
