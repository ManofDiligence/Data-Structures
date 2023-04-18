#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

int n, m, x1, y1, x2, y2;

bool check(int k) {
    int dx = abs(x1 - x2), dy = abs(y1 - y2);
    int dist = dx + dy;
    if (k >= dist) return true;
    int d = k - dist;
    int mx = min(n, m);
    if (d <= mx && (mx - d) % 2 == 0) return true;
    if (d > mx && d <= n + m - 2 && (n + m - 2 - d) % 2 == 0) return true;
    if (d > n + m - 2 && d <= 2 * mx && (d - n - m + 2) % 2 == 0) return true;
    return false;
}

int solve() {
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    int l = 0, r = 2*(n+m); // upper bound is 2*(n+m)
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l == 2*(n+m) ? -1 : l;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}
