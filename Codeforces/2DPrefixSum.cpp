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

void prefix_sum(vi &a);
void partialSum(vi &a, int l, int r, int v);
int make_unique(vi &a);

void solve() {
   int n, m; cin >> n >> m;
   vvll a(n, vll(m)); cin >> a;
   for (int i = 0; i < n; i++) {
      for (int j = 1; j < m; j++) {
         a[i][j] = a[i][j] + a[i][j-1];
      }
   }
   for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
         a[i][j] = a[i][j] + a[i-1][j];
      }
   }
   
   int q; cin >> q;
   while (q--) {
      int l1, r1, l2, r2; cin >> l1  >> r1 >> l2 >> r2;

      // 0 Based 
      l1--, r1--, l2--, r2--;

      ll sum = a[l2][r2];
      if (l1 > 0)
         sum -= a[l1-1][r2];
      if (r1 > 0)
         sum -= a[l2][r1-1];
      if (l1 > 0 && r1 > 0)
         sum += a[l1-1][r1-1];
      cout << sum << endl;
   }
}


int main() {
   FreePalestine;
   int t; t = 1;
   // cin >> t;
   while (t--) solve();
   return 0;
}

// 2D array with vector
// vvi a(n, vector<int>(n));
