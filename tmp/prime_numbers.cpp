// prime numbers
// 12.02.2024

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

#define int long long

bool is_prime(int x) {
    if (x == 1) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }

    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<int> primes;
    int n = 100001;
    int t1 = chrono::steady_clock::now().time_since_epoch().count();
    for (int i = 1; i < n; ++i) {
        if (is_prime(i)) {
            primes.emplace_back(i);
        }
    }
    cout << primes.size() << '\n';
    cout << chrono::steady_clock::now().time_since_epoch().count() - t1;

//    for (auto p : primes) {
//        cout << p << ' ';
//    }

    return 0;
}
