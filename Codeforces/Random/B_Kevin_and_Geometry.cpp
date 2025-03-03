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
   sort(all(a));
   int maxl = -1;
   
   for (int i = n-1; i >= 1; --i) {
      if (a[i] == a[i-1]) {
         maxl = a[i];
         a.erase(a.begin()+i-1, a.begin()+i+1);
         break;
      }
   }
   if (maxl == -1) {
      cout << -1 << endl;
      return;
   }
   vi dif(n-3);
   for (int i = 0; i < n-3; i++) dif[i] = a[i+1] - a[i];

   for (int i = 0; i < n-3; i++) {
      if (dif[i] < 2 * maxl) {
         cout << maxl << ' ' << maxl << ' ' << a[i] << ' ' << a[i+1] << endl;
         return;
      }
   }
   cout << "-1\n";
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
