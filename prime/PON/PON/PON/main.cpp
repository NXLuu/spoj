#include <iostream>
#define ll unsigned long long int
using namespace std;
int a[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 61, 23, 13, 1662803, 31, 73};

ll modMul(ll x, ll y, ll p) {
    if (y == 1)
        return x % p;
    ll temp = modMul(x, y / 2, p);
    if (y % 2 == 0)
        return (temp + temp) % p;
    else return (((temp + temp) % p) + x) % p;
}

ll modulo(ll x, ll y, ll p) {
    if (y == 1)
        return x % p;
    ll temp = modulo(x, y / 2, p);
    if (y % 2 == 0)
        return modMul(temp, temp, p);
        else return modMul(modMul(temp, temp, p), x, p);
}



bool millerTest(ll d, ll n,ll a) {
    ll x = modulo(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }
    return false;
}

bool isPrime(ll n) {
    for (int i = 0 ; i < 4; ++i)
        if (a[i] == n)
            return true;
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;
    ll d = n - 1;
    if (n % 2 == 0)
        return false;
    while (d % 2 == 0) {
        d /= 2;
    }
    for (int i = 0; i < 19; ++i){
        if (n > a[i])
        if (!millerTest(d, n, a[i]))
            return false;
    }
    return true;
}

int main() {
    ll t = 0;
//    cin >> t;
//    while(t--) {
//        ll n;
//        cin >> n;
//        if (isPrime(n))
//            cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
    for (ll i = 1; i <= 10000000; ++i)
        if (isPrime(i)) {
            ++t;
            cout << i << endl;
        }
    cout << t;
    return 0;
}
