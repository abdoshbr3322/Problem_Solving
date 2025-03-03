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
   int l, r; cin >> l >> r;
   vector<bool> rem(r-l+200, false);
   int ans = 0;
   for (int i =  l; i < r; i++) {
      if (rem[i-l] || rem[i-l+1]) continue;
      for (int j = l; j <= r; j++) {
         if (j == i || j == i+1 || rem[j-l]) continue;
         if (gcd(i, j) == gcd(i+1, j) && gcd(i,j) == 1) {
            ans++;
            rem[i-l] = 1;
            rem[i-l+1] = 1;
            rem[j-l] = 1;
            break;
         }
      }
   }
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
