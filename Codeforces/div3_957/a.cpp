// بسم الله الرحمن الرحيم

#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cstring>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define ll        long long
#define ull       unsigned long long
#define vi        vector<int>
#define vvi       vector<vi>
#define vll       vector<long long>
#define vvll      vector<vll>
#define float     double
#define all(a)    a.begin(), a.end()
#define all_r(a)  a.rbegin(), a.rend()
#define sum_a(n)  n*(n+1) / 2

void input(vi &a, int n) {
   for (int i = 0; i < n; i++) {
      int ai; cin >> ai;
      a.push_back(ai);
   }
} 

void solve() {
   int a, b, c; cin >> a >> b >> c;
   vector <int>v = {a, b, c};
   for (int i = 0; i < 5; i++) {
      int mini =  INT_MAX;
      int min_;
      for (int i = 0 ; i <  3; i++) {
         if (v[i] < mini) {
            mini = v[i];
            min_ = i;
         }
      }
      v[min_] += 1;
   }
   cout << accumulate(all(v), 1, [](int a, int b) {
      return a * b;
   }) << endl;
}


int main() {
   fastio;
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t; t = 1;
   cin >> t;
   while (t--) solve();
   return 0;
}