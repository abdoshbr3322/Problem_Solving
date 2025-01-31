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
   vector<double> a(3); cin >> a;
   int k; cin >> k;
   // a[0] += min(a[1] + a[2] , k);
   // cout << a[0] << endl;
   double h = (a[0] + a[1] + a[2]) / (double)2;
   double ans = sqrt(h * (h-a[0]) * (h-a[1]) * (h-a[2]));
   cout << ans << endl;
}


int main() {
   FreePalestine;
   // freopen("sticks.in", "r", stdin); 

   #ifndef ONLINE_JUDGE 
      freopen("input.txt", "r", stdin); 
      freopen("output.txt", "w", stdout); 
   #endif 
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}

