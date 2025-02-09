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

bool is_bd(int n) {
   while (n) {
      if (n % 10 != 1 && n % 10 != 0) return false;
      n/=10;
   }
   return true;
}

int is_pr[100001] {0};
bool is_presented(int n) {
   if (is_pr[n]) return is_pr[n] == 1 ? true : false; // Memoization
   if (is_bd(n)) return true;  // Base Case
   for (int i = 2; i <= sqrt(n); i++) { // Recursive Case
      if (n % i == 0 && is_presented(i) && is_presented(n/i)) {
         is_pr[n] = 1;
         return true;
      }
   }
   is_pr[n] = -1;
   return false;
}



void solve() {
   int n; cin >> n;
   cout <<  (is_presented(n) ? "YES\n" : "NO\n");
}


int main() {
   FreePalestine;
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}
