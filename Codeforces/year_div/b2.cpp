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

#define fastio                       \
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

void make_unique(vi &a) {
   auto ip = unique(all(a));
   a.resize(distance(a.begin(), ip));
}
void make_unique(vll &a) {
   auto ip = unique(all(a));
   a.resize(distance(a.begin(), ip));
}

void input2D(vvi &a, int n, int m) {
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         int ai;
         cin >> ai;
         a[i].push_back(ai);
      }
   }
}

void input(vi &a, int n) {
   for (int i = 0; i < n; i++)  {
      int ai;
      cin >> ai;
      a.push_back(ai);
   }
}

void solve()
{
   int n; cin >> n;
   vpll a;
   vll my;
   map<ll, int> freq;
   for (int i = 0; i < n; i++) {
      ll l, r; cin >> l >> r;
      a.push_back({l, r});
      if (l == r) {
         my.push_back(l);
         freq[l]++;
      }
   }
   sort(all(my));
   make_unique(my);
   for (auto p : a) {
      ll l = p.first, r = p.second;
      if (l == r) {
         cout << (freq[l] > 1 ? 0 : 1);
         continue;
      }
      auto li = lower_bound(all(my), l);
      auto ri = lower_bound(all(my), r);
      if (li != my.end() && ri != my.end() && *li == l && *ri == r && ((ri - li) == (r - l))) cout << 0;
      else cout << 1;
   }
   cout << endl;
}

int main()
{
   fastio;
   int t;
   t = 1;
   cin >> t;
   while (t--)
      solve();
   return 0;
}