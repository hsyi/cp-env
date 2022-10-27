// atcoder beginer contest 130 F
#include<hesylib/head.hpp>

const int mxN=1e5+11;
struct Point{
    db x, y, dx, dy;
} ps[mxN];
int n;

db area(db t) {
    db mnX=2e10, mxX=-2e10;
    db mnY=2e10, mxY=-2e10;
    FOR(i, 0, n) {
        db nx = ps[i].x + ps[i].dx*t;
        db ny = ps[i].y + ps[i].dy*t;
        debug(ps[i].x, ps[i].y);
        debug(nx, ny);
        ckmin(mnX, nx);
        ckmin(mnY, ny);
        ckmax(mxX, nx);
        ckmax(mxY, ny);
    }
    return (mxX-mnX) * (mxY -mnY);
}

void solve() {
    cin >> n;
    FOR(i,0,n) {
        int x, y;
        char ch;
        db dx=0, dy=0;
        cin >> x >> y >> ch;
        if (ch == 'D') dy=-1;
        if (ch == 'U') dy=1;
        if (ch == 'L') dx=-1;
        if (ch == 'R') dx=1;
        ps[i] = {x, y, dx, dy};
    }
    db l=0, r=1e10;
    db ans = 1e18;
    rep(200) {
        db mid1 = l + (r-l)/3;
        db mid2 = l + 2*((r-l)/3);
        debug(mid1, mid2);
        db a1 = area(mid1);
        db a2 = area(mid2);
        debug(a1, a2, l, r);
        ckmin(ans, a1);
        ckmin(ans, a2);
        if (a1 > a2) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    cout << setprecision(12) << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#if HESYDEBUG
    freopen("tmp/in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int T=1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
