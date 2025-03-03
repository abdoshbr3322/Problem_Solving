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

int mod(int a, int b) {
   return (a % b + b ) % b;
}

void solve() {
   ll n; cin >> n;
   vll a(n); cin >> a;
   
   sort(all(a));
   ll g = 0;
   for (auto i : a) {
      g = gcd(a[n-1] - i, g);
   }
   if (g == 0) {
      cout << 1 << endl;
      return;
   }
   ll extra = a[n-1] - g;
   
   for (int i = n-1;i >= 0; i--) {
      if (a[i] < extra) {
         break;
      }
      else if (a[i] == extra) extra -= g;
   }
   a.push_back(extra);
   ll ans = 0;
   for (ll i : a) {
      ans += (a[n-1] - i) / g;
   }
   // cout << g << endl << a << endl;
   cout << ans << endl;
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
