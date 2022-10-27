// https://cses.fi/problemset/task/1735/ 
// segment tree, with lazy;
#include<hesylib/head.hpp>

const int mxN = 2e5+11;
struct {
  int l; int r;
  ll sum=0, set=0, inc=0;
} tree[mxN*3];

int n, a[mxN];

#define lch(x) x<<1
#define rch(x) x<<1|1
#define M ((tree[rt].l + tree[rt].r) / 2)
#define L (tree[rt].l)
#define R (tree[rt].r)

void pushup(int rt) {
  tree[rt].sum = tree[lch(rt)].sum + tree[rch(rt)].sum;
}

void build(int rt=1, int l=0, int r=n-1) {
  tree[rt].l = l, tree[rt].r = r;
  if(l==r) {tree[rt].sum = a[l]; return;}
  build(lch(rt), L, M);
  build(rch(rt), M+1, R);
  pushup(rt);
}

void calc_set(int rt) {
  tree[rt].sum = (R-L+1) * tree[rt].set;
}

void calc_inc(int rt, ll v) {
  tree[rt].sum += (R-L+1) * v;
}

void pushdown(int rt) {
  if (tree[rt].set) {
    tree[lch(rt)].set = tree[rch(rt)].set = tree[rt].set;
    calc_set(lch(rt)); calc_set(rch(rt));
    tree[lch(rt)].inc = tree[rch(rt)].inc = 0;
  }
  if (tree[rt].inc) {
    tree[rch(rt)].inc += tree[rt].inc;
    tree[lch(rt)].inc += tree[rt].inc;
    calc_inc(lch(rt), tree[rt].inc), calc_inc(rch(rt), tree[rt].inc);
  }
  tree[rt].set = tree[rt].inc = 0;
}


void inc(int l, int r, ll v, int rt=1) {  
  if (L > r || l > R) return;
  if (L==R) {tree[rt].sum += v; return;}
  if ( L >= l && R <= r) {
    tree[rt].inc += v;
    tree[rt].sum += (R-L+1) * v; return;
  }
  pushdown(rt);
  inc(l, r, v, lch(rt));
  inc(l, r, v, rch(rt));
  pushup(rt);
}

void tset(int l, int r, ll v, int rt=1) {
  if (L > r || l > R) return;
  if (L==R) {tree[rt].sum = v; return;}
  if ( L >= l && R <= r) {
    tree[rt].sum = (R-L+1) * v;
    tree[rt].set = v;
    tree[rt].inc = 0;
    return;
  }
  pushdown(rt);
  tset(l, r, v, lch(rt));
  tset(l, r, v, rch(rt));
  pushup(rt);
}

ll qry(int l, int r, int rt=1) {
  if (L > r || l > R) return 0;
  if ( L >= l && R <= r) {
    return tree[rt].sum;
  }
  pushdown(rt);
  ll ret = qry(l, r, lch(rt));
  ret += qry(l, r, rch(rt));
  return ret;
}

void solve() {
  int q;
  cin >> n >> q;
  FOR(i, 0, n) cin >> a[i];
  build();
  rep(q) {
    int type; cin >> type;
    if (type == 1) {
      int x, y, v; cin >> x >> y >> v; x--, y--;
      inc(x, y, v);
    } else if(type==2) {
      int x, y, v; cin >> x >> y >> v; x--, y--;
      tset(x, y, v);
    } else {
      int x, y; cin >> x >> y; x--, y--;
      cout << qry(x, y) << endl;
    }
  }
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
