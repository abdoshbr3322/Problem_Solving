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

bool isC(char c) {
   return (c == 'b' || c == 'c' || c == 'd');
}
bool isV(char c) {
   return (c == 'a' || c == 'e');
}
bool isCV(string s) {
   return (isC(s[0]) && isV(s[1]));
}
bool isCVC(string s) {
   return (isC(s[0]) && isV(s[1]) && isC(s[2]));
}

void solve() {
   int n; cin >> n;
   string s; cin >> s;
   vector<string> splits;
   int i = 0;
   for (; i < n-2; i++) {
      string _ = "";
      string s1 = _ + s[i] + s[i+1];
      string s2 =  s1 + s[i+2];
      if (isCV(s1)) {
         splits.push_back(s1);
         i++;
      } else if (isCVC(s2)) {
         splits.push_back(s2);
         i+=2;
      } else {
         splits.back().push_back(s[i]);
      }
   }
   if (i == n-1 && i++) splits.back().push_back(s.back());
   else splits.push_back(s.substr(i));
   for (int i  = 0; i < splits.size(); i++) cout << splits[i] << (i <  splits.size()-1 ? "." : "");
   cout << endl;
}


int main() {
   FreePalestine;
   // #ifndef ONLINE_JUDGE 
   //    freopen("input.txt", "r", stdin); 
   //    freopen("output.txt", "w", stdout); 
   // #endif 
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}

