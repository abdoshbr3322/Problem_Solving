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
   int n, q; cin >> n >> q;
   string s; cin >> s;
   int freq[26][10001] = {};
   for (int i = 0; i < 26; i++) {
      int f = 0;
      for (int j = 1; j <= n; j++) {
         if (s[j-1] == (i + 'a')) f++;
         freq[i][j] = f;
      }
   }
   while (q--) {
      int l, r; char c;
      cin >> l >> r >> c;
      int ans = 0;
      int cor = ceil(double(r) / n) - l /n;
      if (l % n == 0) cor++;
      ans += freq[c-'a'][n] * cor;
      if (l%n != 1) {
         ans -= freq[c-'a'][l%n ? l%n-1 : n-1];
      }
      if (r%n != 0) {
         ans -= freq[c-'a'][n];
         ans += freq[c-'a'][r%n];
      }
      cout << ans << endl;
   }
}


int main() {
   FreePalestine;
   // #ifndef ONLINE_JUDGE 
   //    freopen("input.txt", "r", stdin); 
   //    freopen("output.txt", "w", stdout); 
   // #endif 
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}
