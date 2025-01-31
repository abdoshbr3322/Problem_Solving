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

int make_unique(vi &a) {
   auto ip = unique(all(a));
   int n_size = distance(a.begin(), ip);
   a.resize(n_size);
   return n_size;
}

vvll prefix_sum_2d(vvi &a) {
   int n = a.size();
   int m = a[0].size();
   vvll prefix(n+1, vll(m+1, 0));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         prefix[i+1][j+1] += prefix[i+1][j] + a[i][j];
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         prefix[i+1][j+1] += prefix[i][j+1];
      }
   }

   return prefix;
}

ll rect_sum(int x1, int y1, int x2, int y2, vvll &p) {
   return (p[y2][x2] - p[y2][x1-1] - p[y1-1][x2] + p[y1-1][x1-1]);
}

void solve() {
   int n, q; cin >> n >> q;
   vvi a(n, vi(n, 0)); 
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         char c; cin >> c;
         a[i][j] = (c == '*');
      }
   }
   vvll prefix = prefix_sum_2d(a);
   while (q--) {
      int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
      cout << rect_sum(x1, y1, x2, y2, prefix) << endl;
   }
}

int main() {
   FreePalestine;
   int t; t = 1;
   // cin >> t;
   while (t--) solve();
   return 0;
}