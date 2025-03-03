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

string e = "End";

bool isEnd(string s) {
   return s.substr(0, 3) == e;
}

void solve() {
   int n; cin >> n;
   vector<string> a(n); cin >> a;
   if (a[0] != "Header" || a[n-1] != "EndHeader") {
      cout  << "WA\n";
      return;
   }

   stack<string> st;
   bool is_ac = true;
   for (int i = 1; i < n-1; i++) {
      string s = a[i];
      if (s == "Header") {
         cout << "WA\n";
         return;
      }
      if (isEnd(s)) {
         string tag = s.substr(3);
         if (!st.empty() && st.top() == tag) {
            st.pop();
         } else {
            is_ac = false;
         }
      } else {
         st.push(s);
      }
   }

   if (!is_ac || !st.empty()) cout << "WA\n";
   else cout << "ACC\n";
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
