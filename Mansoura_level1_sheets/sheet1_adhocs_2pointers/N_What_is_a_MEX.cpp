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

   vi freq(2e5+1);
   int l = 0, r = 0;
   int mx = 0, cnt = 0, ans = INT_MIN, cur_mx = 0, cnt_2 = 0;
   while (r < n) {
      freq[a[r]]++;
      while (freq[a[r]] > 1) {
         freq[a[l]]--;
         l++;
         cnt = 0;
         cur_mx = 0;
         cnt_2 = 0;
      }
      cur_mx = max(cur_mx, a[r]);
      if (a[r] <= mx) cnt++;
      if (a[r] <= cur_mx) cnt_2++;
      if (cnt_2 == cur_mx + 1) {
         mx = max(cur_mx, mx);

      }
      else if (cnt == mx) {
         ans = max(ans, r- l + 1);
      }
      else if (cnt == mx + 1) {
         mx++;
         ans = r- l + 1;
      }
      
      r++;
   }
   cout << ans << endl;
}


signed main() {
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
