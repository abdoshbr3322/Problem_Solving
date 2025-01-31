// بسم الله الرحمن الرحيم

#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define ll   long long
#define ull  unsigned long long
#define vi   vector<int>
#define vvi  vector<vi>
#define vll  vector<long long>
#define vvll  vector<vll>
#define float double
#define all(a) a.begin(), a.end()
#define all_r(a) a.rbegin(), a.rend()
#define sum_a(n) n*(n+1) / 2

void input2D(vector<vector<char>> &a, int n, int m){
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         char ai; cin >> ai;
         a[i].push_back(ai);
      }
   }
}

void input(vi &a, int n) {
   for (int i = 0; i < n; i++) {
      int ai; cin >> ai;
      a.push_back(ai);
   }
} 

void solve() {
   int n, q; cin >> n >> q;
   string a, b; cin >> a >> b;

   int a_dp[26][200000] = {0};
   int b_dp[26][200000] = {0};
   for (int i = 0; i < n; i++) {
      a_dp[a[i]-'a'][i]++;
      b_dp[b[i]-'a'][i]++;
      for (int j = 0; j < 26; j++) {
         a_dp[j][i] += a_dp[j][i-1];
         b_dp[j][i] += (i == 0 ? 0 : b_dp[j][i-1]);
      }
   }
   while (q--) {
      int l, r; cin >> l >> r;
      l--; r--;
      l = min(l,r); r = max(l,r);
      int ans = 0;
      map<int, int> fr_a;
      for (int i = 0; i < 26; i++) {
         ans += max((a_dp[i][r] - (l == 0 ? 0 : a_dp[i][l-1])) - (b_dp[i][r] - (l == 0 ? 0 : b_dp[i][l-1])), 0);
      }

      cout << ans << endl;
   }
}


int main() {
   fastio;
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}