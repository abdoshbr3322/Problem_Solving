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
   vvll a(n, vll(n)); cin >> a;
   for (int i = 0; i < n; i++) {
      ll sum = 0;
      for (int j = n-1; j >= 0; j--) {
         ll temp = a[i][j];
         a[i][j] = sum;
         sum += temp;
      }
      reverse(all(a[i]));
   }
   sort(all(a));   

   int s = n-2;
   for (int cur = 1; cur < n;) {
      bool found = false;
      for (int i = s; i >= 0; i--) {
         for (int j = 1; j < n; j++) {
            if (a[i][j] == cur) {
               cur++;
               found = true;
               s = i-1;
               break;
            }
         }
         if (found) break;
      }
      if (!found) {
         cout << cur << endl;
         return;
      }
   }
   cout << n << endl;
}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}

