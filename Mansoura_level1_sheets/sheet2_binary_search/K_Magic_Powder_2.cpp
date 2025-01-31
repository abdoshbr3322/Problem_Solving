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

vi prefix_sum(vi &a) {
   int n = a.size();
   vi prefix(n+1, 0);
   for (int i = 0; i < a.size(); i++) {
      prefix[i+1] += a[i] + prefix[i];
   }
   return prefix;
}

void solve() {
   ll n, k; cin >> n >> k; 
   vll a(n); cin >> a;
   vll b(n); cin >> b;
   
   ll ans;
   ll l = 0, r = 2e9;
   while (l <= r) {
      ll mid = (l + r) / 2;
      ll k_ = k;
      bool found = true;
      for (int i = 0; i < n; i++) {
         if(b[i] < (mid * a[i])) {
            ll x = a[i] * mid - b[i];
            if (x <= k_) {
               k_ -= x;
               continue;
            }
            found = false;
         }
      }
      if (found) {
         ans = mid;
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
   // cin >> t;
   while (t--) solve();
   return 0;
}