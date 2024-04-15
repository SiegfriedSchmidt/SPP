//  
// 22.03.2024

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define int long long

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    double v, angle;
    cin >> v >> angle;

    angle = angle / 180 * M_PI;
    double vy = v * sin(angle);
    double vx = v * cos(angle);

    double t = 2 * vy / 10;
    double d = vx * t;

    cout << fixed << setprecision(2) << d << '\n';

    return 0;
}
