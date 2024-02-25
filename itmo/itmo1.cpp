//  
// 24.02.2024

#include <iostream>

using namespace std;

#define int long long

signed main() {
    int d = 0;
    int s = 0;
//    for (int i = 0; i < 30; ++i) {
//        cout << 3 * (1 << i) << '\n';
//    }
//
//    for (int i = 0; i < 30; ++i) {
//        s += (1 << i);
//    }
//    cout << s << '\n';
    s = (1 << 30) - 1;
    d = 3 * (1 << 29);

    s /= 3;
    d /= 3;
    cout << s << ' ' << d << '\n';

    cout << hex << s << '\n';
    cout << hex << d << '\n';

    string s1 = "00100000004000000000000000000003FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5D1008F93C2E742";
//    string s1 = "abc0";
    int sum1 = 0;
    for (auto c : s1) {
        if (c >= '0' && c <= '9') {
            sum1 += c - '0';
        } else {
            sum1 += c - 'A' + 10;
        }
    }

    cout << dec << sum1 << '\n';
    return 0;
}
