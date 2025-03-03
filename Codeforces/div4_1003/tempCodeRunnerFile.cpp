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
   ll n, m; cin >> n >> m;
   vll a(n), b(m); cin >> a >> b;
   sort(all(b));
   int cnt = 0;
   for (int i = 0; i < n; i++) {
      auto l = b.begin();
      if (i > 0) {
         l = lower_bound(all(b), a[i] + a[i-1]);
      }
      if (l != b.end()) {
         bool ok1 = true;
         if (i > 0) {
            ok1 = ((*l - a[i]) >= a[i-1]);
         }
         bool ok2 = true;
         if (i < n-1) {
            ok2 = ((*l - a[i]) <= a[i+1]);
         }
         if (ok1 && ok2) {
            a[i] =  *l - a[i];
            cnt++;
         }
      }
   }
   if (cnt > 0) {
      cout << (is_sorted(all(a)) ? "YES\n" : "NO\n");
   } else {
      cout << "NO\n";
   }
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
