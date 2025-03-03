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

vll prefix_sum(vll &a) {
   int n = a.size();
   vll prefix(n+1, 0);
   for (int i = 0; i < a.size(); i++) {
      prefix[i+1] += a[i] + prefix[i];
   }
   return prefix;
}

void solve() {
   int n, q; cin >> n >> q;
   vll a(n); cin >> a;
   vll prefix = prefix_sum(a);
   vi broken(n+1);
   for (int i = 0; i < n; i++) {
      broken[i+1] = (a[i] == 0);
      broken[i+1] += broken[i];
   }

   while (q--) {
      int l, r; cin >> l >> r;
      ll sum = prefix[r] - prefix[l-1];
      if (sum < 0) {
         cout << "SpongeBob just flopped." << endl;
      } else if (sum == 0) {
         cout << "Oh! SpongeBob is spinning." << endl;
      } else {
         cout << sum << ' '; 
         cout << broken[r] - broken[l-1] << endl;
      }
   }
}


int main() {
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
