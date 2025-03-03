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

struct t
{
   string s;
   int x, y, z;
};


void solve() {
   int n; cin >> n;
   vector<t> a(n);
   for (int i = 0; i < n; i++) {
      cin.ignore();
      string s; getline(cin, s);
      int x, y, z; cin >> x >> y >> z;
      t team = {s, x, y, z};
      a[i] = team;
   }
   sort(all(a), [&](t i, t j)  {
      if (i.x > j.x) return true;
      else if (i.x == j.x) {
         if (i.y < j.y) return true;
         else if (i.y == j.y) {
            return i.z <= i.y;
         } else return false;
      } else return false;
   });

   cout << a[0].s << endl  ; 
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
