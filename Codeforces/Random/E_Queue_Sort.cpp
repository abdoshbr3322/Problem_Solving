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
   int n; cin >> n;
   vi a(n); cin >> a;
   vi suffix_min(a);
   for (int i = n-2; i >= 0; i--) 
      suffix_min[i] = min(suffix_min[i], suffix_min[i+1]);
      
   int ans;
   int l = 0, r = n - 1;
   while (l <= r) {
      int mid = (l + r) /2;
      bool found = is_sorted(a.begin()+mid, a.end());
      if (found) {
         ans = mid;
         r = mid - 1;
      } else {
         l = mid + 1;
      }
   }
   for (int i = 0; i < ans; i++) {
      if (a[i] <= suffix_min[i+1]) {
         cout << -1 << endl;
         return;
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
