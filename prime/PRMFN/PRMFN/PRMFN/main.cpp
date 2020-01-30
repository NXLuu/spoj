#include <iostream>
#define ll unsigned long long int
using namespace std;
int a[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 61, 23, 13, 1662803, 31, 73};
int check[4] = {2, 3, 5, 7};

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
        x = modMul(x, x, n);
        d *= 2;
        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }
    return false;
}

bool isPrime(ll n) {
    ll temp = n;
    while(temp != 0) {
        ll du = temp % 10;
        if (du != 2 && du != 3 && du != 5 && du != 7)
            return false;
        temp /= 10;
    }
    for (int i = 0 ; i < 4; ++i)
        if (a[i] == n)
            return true;
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;
    ll d = n - 1;
    
    while (d % 2 == 0) {
        d /= 2;
    }
    if (n % 2 == 0)
        return false;
    for (int i = 0; i < 19; ++i){
        if (n > a[i])
            if (!millerTest(d, n, a[i]))
                return false;
    }
    return true;
}

//string solve(ll n) {
//    string s = to_string(n);
//    int dem = s.size();
//    for (int i = 0; i < dem ; ++i) {
//        for (int j = 3; j >= 0; --j) {
//            if (s[i] > check[j]) {
//                s[i] = check[j];
//                for (int k = i; k < dem; ++k)
//                    s[k] = '7';
//                return s;
//            }
//        }
//        if (s[i] < check[0])
//            s[i - 1] =
//    }
//}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll cnt = 1;
        ll n;
        cin >> n;
        for (ll i = n; i > 0; --i) {
            if (isPrime(i)) {
                cout << "Case " << cnt << ": " << i << endl;
                break;
            }
        }
//        solve();
    }
//    for (int i = 1; i <= 100; ++i) {
//        if (isPrime(i))
//            cout << i << endl;
//    }
    return 0;
}
