
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
   ll n, x; cin >> n >> x;
   vi a(n+1);
   for (int i = 1; i <= n; i++) cin >> a[i];
   for (int i = 1; i <= n; i++) a[i]+= a[i-1];

   int l = 1, r = 1;
   int sum = 0;
   int ans = 0;
   while (r <= n) {
      sum = a[r] - a[l-1];
      while (sum > x) {
         sum += a[l-1];
         l++;
         sum -= a[l-1];
      }
      ans = max(ans, r-l+1);
      r++;
   }
   cout << ans << endl;
}

int main() {
   FreePalestine;
   int t; t = 1;
   // cin >> t;
   while (t--) solve();
   return 0;
}