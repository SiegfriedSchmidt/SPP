//  
// 22.02.2024

#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

#define int long long

void print_bin8(unsigned int x) {
    cout << x << ' ' << bitset<8>(x) << ' ';
}

void print_bin16(unsigned int x) {
    cout << bitset<16>(x) << '\n';
}

signed main() {
    print_bin8(144);
    cout << "\n\n";
    print_bin8(145);
    cout << "permit\n";
    print_bin8(146);
    cout << "permit\n";
    print_bin8(147);
    cout << "permit\n";
    print_bin8(148);
    cout << "permit\n";
    print_bin8(149);
    cout << "permit\n";
    print_bin8(150);
    cout << "permit\n";
    print_bin8(151);
    cout << "permit\n";
    print_bin8(152);
    cout << "deny\n";
    print_bin8(153);
    cout << "deny\n";
    print_bin8(156);
    cout << "deny\n";
    print_bin8(157);
    cout << "deny\n";
    print_bin8(154);
    cout << "permit\n";
    print_bin8(155);
    cout << "permit\n";
    print_bin8(158);
    cout << "permit\n";
    // 23.149.22.8/29
    // 8 - 16

    return 0;
}
