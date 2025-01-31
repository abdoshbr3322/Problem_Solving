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
   vi a;
   map<int, int> fr;
   for (int i =  0 ; i < n ; i++) {
      int ai; cin >> ai;
      a.push_back(ai);
      fr[ai]++;
   }
   if (fr[0] == n) cout << "0\n";
   else {
      bool found = false;
      bool foundz = false;
      for (int i= 0 ; i < n; i++) {
         if (a[i] != 0) found = true;
         if (found && a[i] == 0) {
            foundz= true;
         }
         if (foundz && a[i] != 0) {
            cout << "2\n";
            return;
         }
      }
      cout << "1\n";
   }
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