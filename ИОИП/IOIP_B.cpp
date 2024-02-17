//  
// 17.02.2024

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    string t;
    cin >> s >> t;

    vector<pair<int, int>> arr;
    int idx = t.size() - 1;
    int del_i = 2;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (idx >= 0 && s[i] == t[idx]) {
            arr.emplace_back(i, idx);
            --idx;
        } else {
            del_i = i;
        }
    }

    if (idx != -1) {
        cout << "NO";
        return 0;
    }

    if ((del_i + 1) % 2 == 0) {
        cout << "YES";
    } else {
        sort(arr.begin(), arr.end());
        int i2 = 0;
        while (i2 < arr.size() && arr[i2].first < del_i) {
            ++i2;
        }
        if (i2 == arr.size()) {
            cout << "NO";
            return 0;
        }

        if (t[arr[i2].second] == s[del_i]) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }


//    if (arr.empty()) {
//        cout << "YES";
//        return 0;
//    }
//
//    if (arr[0] == 1) {
//        cout << "NO";
//        return 0;
//    }

//    int n = arr.size();
//    int l = 0;
//    int r = n - 1;
//
//    int rev = 0;
//
//    bool flag = true;
//    while (l < r) {
//        while (r >= 0 && (arr[r] + rev) % 2 == 0) {
//            --r;
//        }
//        while (l < n && (arr[l] + rev) % 2 == 0) {
//            ++l;
//        }
//
//        if (l < r) {
//            ++rev;
//        }
//    }
//    cout << "YES";


    return 0;
}
