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

int make_unique(vi &a) {
   auto ip = unique(all(a));
   int n_size = distance(a.begin(), ip);
   a.resize(n_size);
   return n_size;
}

void input2D(vvi &a, int n, int m) {
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> a[i][j];
      }
   }
}

void input(vi &a, int n) {
   for (int i = 0; i < n; i++)  {
      cin >> a[i];
   }
}

void solve() {
   string s; cin >> s;
   int n = s.size();
   ll ans = 0;      
   int ones = 0, zeros = 0;
   for (int i = 0; i < n; i++) {
      if (ones && s[i] == '0') zeros++;
      if ((s[i] == '1' || i == n-1) && zeros) {
         // cout << "test\n";
         ans += ((ll)(ones + 1) * zeros);
         zeros = 0;
      }
      if (s[i] == '1') ones++;
   }

   cout << ans << endl;   

}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}