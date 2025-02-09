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


vi prime_factorize(int n) {
   vi res;
   for (int i = 2; 1ll * i * i <= n; i++) {
      while (n % i == 0) {
         n /= i;
         res.push_back(i);
      }
   }
   if (n != 1) res.push_back(n);
   return res;
}

vi get_divisors(int n) {
   vi res;
   for (int i = 1; 1ll * i * i <= n; i++) {
      if (n % i == 0) {
         res.push_back(i);
         if (1ll * i * i != n) res.push_back(n / i);
      }
   }
   return res;
}