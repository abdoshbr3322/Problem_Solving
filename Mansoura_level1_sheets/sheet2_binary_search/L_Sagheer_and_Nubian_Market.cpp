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
   int n, s; cin >> n >> s;
   vll a(n); cin >> a;

   
   ll k, t;
   int l = 0, r = n;
   while (l <= r) {
      ll mid = (l + r) / 2;
      vll a_(a);
      for (int i = 0; i < n; i++) {
         a_[i] += ((i + 1) * mid); 
      }
      sort(all(a_));
      ll sum = accumulate(a_.begin(), a_.begin() + mid, 0ll);
      if ((sum) <= s) {
         k = mid;
         t = sum;
         l = mid + 1;
      } else {
         r = mid-1;
      }
   }
   cout << k << ' ' << t;

}



int main() {
   FreePalestine;
   int t; t = 1;
   // cin >> t;
   while (t--) solve();
   return 0;
}

