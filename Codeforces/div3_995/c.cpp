// بسم الله الرحمن الرحيم

#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define ll   long long
#define ull  unsigned long long
#define vi   vector<int>
#define vvi  vector<vi>
#define vll  vector<long long>
#define vvll  vector<vll>
#define float double
#define all(a) a.begin(), a.end()
#define all_r(a) a.rbegin(), a.rend()
#define sum_a(n) n*(n+1) / 2

void input2D(vvi &a, int n, int m){
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         int ai; cin >> ai;
         a[i].push_back(ai);
      }
   }
}

void input(vi &a, int n) {
   for (int i = 0; i < n; i++) {
      int ai; cin >> ai;
      a.push_back(ai);
   }
} 

void solve() {
   int n, m, k; cin >> n >> m >> k;
   vi a, q;
   input(a, m);
   input(q, k);
   if (k == n) {
      for (int i = 0; i < m; i++) {
         cout << '1';
      }
      cout << endl;
      return;
   } else if (k < n - 1) {
      for (int i = 0; i < m; i++) {
         cout << '0';
      }
      cout << endl;
      return;
   }
   int mis;
   for (int i = 1; i <= n; i++) {
      if (!binary_search(all(q), i)) mis = i;
   }
   for (auto i : a) {
      if (i == mis) cout << '1';
      else cout << '0';
   }
   cout << endl;
}


int main() {
   fastio;
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}