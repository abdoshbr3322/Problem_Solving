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
#define float double
#define all(a) a.begin(), a.end()
#define all_r(a) a.rbegin(), a.rend()
#define sum_a(n) n *(n + 1) / 2

void input2D(vvi &a, int n, int m)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         int ai;
         cin >> ai;
         a[i].push_back(ai);
      }
   }
}

void input(vi &a, int n)
{
   for (int i = 0; i < n; i++)
   {
      int ai;
      cin >> ai;
      a.push_back(ai);
   }
}

void solve()
{
   int n;
   cin >> n;
   vector<ll> my;
   vector<pair<ll, ll>> a;
   map<pair<ll, ll>, int> freq;
   for (int i = 0; i < n; i++)
   {
      ll l, r;
      cin >> l >> r;
      if (l == r)
      {
         my.push_back(l);
      }
      freq[{l, r}]++;
      a.push_back({l, r});
   }
   sort(all(my));
   auto ip = unique(all(my));
   my.resize(distance(my.begin(), ip));
   for (auto p : a)
   {
      ll l = p.first, r = p.second;
      ll dif = abs(r - l);
      if (dif == 0) {
         cout << (freq[p] == 1 ? 1 : 0);
         continue;
      }
      auto low = lower_bound(all(my), l);
      auto up = lower_bound(all(my), r);
      if ((low != my.end()) && (up != my.end()) && (*low == l) && (*up == r) && (up - low) == dif)
         cout << 0;
      else
         cout << 1;
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