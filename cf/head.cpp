#include<hesylib/head.hpp>

void solve() {
}

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#if HESYDEBUG
  freopen("tmp/in", "r", stdin);
  //freopen("out", "w", stdout);
#endif
  int T=1;
  cin >> T;
  FOR(i, 0, T) {
    // cout << "Case #"<<i+1<<": ";
    solve();
  }
  return 0;
}
