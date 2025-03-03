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

const ll MOD = 1e9+7;
ll fast_power(ll base, ll pow) { // O(log(n))
   ll res = 1;
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

void solve() {
   int l, r, k; cin >> l >> r >> k;
   int b = ceil(10.0 / k) - 1;

   ll ans = 0;
   ans = ((fast_power(b+1, r) - fast_power(b+1, l) + MOD) % MOD);
   cout << ans << endl;

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
