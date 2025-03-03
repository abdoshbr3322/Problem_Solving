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
   int q; cin >> q;

   deque<int> dq;

   while (q--) {
      string op; cin >> op;
      if (op == "push_back") {
         int x; cin >> x;
         dq.push_back(x);
      }

      else if (op == "push_front") {
         int x; cin >> x;
         dq.push_front(x);
      }

      else if (op == "pop_front") {
         dq.pop_front();
      }

      else if (op == "pop_back") {
         dq.pop_back();
      }

      else if (op == "front")
         cout << dq.front() << endl;

      else if (op == "back")
         cout << dq.back() << endl;

      else if (op == "print") {
         int x; cin >> x;
         cout << dq[x-1] << endl;
      }
      
   }
}


int main() {
   FreePalestine;
   // #ifndef ONLINE_JUDGE 
   //    freopen("input.txt", "r", qudin); 
   //    freopen("output.txt", "w", qudout); 
   // #endif 
   int t; t = 1;
   // cin >> t;
   while (t--) solve();
   return 0;
}
