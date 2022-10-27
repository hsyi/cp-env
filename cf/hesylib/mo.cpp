#include<hesylib/head.hpp>


void solve() {
    int n, q;
    cin >> n >> q;
    vi x(n);
    FOR(i, 0, n) cin >> x[i];
    V<pi> qs(q);
    rep(q) {
        int l, r;
        cin >> l >> r;
        qs.eb({l, r});
    }
    vi qsi(n);
    iota(all(qsi), 0);
    int block = (int)sqrt(n);
    int m = n/block;
    sort(all(qsi), [&](int lhs, int rhs) {
            if (qs[lhs].f/block == qs[rhs].f/block) {
                return qs[lhs].s < qs[rhs].s;
            } else {
                return qs[lhs].f/block < qs[rhs].f/block;
            }
            });
    int curres = 0;
    int curL = 0;
    int curR = 0;
    unordered_map<int, int> ms;
    vi out(m);
    FOR(i, 0, m) {
        FOR(j, 0, block) {
            int cl = qs[qsi[i*blcok + j]].f;
            int cr = qs[qsi[i*block + j]].s;
            if (j == 0) {
                curL = cl;
                curR = cl;
                ms.clear();
            }
            while(curL > cl) {
                if(ms.count(curL)) {
                    ms[x[curL]]++;
                } else {
                    ms.count[curL] = 1;
                }
                curL--;
            }
            while(curL < cl) {
                if(ms[x[curL]] > 1) {
                    ms[x[curL]]--;
                } else {
                    ms.erase(ms.find(x[curL]));
                }
                curL++;
            }
            while(curR <= cr) {
                if(ms.count(x[curR])) {
                    ms[x[curR]]++;
                } else {
                    ms[x[curR]] = 1;
                }
                curR++;
            }

        }
    }
    sort(all(q));

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
