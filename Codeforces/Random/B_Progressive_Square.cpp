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
   int n, c, d; cin >> n >> c >> d;
   vi b(n*n); input(b, n*n);
   sort(all(b));
   int mini = b[0];
   vi valid;
   for (int i = 0; i < n; i++) {
      valid.push_back(mini);
      for (int j = 1; j < n - i; j++) {
         valid.push_back(mini + (c*j));
         valid.push_back(mini + (d*j));
      }
      mini += (c + d);
   }
   sort(all(valid));
   for (int i =0 ; i < n * n; i++) {
      // cout << valid[i] << ' '; 
      if (b[i] != valid[i]) {
         cout << "NO\n";
         return;
      }
   }
   cout << "YES\n";
}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}