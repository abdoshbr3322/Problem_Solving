
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

#define fastio                       \
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

void make_unique(vi &a) {
   auto ip = unique(all(a));
   a.resize(distance(a.begin(), ip));
}

void input2D(vvi &a, int n, int m) {
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         int ai;
         cin >> ai;
         a[i].push_back(ai);
      }
   }
}

void input(vll &a, int n) {
   for (int i = 0; i < n; i++)  {
      cin >> a[i];
   }
}

void solve() {
   ll n, m, q; cin >> n >> m >> q;
   vll b(m); input(b, m);
   sort(all(b));
   while (q--) {
      ll a; cin >> a;
      ll ans;
      if (a < b[0]) ans = b[0] - 1;
      else if (a > b[m-1]) ans = n-b[m-1];
      else {
         auto it = lower_bound(all(b), a);
         ans = (*it - *(--it)) / 2  ;
      }
      cout << ans << endl;
   }
}


int main() {
   fastio;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}  