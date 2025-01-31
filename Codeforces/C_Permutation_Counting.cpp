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

   ll l = 1, r = 1e13;
   ll ans;
   while (l <= r) {
      ll mid = (l + r) / 2;
      ll k_ = k;
      ll s = n;
      bool ok = true;
      for (int i = 0; i < n; i++) {
         if (a[i] < mid) {
            k_ -= (mid - a[i]);
            s--;
         } else {
            if (a[i] == mid) s--;
         }
         if (k_ < 0) {
            ok = false;
            break;
         }
      }
      if (ok) {
         ans = mid + (mid-1) *(n-1) + min(n-1, k_+s);
         l = mid + 1;
      } else {
         r = mid - 1;
      }
   }
   cout << ans << endl;

}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}
