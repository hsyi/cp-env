#include<hesylib/head.hpp>
 
const int mxN = 2e5+11;
 
vi adj[mxN];
int seq[mxN], tin[mxN], ts, ch[mxN], tsz[mxN], fa[mxN], depth[mxN];
int tree[mxN*2];
int a[mxN];
 
void dfs_sz(int u=1) {
  tsz[u] = 1;
  each(v, adj[u]) {
    depth[v] = depth[u]+1;
    fa[v] = u;
    adj[v].erase(find(all(adj[v]), u));
    dfs_sz(v);
    tsz[u] += tsz[v];
    if(tsz[v] > tsz[adj[u][0]]) swap(v, adj[u][0]);
  }
}
 
void dfs_hld(int u=1) {
  seq[ts] = u;
  tin[u] = ts++;
  each(v, adj[u]) {
    ch[v] = (v==adj[u][0]?ch[u]:v);
    dfs_hld(v);
  }
}
 
void build() {
  FOR(i, 0, ts) tree[i+ts] = a[seq[i]];
  ROF(i, 1, ts) tree[i] = max(tree[i<<1], tree[i<<1|1]);
}
 
void upd(int p, int x) {
  for(tree[p+=ts] = x, p>>=1; p>0; p>>=1) tree[p] = max(tree[2*p], tree[2*p+1]);
}
 
int qry(int l, int r) {
  int res = 0;
  for (l += ts, r += ts; l <= r; l >>= 1, r >>= 1) {
    if (l%2==1) ckmax(res, tree[l++]);
    if (r%2==0) ckmax(res, tree[r--]);
  }
  return res;
}
 
int qry_hld(int x, int y) {
  int ret =0;
  while(ch[x]^ch[y]) {
    if(depth[ch[x]] < depth[ch[y]]) swap(x, y);
    ckmax(ret, qry(tin[ch[x]], tin[x]));
    x = fa[ch[x]];
  }
  if(depth[x] < depth[y]) swap(x, y);
  ckmax(ret, qry(tin[y], tin[x]));
  return ret;
}
 
void solve() {
  int n, q;
  cin >> n >> q;
  ts = 0;
  FOR(i, 1, n+1) cin >> a[i];
  debug(n,q);
  rep(n-1) {
    int u, v;
    cin >> u >> v;
    adj[u].eb(v);
    adj[v].eb(u);
  }
  dfs_sz();
  ch[1] = 1;
  dfs_hld();
  assert(n==ts);
  build();
  rep(q) {
    int qt; cin >> qt;
    if(qt==1) {
      int s, x; cin >> s >> x;
      upd(tin[s], x);
    } else {
      int x, y;
      cin >> x >> y;
      cout << qry_hld(x, y) << " ";
    }
  }
  cout << "\n";
  
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
