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

void input2D(vector<vector<char>> &a, int n, int m){
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         char ai; cin >> ai;
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
   int n, k; cin >> n >> k;
   vector<vector<char>> a(n); input2D(a, n, n);
   vector<vector<char>> b(n/k);
   for (int i = 0; i < n; i+=k) {
      for (int j = 0; j < n; j += k) {
         b[i/k].push_back(a[i][j]);
      }
   }
   for (int i = 0; i < n/k; i++) {
      for (int j = 0; j < n/k; j++) cout << b[i][j];
      cout << endl; 
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