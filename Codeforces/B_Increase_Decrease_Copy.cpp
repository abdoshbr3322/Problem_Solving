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

// int dx[] =  {1, 1, 0, 0, -1, -1, 1, -1};
// int dy[] =  {1, -1, 1, -1, 1, -1, 0, 0};

void solve() {
   int n; cin >> n;
   vll a(n); cin >> a;
   vll b(n+1); cin >> b; 
   ll ans = 1;
   ll min_dif = INT_MAX;
   for (int i = 0; i < n; i++) {
      ans += abs(a[i]-b[i]);
      if ((b[n] >= min(a[i], b[i])) && (b[n] <= max(a[i], b[i]))) min_dif = 0;
      min_dif = min({min_dif, abs(a[i] - b[n]), abs(b[i] - b[n])});
   }
   ans += min_dif;
   cout << ans << endl;
}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}
