//
// 05.03.2024

#include <iostream>
#include <vector>

using namespace std;

#define int long long

const int INF = 1e9;

int n, k;
int a[100001];

int func(int v) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            s += abs(a[i] - v);
        } else {
            s += abs(a[i] - (v - k));
        }
    }
    return s;
}

int func2(int v) {
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            s += abs(a[i] - v);
        } else {
            s += abs(a[i] - (v + k));
        }
    }
    return s;
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int l = -1e9, r = 1e9;
    while (l + 2 < r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (func(mid1) > func(mid2)) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    int ans = min(min(func(l), func(l + 1)), func(l + 2));

    l = -1e9, r = 1e9;
    while (l + 2 < r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (func2(mid1) > func2(mid2)) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    ans = min(ans, min(min(func2(l), func2(l + 1)), func2(l + 2)));

    cout << ans;
    return 0;
}
