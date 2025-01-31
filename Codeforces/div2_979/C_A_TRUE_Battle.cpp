
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

#define fastio                       \
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

void make_unique(vi &a) {
   auto ip = unique(all(a));
   a.resize(distance(a.begin(), ip));
}

void input2D(vvi &a, int n, int m) {
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         int ai;
         cin >> ai;
         a[i].push_back(ai);
      }
   }
}

void input(vi &a, int n) {
   for (int i = 0; i < n; i++)  {
      int ai;
      cin >> ai;
      a.push_back(ai);
   }
}

void solve() {
   int n; cin >> n;
   string s; cin >> s;
   if (n > 3 && (s[0] == '1' || s[1] == '1' || s[n-1] == '1' || s[n-2] == '1')) {
      cout << "YES\n";
      return;
   };
   if (n <= 3 && (s[0] == '1' || s[n-1] == '1')) {
      cout << "YES\n";
      return;
   }
   int z = 0, o = 0;
   for (auto i : s) {
      if (i == '0') z++;
      else o++;
   }
   if ((n / 2) >= z) cout << "YES\n";
   else cout << "NO\n";

}

int main() {
   fastio;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}