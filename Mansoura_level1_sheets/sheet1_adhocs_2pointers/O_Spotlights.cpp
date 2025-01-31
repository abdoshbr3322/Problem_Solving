
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

#define FreePalestine  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
   int n, m; cin >> n >> m;
   vvi a(n, vi(m)) ; cin >> a;
   vvi prefix_r(a);
   for (int i = 0; i < n ; i++) {
      for (int j = 1; j < m; j++) {
         prefix_r[i][j] += prefix_r[i][j-1];
      }
   }
   vvi prefix_c(a);
   for (int i = 1; i < n ; i++) {
      for (int j = 0; j < m; j++) {
         prefix_c[i][j] += prefix_c[i-1][j];
      }
   }
   int ans =  0;
   for (int i = 0; i  <n; i++) {
      for (int j = 0; j < m; j++) {
         if (a[i][j] == 0) {
            if (prefix_r[i][m-1] - prefix_r[i][j]) ans++;
            if (j != 0 && prefix_r[i][j-1]) ans++;
            if (prefix_c[n-1][j] - prefix_c[i][j]) ans++;
            if (i != 0 && prefix_c[i-1][j]) ans++;
         }
      }
   }
   cout << ans << endl;
}


int main() {
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   int t = 1;
   // cin >> t;
   while (t--) solve();
   return 0;
}
