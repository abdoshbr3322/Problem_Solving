
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
   string s; cin >> s;
   int q; cin >> q;
   int n = s.size();
   map<int, bool> def_i;
   int size = 0;
   for (int i =0; i < n - 3; i++) {
      if ((s[i] + s[i+1]) == ('1' * 2) && (s[i+2] + s[i+3]) == ('0' * 2)) {
         def_i[i] = 1;
         size++;
      }
   }
   while (q--) {
      int i, v; cin >> i >> v; 
      i--;
      s[i] = v + '0';
      if (v == 0 && def_i[i]) {
         def_i[i] = false;
         size--;
      } else if (v == 0 && def_i[i-1]) {
         def_i[i-1] = false;
         size--;
      } else if (v == 1 && def_i[i-2]) {
         def_i[i-2] = false;
         size--;
      } else if (v == 1 && def_i[i-3]) {
         def_i[i-3] = false;
         size--;
      }
      if (v == 0) i-=2;
      if ((!def_i[i] && !def_i[i-1])) {
         if (i < n-3 && ((s[i] + s[i+1]) == ('1' * 2) && (s[i+2] + s[i+3]) == ('0' * 2))) {
            def_i[i] = 1;
            size++;
         } else if (i < n-2 && (s[i-1] + s[i]) == ('1' * 2) && (s[i+1] + s[i+2]) == ('0' * 2)) {
            def_i[i-1] = 1;
            size++;
         }
      }
      cout << (size ? "YES" : "NO") << endl;
   }

}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}