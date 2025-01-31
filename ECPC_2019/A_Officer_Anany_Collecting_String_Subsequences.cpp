// بسم الله الرحمن الرحيم

#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>
#include <fstream>
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
   string s; cin >> s;
   int ans = INT_MAX;
   for (int i = 0; i < n; i++) {
      if (s[i] == 'A') {
         char cur = 'B';
         for (int j = i + 1; j < n; j++) {
            if (s[j] == cur) cur++;
            if (cur == (char)('Z' + 1)) {
               ans = min(ans, j-i+1);
               break;
            }
         }
      }

   }
   cout << ans << endl;
}


int main() {
   FreePalestine;
   // #ifndef ONLINE_JUDGE 
      freopen("collectingofficer.in", "r", stdin); 
      // freopen("input.txt", "r", stdin); 
      // freopen("output.txt", "w", stdout); 
   // #endif 
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}



vvll prefix_sum_2d(vvi &a) {
   int n = a.size();
   int m = a[0].size();
   vvll prefix(n+1, vll(m+1, 0));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         prefix[i+1][j+1] += prefix[i+1][j] + a[i][j];
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         prefix[i+1][j+1] += prefix[i][j+1];
      }
   }

   return prefix;
}

ll rect_sum(int x1, int y1, int x2, int y2, vvll &p) {
   return (p[y2][x2] - p[y2][x1-1] - p[y1-1][x2] + p[y1-1][x1-1]);
}
void bubble_sort(vi &a) {
   int n = a.size();
   for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1 - i; j++)  {
         if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
      }
   }
}

vll prefix_sum(vi &a) {
   int n = a.size();
   vll prefix(n+1, 0);
   for (int i = 0; i < a.size(); i++) {
      prefix[i+1] += a[i] + prefix[i];
   }
   return prefix;
}


void partialSum(vi &a, int l, int r, int v) {
   a[l] += v;
   a[r+1] -= v;
}

int make_unique(vi &a) {
   auto ip = unique(all(a));
   int n_size = distance(a.begin(), ip);
   a.resize(n_size);
   return n_size;
}
