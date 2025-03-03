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

void solve() {
   ll n, k; cin >> n >> k;
   vll a(n); cin >> a;
   ll l = 0, r = n-1, ans = 0;
   while (l < r) {
      ll val = min(a[l], a[r]);
      int need = (val == a[l] ? 2 * val - 1 : 2 * val);
      if (k < need) break;
      a[l] -= val;
      k -= val;
      if (a[l] == 0) {
         ans++;
         l++;
      }
      if (k < val) break;
      a[r] -= val;
      k-= val;
      if (a[r] == 0) {
         ans++;
         r--;
      }
   }
   if (l == r && a[l] != 0) {
      a[l] -= min(a[l], k);
      if (a[l] == 0) ans++;
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
   cin >> t;
   while (t--) solve();
   return 0;
}
