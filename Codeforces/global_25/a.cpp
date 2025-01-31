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
   int n; cin >> n;
   string s; cin >> s;
   int one = 0;
   for (int i = 0; i < n; i++) one += (s[i] - '0');
   if (one % 2 == 0 && one != 2) cout << "YES\n";
   else if (one == 2) {
      for (int i = 0; i < s.size() - 1; i++) {
         if (s[i] == '1' && s[i+1] == '1') {
            cout << "NO\n";
         } else cout << "YES\n";
      }
   }
   else cout << "NO\n";
}


int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}