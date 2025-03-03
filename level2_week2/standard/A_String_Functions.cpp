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
   int n, q; cin >> n >> q;
   string s; cin >> s;

   while (q--) {
      string op; cin >> op;
      if (op == "pop_back") {
         s.pop_back();
         
      } else if (op == "front") {
         cout << s.front() << endl;

      } else if (op == "back") {
         cout << s.back() << endl;

      } else if (op == "sort") {
         int l, r; cin >> l >> r;
         if (l > r) swap(l, r);
         sort(s.begin() + l - 1, s.begin()+r);
      
      } else if (op == "reverse") {

         int l, r; cin >> l >> r;
         if (l > r) swap(l, r);
         reverse(s.begin() + l - 1, s.begin()+r);

      } else if (op == "print") {
         int i; cin >> i;
         cout << s.at(i-1) << endl;

      } else if (op == "substr") {
         int l, r; cin >> l >> r;
         if (l > r) swap(l, r);
         cout << s.substr(l-1, r - l + 1) << endl;

      } else if (op == "push_back") {
         char x; cin >> x;
         s.push_back(x);

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
