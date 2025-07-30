const int N = 2e5, oo = 2e18, MOD = 1e9+7;

int fact[N+5], inv[N+5];

int mod_pow( int b, int p, int m ) {
    int res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

void pre() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = mod_pow(fact[i], MOD-2, MOD); 
    }
}

int nCr(int n, int r) {
    if(r > n) return 0;
    return (fact[n] * inv[r] % MOD * inv[n - r] % MOD) % MOD;
}

int C(int n, int k) {
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res *= i;
    for (int i = 2; i <= k; ++i)
        res /= i;
    return res;
}

