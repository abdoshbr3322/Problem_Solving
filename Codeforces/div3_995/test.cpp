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
#define ll   long long
#define ull  unsigned long long
#define vi   vector<int>
#define vvi  vector<vi>
#define vll  vector<long long>
#define vvll  vector<vll>
#define float double
#define all(a) a.begin(), a.end()
#define all_r(a) a.rbegin(), a.rend()
#define sum_a(n) n*(n+1) / 2

void input2D(vvi &a, int n, int m){
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         int ai; cin >> ai;
         a[i].push_back(ai);
      }
   }
}

void input(vi &a, int n) {
   for (int i = 0; i < n; i++) {
      int ai; cin >> ai;
      a.push_back(ai);
   }
} 

vector<string> solution(const string &s)
{
  vector<string> result;
  int n = s.size();
  for (int i = 0; i < n; i+=2) {
    result.push_back(s.substr(i, 2));
  }
  if (result.back().size() == 1) result.back().push_back('_');
    return result; // Your code here
}



int main() {
   fastio;
   vector<string> s = solution("abc");
   for (auto i : s) cout << i << endl;

   // cin >> t;
   // while (t--) solve();
   return 0;
}

/*
   y = 7, x = 6 --> 6
   y = 8, x = 5 --> 5
   y = 9, --> 9

*/