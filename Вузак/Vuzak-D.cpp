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
int n, X;
int ans = 0;
string s;

void func(int idx, int pr) {
    if (idx == n) {
        ans += 1;
    }
    for (int i = 1; i <= X; ++i) {
        if (idx == -1) {
            func(idx + 1, i);
            continue;
        }
        if (s[idx] == '<' && pr < i) {
            func(idx + 1, i);
        } else if (s[idx] == '>' && pr > i) {
            func(idx + 1, i);
        } else if (s[idx] == '=' && pr == i) {
            func(idx + 1, i);
        }
    }
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> X;
    cin >> s;

    func(-1, -1);
    cout << ans;


    return 0;
}

