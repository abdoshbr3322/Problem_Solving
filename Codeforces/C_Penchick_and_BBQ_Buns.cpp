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
   if (n % 2 && n <= 25) {
      cout << "-1\n";
      return;
   }
   if (n % 2) {
      cout << 1 << ' ';
      for (int i = 3; i <= 6; i++) {
         cout << i << ' ' << i << ' ';
      }
      cout << "1 2 ";
      for (int i = 7; i<= 13; i++) {
         cout << i << ' ' << i << ' ';
      }
      cout << "1 2 ";
      for (int i = 15; i<= (n/2)+1; i++) {
         cout << i << ' ' << i << ' ';
      }
   }
   else {
      for (int i = 1; i <= (n/2); i++) {
         cout << i << ' ' << i << ' '; 
      }
      cout << endl;
   }
}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}

