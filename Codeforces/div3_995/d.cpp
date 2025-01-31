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

void input2D(vvi &a, int n, int m){
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         int ai; cin >> ai;
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
   int n; ll x, y;
   cin >> n >> x >> y;
   vi a; input(a, n);
   sort(all(a));
   ll s = accumulate(all(a), 0ll);
   ll mini = s - y;
   ll maxi = s - x;
   ll ans  = 0;

   for (int i = 0; i < n; i++) {
      // find the first number greater than or equal to mini-a[i]
      auto low = lower_bound(a.begin()+i+1, a.end(), mini-a[i]);
      // find the last number less than or equal to maxi-a[i]
      auto up = upper_bound(a.begin()+i+1, a.end(), maxi-a[i]);
      up--;
      ans += (up - low +  1ll);
   }
   cout << ans << endl;
}


int main() {
   fastio;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}