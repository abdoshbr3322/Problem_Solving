const int N = 1e6+4, oo = 2e18;

const int base_1 = 127, base_2 = 131, MOD_1 = 1e9+7, MOD_2 = 2e9+11;
int pw_1[N], pw_2[N];


void init() {
    pw_1[0] = pw_2[0] =1;
    for (int i = 1; i < N; i++) {
        pw_1[i] = (pw_1[i-1] * base_1) % MOD_1;
        pw_2[i] = (pw_2[i-1] * base_2) % MOD_2;
    }
    
}

struct Hash {

private:
    pair<int, int> pre[N];

public:
    Hash(string&s) {
        int a = 0,b = 0;
        for(int i = 0; i < (int)s.size(); i++) {
            a = (a * base_1) % MOD_1;
            b = (b * base_2) % MOD_2;
            a = (a + s[i]) % MOD_1;
            b = (b + s[i]) % MOD_2;
            pre[i] = {a, b};
        }
    }
    pair<int, int> get_hash(int l, int r) {
        pi ret = pre[r];
        int sz = r - l + 1;
        --l;
        if(l >= 0) {
            ret.first -= (pre[l].first * pw_1[sz]) % MOD_1;
            if (ret.first < 0) ret.first += MOD_1;

            ret.second -= (pre[l].second * pw_2[sz]) % MOD_2;
            if (ret.second < 0) ret.second += MOD_2;
        }
        return ret;
    }

};
