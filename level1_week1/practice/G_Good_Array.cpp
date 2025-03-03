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
#define int ll

void solve() {
   int n; cin >> n;
   vi a(n); cin >> a;
   
   ll sum = 0;
   vi freq(1e6+1);
   for (int i : a) {
      freq[i]++;
      sum += i;
   }

   vi ans;
   for (int i = 0; i < n; i++) {
      sum -= a[i];
      freq[a[i]]--;
      if (sum % 2 == 0 && (sum / 2) <= 1e6 && freq[sum/2]) {
         ans.push_back(i+1);
      }
      sum += a[i];
      freq[a[i]]++;
   }
   int ans_s = (int)(ans.size());
   cout << ans_s << endl;
   if (ans_s) {
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
