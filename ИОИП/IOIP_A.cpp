//  
// 17.02.2024

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <numeric>

using namespace std;

#define int long long
const int MAXN = 5 * 1e5 + 1;
int a[MAXN];
int n;

int find_maxd(int l, int r) {
    int maxd = 0;
    for (int i = max(0ll, l); i + 1 < min(n, r); ++i) {
        maxd = max(maxd, abs(a[i] - a[i + 1]));
    }
    return maxd;
}

int find_maxd_change(int ind, int v) {
    int p = a[ind];
    a[ind] = v;
    int newd = find_maxd(ind - 3, ind + 5);
    a[ind] = p;
    return newd;
}

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int maxd = find_maxd(0, n);

    vector<int> idx;
    for (int i = 0; i + 1 < n; ++i) {
        int d = abs(a[i] - a[i + 1]);
        if (d == maxd) {
            idx.emplace_back(i);
        }
    }

    int mind = 1e9;
    int mini = -1;
    int minv = -1;
    if (idx.size() == 1) {
        int ind = idx[0];
        if (ind - 1 >= 0) {
            int newv = (a[ind - 1] + a[ind + 1]) / 2;
            int newd = find_maxd_change(ind, newv);
            if (newd < mind) {
                mind = newd;
                mini = ind;
                minv = newv;
            }
        } else {
            int newd = find_maxd_change(ind, a[ind + 1]);
            if (newd < mind) {
                mind = newd;
                mini = ind;
                minv = a[ind + 1];
            }
        }

        if (ind + 2 < n) {
            int newv = (a[ind] + a[ind + 2]) / 2;
            int newd = find_maxd_change(ind + 1, newv);
            if (newd < mind) {
                mind = newd;
                mini = ind + 1;
                minv = newv;
            }
        } else {
            int newd = find_maxd_change(ind + 1, a[ind]);
            if (newd < mind) {
                mind = newd;
                mini = ind + 1;
                minv = a[ind];
            }
        }
    } else if (idx.size() == 2) {
        if (idx[0] + 1 == idx[1]) {
            int newv = abs(a[idx[0]] + a[idx[1] + 1]) / 2;
            int newd = find_maxd_change(idx[0] + 1,newv);
            if (newd < mind) {
                mind = newd;
                mini = idx[0] + 1;
                minv = newv;
            }
        } else {
            mini = 0;
            minv = a[mini];
        }
    } else {
        mini = 0;
        minv = a[mini];
    }

    a[mini] = minv;

    cout << find_maxd(0, n) << ' ' <<  mini + 1 << ' ' << minv;


    return 0;
}

/*
6
1 4 10 8 6 5

 */
