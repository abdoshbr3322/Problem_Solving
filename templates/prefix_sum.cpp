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


vll prefix_sum(vi &a) {
   int n = a.size();
   vll prefix(n+1, 0);
   for (int i = 0; i < a.size(); i++) {
      prefix[i+1] += a[i] + prefix[i];
   }
   return prefix;
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

// for 1 based
ll rect_sum(int x1, int y1, int x2, int y2, vvi &p) {
   return (p[x2][y2] - p[x2][y1-1] - p[x1-1][y2] + p[x1-1][y1-1]);
}
// for 0 based
// ll rect_sum(vvll& prefix, int x1, int y1, int x2, int y2) {
//    ll sum = prefix[x2][y2];
//    if (y1 > 0) sum -= prefix[x2][y1-1];
//    if (x1 > 0) sum -= prefix[x1-1][y2];
//    if (x1 > 0 && y1 > 0) sum += prefix[x1-1][y1-1];
//    return sum;
// }