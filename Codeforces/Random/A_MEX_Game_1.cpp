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


vll prefix_sum(vi &a) {
   int n = a.size();
   vll prefix(n+1, 0);
   for (int i = 0; i < a.size(); i++) {
      prefix[i+1] += a[i] + prefix[i];
   }
   return prefix;
}


void solve() {
   ll n; cin >> n;
   vll a(n); cin >> a;
   
   vll freq(n+1);
   for (auto i : a) freq[i]++;
   
   ll extra = INT_MAX, fail = 0;
   for (int i = 0; i <= n ;i++) {
      // cout << i << ' ' << freq[i] << endl;
      if (freq[i] == 0) {
         cout << i << endl;
         return;
      }
      if (freq[i] == 1) {
         if (fail) {
            cout << i << endl;
            return;
         }
         fail = 1;
      }
   }
}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}
