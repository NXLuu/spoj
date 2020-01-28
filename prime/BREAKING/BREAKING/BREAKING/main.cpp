#include <iostream>

using namespace std;
int cnt = 1;
void solve(long n) {
    cout << "Case " << cnt << ": ";
    ++cnt;
    long i = 2;
    while (n != 1 || i * i < n) {
        if (n % i == 0) {
            cout << i << " ";
            while (n % i == 0) {
                n /= i;
            }
        }
        ++i;
    }
    cout << endl;
}


int main() {
    int t;
    cin >> t;
    while (t --) {
        long n;
        cin >> n;
        solve(n);
    }
    
    return 0;
}
