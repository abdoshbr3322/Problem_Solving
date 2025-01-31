
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

int make_unique(vi &a) {
   auto ip = unique(all(a));
   int n_size = distance(a.begin(), ip);
   a.resize(n_size);
   return n_size;
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
   int n, k , q; cin >> n >> k >> q;

   vi p(2e5+1, 0);
   vi adm(2e5+1, 0);
   for (int i = 0; i < n; i++) {
      int l, r; cin >> l >> r;
      p[l]++;
      p[r+1]--;
   }
   for (int i = 0; i < 2e5; i++) {
      p[i+1] += p[i];
      adm[i+1] += adm[i] + (p[i+1] >= k);
   }
   while (q--) {
      int a, b; cin >> a >> b;
      cout << adm[b] - adm[a-1] << endl;
   }


}

int main() {
   FreePalestine;
   int t; t = 1;
   // cin >> t;
   while (t--) solve();
   return 0;
}