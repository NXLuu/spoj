#include <iostream>
#define ll unsigned long long int
using namespace std;
int a[6] = {2, 3, 5, 61, 7, 23};

ll modulo(ll x, ll y, ll p) {
    if (y == 1)
        return x % p;
    ll temp = modulo(x, y / 2, p);
    if (y % 2 == 0)
        return (temp * temp) % p;
    else return (temp * temp % p) * x % p;
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
    for (int i = 0; i < 6; ++i){
        if (n > a[i])
            if (!millerTest(d, n, a[i]))
                return false;
    }
    return true;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        ll m;
        cin >> n;
        cin >> m;
        for (ll i = n ; i <= m; ++i) {
            if (isPrime(i))
                cout << i << endl;
        }
        cout << endl;
    }
    return 0;
}
