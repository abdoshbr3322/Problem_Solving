
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
      cin >> a[i];
   }
}
void solve() {
   int n, d; cin >> n >> d;
   vi result = {1};
   if (d % 3 == 0 || n >= 3) result.push_back(3);
   if (d == 5) result.push_back(5);
   if (d == 7 || n >= 3) result.push_back(7);
   if (d == 9 || (n >= 6) || (d % 3 == 0 && n >= 3)) result.push_back(9);
   for (auto i : result) cout << i << ' ';
   cout << endl;
}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}