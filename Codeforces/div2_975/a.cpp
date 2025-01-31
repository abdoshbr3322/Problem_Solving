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
   int n; cin >> n;
   vi a; input (a, n);
   auto maxi = max_element(all(a));
   int i = maxi - a.begin();
   if (n % 2 == 0) {
      cout << (n/2) + *maxi << endl;
      
   } else {
      int ans = (i % 2 == 1) ? (n / 2) : ((n / 2) + 1);
      if (i % 2 == 1) {
         for (int j = i+1; j < n; j+=2) {
            if ((a[j] == *maxi)) {
               ans++;
               break;
            }
         }
      }
      cout << ans + *maxi << endl;
   }
}


int main() {
   fastio;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}