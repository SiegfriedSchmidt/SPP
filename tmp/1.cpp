// 
// 10.02.2024

#include <algorithm>
#include <cctype>
#include <chrono>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 2e5;
const int MOD = 100000000;

int func(int x, int p) {
    if (p == 1) {
        return x;
    }
    return func(x * x % MOD, p / 2) * (p % 2 != 0 ? x : 1) % MOD;
}

int binpow(int a, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        int x = binpow(a, n / 2);
        return x * x % MOD;
    }
    return binpow(a, n - 1) * a % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << func(3, 4);


}
