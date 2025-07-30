void IS_BRIDGE(int v,int to);
 
int n; 
vvi adj;
vector<bool> vis;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}


void solve() {
    adj.assign(n, { });
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);

    // input the edges

    timer = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i])
            dfs(i);
    }
}


signed main() {
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
