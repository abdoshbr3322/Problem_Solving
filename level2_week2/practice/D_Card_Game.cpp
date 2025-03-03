// بسم الله الرحمن الرحيم

#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>
#include <iomanip>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <array>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <string>
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
   vector<string> in(3); cin >> in;
   queue<char> m, a, r;
   for (char c : in[0]) {
      m.push(c);
   }
   for (char c : in[1]) {
      a.push(c);
   }
   for (char c : in[2]) {
      r.push(c);
   }
   char turn = 'm';
   while (true) {
      if (turn == 'm') {
         if (m.empty()) {
            cout << 'M' << endl;
            return;
         }
         turn = m.front();
         m.pop();
      } else if (turn == 'a') {
         if (a.empty()) {
            cout << 'A' << endl;
            return;
         }
         turn = a.front();
         a.pop();
      } else {
         if (r.empty()) {
            cout << 'R' << endl;
            return;
         }
         turn = r.front();
         r.pop();
      }
   }
}


int main() {
   FreePalestine;
   // #ifndef ONLINE_JUDGE 
   //    freopen("input.txt", "r", stdin); 
   //    freopen("output.txt", "w", stdout); 
   // #endif 
   int t; t = 1;
   // cin >> t;
   while (t--) solve();
   return 0;
}
