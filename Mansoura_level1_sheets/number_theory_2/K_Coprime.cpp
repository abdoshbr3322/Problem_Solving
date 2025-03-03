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
   vi ind(1001, -1);
   for (int i = 0; i < n; i++) {
      ind[a[i]] = i;
   }

   int maxi = INT_MIN;
   bool found = false;
   for (int i = 1; i <= 1000; i++) {
      if (ind[i] == -1) continue;
      for (int j = 1; j <= 1000; j++) {
         if (ind[j] == -1) continue;
         if (gcd(i, j) == 1) {
               found = true;
               maxi = max(maxi, ind[i] + ind[j] + 2);
            }
         }
   }
   if (found) {
      cout << maxi << endl;
   } else {
      cout << -1 << endl;
   }
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
