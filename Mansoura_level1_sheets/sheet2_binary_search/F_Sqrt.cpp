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
   ll n; cin >> n;

   double sqr = sqrt(n);
   cout << (sqr == (int)sqr ? "YES\n" : "NO\n");

   // int st = 1, nd = 1e9;
   // while (st <= nd) {
   //    int mid = (st + nd ) / 2;
   //    ll po = 1ll * mid * mid;
   //    if (po > n) {
   //       nd = mid -1;
   //    } else if (po < n) {
   //       st = mid + 1;
   //    } else {
   //       cout << "YES\n";
   //       return;
   //    }
   // } 
   // cout << "NO\n";
}



int main() {
   FreePalestine;
   int t; t = 1;
   // cin >> t;
   while (t--) solve();
   return 0;
}

