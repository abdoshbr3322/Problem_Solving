
const int N = 1e6+4, oo = 2e18;
const int base_1 = 127, base_2 = 131, MOD_1 = 1e9+7, MOD_2 = 2e9+11;
int inv1, inv2, pw_1[N], pw_2[N];


int mod_pow( int b, int p, int m ) {
    int res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

void init() {
    pw_1[0] = pw_2[0] = 1;
    
    inv1 = mod_pow(base_1, MOD_1-2, MOD_1);
    inv2 = mod_pow(base_2, MOD_2-2, MOD_2);
    for (int i = 1; i < N; i++) {
        pw_1[i] = (pw_1[i-1] * base_1) % MOD_1;
        pw_2[i] = (pw_2[i-1] * base_2) % MOD_2;
    }
}

struct Hashing
{
    
    deque<char> deq;
    int hash_1, hash_2, len;

    Hashing(): hash_1(0), hash_2(0), len(0) {}

    

    void push_back(char c) {
        int d = (c-'a' + 1);
        hash_1 = (hash_1 * base_1) % MOD_1 + d;
        hash_1 %= MOD_1;

        hash_2 = (hash_2 * base_2) % MOD_2 + d;
        hash_2 %= MOD_2;

        len++;
        deq.push_back(c);
    }

    void pop_back() {
        if (len == 0) return;
        int d = (deq.back() - 'a' + 1);
        
        hash_1 = ((hash_1 - d + MOD_1) % MOD_1) * inv1;
        hash_1 %= MOD_1;

        hash_2 = ((hash_2 - d + MOD_2) % MOD_2) * inv2;
        hash_2 %= MOD_2;

        deq.pop_back();
        len--;
    }

    void push_front(char c) {
        int d = (c - 'a' + 1);
        
        hash_1 = (d * pw_1[len]) % MOD_1 + hash_1;
        hash_1 %= MOD_1;

        hash_2 = (d * pw_2[len]) % MOD_2 + hash_2;
        hash_2 %= MOD_2;

        len++;
        deq.push_front(c);
    }

    void pop_front() {
        if (len == 0) return;

        int d = deq.front() - 'a' + 1;
        
        hash_1 = hash_1 - ((d * pw_1[len-1]) % MOD_1) + MOD_1;
        hash_1 %= MOD_1;

        hash_2 = hash_2 - ((d * pw_2[len-1]) % MOD_2) + MOD_2;
        hash_2 %= MOD_2;

        deq.pop_front();
        len--;
    }
    pair<int, int> get_hash() {
        return make_pair(hash_1, hash_2);
    }
};
