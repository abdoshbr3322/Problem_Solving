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

// for 1 based
ll rect_sum(int x1, int y1, int x2, int y2, vvi &p) {
   return (p[x2][y2] - p[x2][y1-1] - p[x1-1][y2] + p[x1-1][y1-1]);
}

void solve() {
   int n, m, a, b; cin >> n >> m >> a >> b;
   string s; cin >> s;
   vector<vector<char>> grid(n, vector<char>(m)); cin >> grid;
   
   vi need(26);
   for (char c : s) {
      need[c-'a']++;
   }

   vector<vvi> prefix(26, vvi(n+1, vi(m+1, 0)));
   for (int i = 0; i < 26; i++) {
      for (int j = 0; j < n; j++) {
         for (int k = 0; k < m ;k++) {
            if (grid[j][k] == (i+'a')) prefix[i][j+1][k+1] = 1;
         }
      }
   }

   for (int i = 0; i < 26; i++) {
      for (int j = 1; j <= n; j++) {
         for (int k = 1; k <= m; k++) {
            prefix[i][j][k] += prefix[i][j][k-1];
         }
      }
      for (int j = 1; j <= n; j++) {
         for (int k = 1; k <= m; k++) {
            prefix[i][j][k] += prefix[i][j-1][k];
         }
      }
   }
   int ans = 0;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {

         int can_1 = INT_MAX, can_2 = INT_MAX;
         bool can_1_try = ((a + i) <= n && (b + j) <= m);
         bool can_2_try = ((a + j) <= m && (b + i) <= n);

         if (!can_1_try) can_1 = 0;
         if (!can_2_try) can_2 = 0;

         for (int k = 0; k < 26; k++) {
            if (need[k] == 0) continue;

            if (can_1_try) {
               int cur = rect_sum(i+1, j+1, a+i, b+j, prefix[k]);
               can_1 = min(cur/need[k], can_1);
            }

            if (can_2_try) {
               int cur = rect_sum(i+1, j+1, b + i, a + j, prefix[k]);
               can_2 = min(cur/need[k], can_2);
            }

         }
         ans = max({ans, can_1, can_2});
      }
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
