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
   vi a(n); cin >> a;
   sort(all(a));
   int odd = count_if(all(a), [&](int i) {
      return (i % 2);
   });
   if ((odd == 0) || (odd == n)) {   
      cout << 0 << endl;
   } else {
      int ans = 0;
      ll max_o;
      for (int i = n-1; i >= 0; i--) {
         if (a[i] % 2) {
            max_o = a[i];
            break;
         }
      }
      for (int i = 0; i < n; i++) {
         if (a[i] % 2 == 0) {
            if (a[i] < max_o) {
               ans++;
               max_o += a[i];
            } else {
               ans += 2;
               max_o += (2 * a[n-1]);
            }
         }
      }
      cout << ans << endl;
   }
   
}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}
