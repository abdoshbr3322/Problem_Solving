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
#define int ll

const int MOD = 998244353;

ll fact(ll n) {
   if (n == 0) return 1;
   return (n * fact(n-1)) % MOD;
}

void solve() {
   string s; cin >> s;
   int n = s.size();

   int ans = 0, ways = 1;
   int cnt = 0;
   for (int i = 1; i < n; i++) {
      if (s[i] == s[i-1]) {
         cnt++;
         ans++;
      }
      if (s[i] != s[i-1] || i == n-1) {
         ways *= (cnt + 1);
         ways %= MOD;
         cnt = 0;
      }
   }
   ways *= fact(ans);
   ways %= MOD;
   cout << ans << ' ' << ways << endl;
}


signed main() {
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
