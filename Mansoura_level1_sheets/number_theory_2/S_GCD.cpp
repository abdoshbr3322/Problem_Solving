// بسم الله الرحمن الرحيم

#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>
#include <iomanip>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <array>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;

template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
#define FreePalestine                \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);                    \
   cout.tie(NULL)

#define int ll
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

int gcd(int a, int b) {
   if (a < b) swap(a, b);
   if (b == 0) return a;
   return gcd(b, a % b);
}

void solve() {
   while (true) {
      int n; cin >> n;
      if (n == 0) break;
      ll ans = 0;
   
      for (int i =1 ; i <= n; i++) {
         for (int j = i + 1; j <= n; j++) {
            ans += gcd(i, j);
         }
      }
      cout << ans << endl;
   }
}


signed main() {
   FreePalestine;
   // #ifndef ONLINE_JUDGE 
   //    freopen("input.txt", "r", stdin); 
   //    freopen("output.txt", "w", stdout); 
   // #endif 
   int t; t = 1;
   // cin >> t;
   while (t--) solve();
   return 0;
}
