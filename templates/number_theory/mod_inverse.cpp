int mod_pow( int b, int p, int m ) {
    int res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}



int gcd(int a, int b, int& x, int& y) { // extended euclidean
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int mod_inv(int n, int m) {
    int x, y;
    int g = gcd(n, m, x, y);
    if (g == 0) {
        // no solution
    }
    x = (x % m + m) % m;
    return x;
}
