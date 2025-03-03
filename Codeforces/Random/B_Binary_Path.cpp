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

int compare_char(char c1, char c2) {
   if (c1 > c2) return 1;
   if (c1 < c2) return -1;
   else return 0;
}


void solve() {
   int n; cin >> n;
   vector<string> a(2, string(n, '0')); cin >> a;

   vi dp(n+1);
   for (int i = n-2; i >= 0; i--) {
      int comp = compare_char(a[0][i+1], a[1][i]);
      dp[i] = comp ? comp : dp[i+1];
   }

   string ans; int paths = 1;
   ans += a[0][0];
   for (int i = 0; i < n-1; i++) {
      if (dp[i] == 0) {
         paths++;
         ans += a[0][i+1];
      } else if (dp[i] == -1) {
         ans += a[0][i+1];
      } else {
         ans += a[1].substr(i, n-i-1);
         for (int j = i; j < n-1; j++) {
            int comp = compare_char(a[0][j+1], a[1][j]);
            if (comp == 0) paths++;
            else break;
         }
         break;
      }
   }
   ans += a[1][n-1];
   cout << ans << endl;
   cout << paths << endl;
}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}
