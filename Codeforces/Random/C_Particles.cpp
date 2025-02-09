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
   vi a(n); cin >> a;
   if (n == 1) cout << a[0] << endl;
   else {
      int pos = count_if(all(a), [&](int i) {
         return i >= 0;
      });
      if (pos) for (int i = 0; i < n; i++) a[i] = max(a[i], 0);
      else {
         cout << *max_element(all(a)) << endl;
         return;
      }
      ll s1 = a[0], s2 = a[1];
      for (int i = 2; i < n; i+=2) s1 += max(a[i], 0);
      for (int i = 3; i < n; i+=2) s2 += max(a[i], 0);
      cout << max(s1, s2) << endl;
   }
}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}
