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
   int n, m, k; cin >> n >> m >> k;
   vi a(n), b(m);
   input(a, n); input(b, m);
   sort(all(a));
   sort(all(b));
   int nn = make_unique(a);
   int mm = make_unique(b);

   vi ans;
   vector<bool> ex(k+1, 0);

   int c1 = 0, c2 = 0;
   for (auto i : a) {
      if (i >= 1 && i <= k) {
         ex[i] = true;
         c1++;
      } else if (i > k) break;
   }
   for (auto i : b) {
      if (i >= 1 && i <= k) {
         ex[i] = true;
         c2++;
      } else if (i > k) break;
   }

   if (c1 >= (k/2) && c2 >= (k/2)) {
      for (int i = 1; i <= k; i++) {
         if (ex[i] == 0) {
            cout << "NO\n";
            return;
         }
      }
      cout << "YES\n";
   }
   else cout << "NO\n";
}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}