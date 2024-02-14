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
    int n, a, b;
    string s;
    cin >> n >> s >> a >> b;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += (s[i] == '1' ? 1 : 0);
    }

    int cntA = max(0ll, cnt - a);
    int cntB = max(0ll, cnt - b);
    if (cntB == 0) {
        cntB = (b - cnt) % 2;
    }

    if (cntA < cntB) {
        cout << "Petya";
    } else if (cntB < cntA) {
        cout << "Vadim";
    } else {
        cout << "Draw";
    }

    return 0;
}

