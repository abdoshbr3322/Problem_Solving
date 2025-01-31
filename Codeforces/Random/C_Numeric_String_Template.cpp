
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
   // int n; cin >> n;
   // vi a(n); input(a, n);
   // int m; cin >> m;
   // map<int, int> freq;
   // map<int, vi> ans;
   // for (int i = 0; i < n; i++) {
   //    freq[a[i]]++;
   // }
   // for (int i = 0; i < n; i++) {
   //    if (freq[a[i]] > 1) ans[a[i]].push_back(i);
   // }

   // while (m--) {
   //    string s; cin >> s;
   //    bool flag = true;
   //    for (auto i : ans) {  // O(n/2);
   //       for (int j = 0; j < n-1; j++) { // O(2)
   //          if (s[j] != s[j+1]) flag = false;
   //          break;
   //       }
   //       if (!flag )break;
   //    }
   //    cout << (flag ? "YES\n" : "NO\n");

   // }
   int n; cin >> n;
   vi a(n); input(a, n);
   int m; cin >> m;

}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}