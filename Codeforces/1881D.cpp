// https://codeforces.com/problemset/problem/1881/D
// 12.02.2024

#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define int long long

const int MAXA = 1e6 + 1;

vector<int> primes;
map<int, int> count_primes;

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

void calculate_primes(int x) {
    int idx = 0;
    while (x != 1) {
        if (x % primes[idx] == 0) {
            count_primes[primes[idx]]++;
            x /= primes[idx];
        } else {
            idx++;
            if (primes[idx] * primes[idx] > x) {
                if (is_prime(x)) {
                    count_primes[x]++;
                }
                return;
            }
        }
    }
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 1; i < MAXA; ++i) {
        if (is_prime(i)) {
            primes.emplace_back(i);
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        count_primes.clear();
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            calculate_primes(x);
        }

        bool flag = true;

        for (auto [p, c]: count_primes) {
            if (c % n != 0) {
                flag = false;
            }
        }

        cout << (flag ? "YES" : "NO") << '\n';


    }

    return 0;
}
