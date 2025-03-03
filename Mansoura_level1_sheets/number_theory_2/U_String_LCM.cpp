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
   string s, t; cin >> s >> t;
   int n = s.size(), m  = t.size();
   
   
   for (int i = 1; i <= min(n, m); i++) {
      bool flag = true;
      for (int j = 0; j < n; j++) {
         if (s[j] != s[j%i]) {
            flag = false;
            break;
         }
      }
      for (int j = 0; j < m; j++) {
         if (t[j] != t[j%i]) {
            flag = false;
            break;
         }
      }
      if (flag && n % i == 0 && m % i == 0) {
         int length = lcm(n/i, m/i);
         while (length--) {
            for (int j = 0; j < i; j++) {
               cout << s[j];
            }
         }
         cout << endl;
         return;
      }
   }
   cout << -1 << endl;
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
