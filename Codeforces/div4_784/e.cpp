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
   vector<string> a(n, string(2, '.')); cin >> a;
   vector<string> rev(a);
   for (auto &i : rev) reverse(all(i));
   sort(all(a));
   sort(all(rev));
   ll ans = 0;
   for (int i = 0; i < n; i++) {
      string s;
      // include all strings start with a[i][0]
      // cout << a[i] << endl;
      auto l = lower_bound(a.begin() + i, a.end(), s + a[i][0] + 'a');
      auto r = upper_bound(a.begin() + i, a.end(), s + a[i][0] + 'z');
      ans += (r - l);
      // cout << ans << endl;

      // include all strings end with rev[i][0]
      l = lower_bound(rev.begin()+i, rev.end(), s + rev[i][0] + 'a');
      r = upper_bound(rev.begin()+i, rev.end(), s + rev[i][0] + 'z');
      ans += (r - l);
      // cout << ans << endl;

      // exclude all strings equal to a[i] twice;
      l = lower_bound(a.begin() + i, a.end(), a[i]);
      r = upper_bound(a.begin() + i, a.end(), a[i]);
      ans -= 2 * (r - l);
      // cout << ans << endl;

   }
   cout << ans << endl;
}


int main() {
   FreePalestine;

   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}
