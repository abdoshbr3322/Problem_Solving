// بسم الله الرحمن الرحيم

#include <bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream& os, vector<T>& v) { for (auto& i : v) os << i << ' '; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& i : v) is >> i; return is; }
#define FreePalestine                \
   ios_base::sync_with_stdio(false); \
   cin.tie(NULL);                    \
   cout.tie(NULL)

#define int ll
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<long long>
#define vvll vector<vll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define all(a) a.begin(), a.end()
#define all_r(a) a.rbegin(), a.rend()

int n, m;
vvi adj;
vi vis, topo, indegree;

void bfs() {
   queue<int> q;
   for (int i = 1; i <= n; i++) {
      if (indegree[i] == 0) {
         q.push(i);
         vis[i] = 1;
         topo.push_back(i);
      }
   }

   while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int v : adj[cur]) {
         if (vis[v]) continue;
         indegree[v]--;
         if (indegree[v] == 0) {
            q.push(v);
            vis[v] = 1;
            topo.push_back(v);
      }
      }
   }
}

