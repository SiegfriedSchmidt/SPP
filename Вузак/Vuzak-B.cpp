//  
// 14.02.2024

#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define int long long
#define mp make_pair

const int MAXN = 2 * 1e5 + 1;
const int INF = 1e9 + 7;

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    pair<int, int> a[m];

    int ml = INF;
    int mr = -INF;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        ml = min(ml, l);
        mr = max(mr, r);
        a[i] = {l, r};
    }

    bool flag = false;
    for (int i = 0; i < m; ++i) {
        if (a[i] == mp(ml, mr)) {
            flag = true;
        }
    }

    cout << (flag ? "YES" : "NO") << '\n';




    return 0;
}

