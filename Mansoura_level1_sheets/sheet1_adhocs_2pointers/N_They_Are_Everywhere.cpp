
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

#define FreePalestine  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
   string a; cin >> a;


   int dis = 0;
   vector<bool> ex('z'-'A'+1, 0);
   for (char i : a) {
      if (!ex[i-'A']) { 
         dis++;
         ex[i-'A'] = 1;
      }
   }
   map<int, int> freq;

   int mini = n;
   int l = 0, r = 0;
   while (r < n) {
      freq[a[r]]++;
      while (freq.size() >= dis) {
         mini = min(mini, r-l+1);
         freq[a[l]]--;
         if (freq[a[l]] == 0) freq.erase(a[l]);
         l++;
      }
      
      r++;
   }
   cout << mini << endl;
}


int main() {
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   int t = 1;
   // cin >> t;
   while (t--) solve();
   return 0;
}
