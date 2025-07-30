const int N = 2e5, K = 23, oo = 2e18;
int Table[N][K + 1], lg[N+1];

void pre_log() {
    lg[0] = lg[1] = 0;
    for (int i = 2; i <= N; i++) {
        lg[i] = lg[i/2] + 1;
    }
}

int merge(int a, int b) {
    return max(a, b); // change later
}

void build(vi& array, int n) {
    for (int i = 0; i < n; i++) {
        Table[i][0] = array[i];
    }

    for (int pw = 1; (1ll << pw) <= n; pw++) {
        for (int i = 0; ((i + (1ll << pw)) <= n); i++) {
            Table[i][pw] = merge(Table[i][pw-1], Table[i + (1ll << (pw-1))][pw-1]);
        }
    }
}

int query(int l, int r) { // O(Log(n))
    int ans = -oo; // change later

    int range = (r - l + 1);
    for (int pw = 21; pw >= 0; pw--) {
        if ((range >> pw) & 1) {
            ans = merge(ans, Table[l][pw]);
            l += (1ll << pw);
        }
    }
    return ans; 
} 


int query2(int l, int r) { // O(1) ->> Only works with 
    int range = (r - l + 1);
    int pw =  lg[range];

    return merge(Table[l][pw], Table[r- (1ll << pw) + 1][pw]);
}