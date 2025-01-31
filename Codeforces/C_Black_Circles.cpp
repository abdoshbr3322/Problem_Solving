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
   vll x(n), y(n);
   for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
   }
   ll xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
   ull distance = 1ll * (xs - xt) * (xs - xt) + 1ll * (ys - yt) * (ys - yt);
   // ull distance = pow((xs-xt), 2) + pow((ys-yt), 2);

   for (int i = 0; i < n; i++) {
      ull cur = 1ll * (x[i] - xt) * (x[i] - xt) + 1ll * (y[i] - yt) * (y[i] - yt);
      // ull cur = pow((x[i]-xt), 2) + pow((y[i]-yt), 2);
      if (cur <= distance) {
         cout << "NO\n";
         return;
      }
   }
   cout << "YES\n";
}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}
