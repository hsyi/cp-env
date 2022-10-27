// https://cses.fi/problemset/task/1694 
// max flow, edmonds-karp algorithm, O(n^2m)
#include<hesylib/head.hpp>
const int mxM = 1e3+11;
const int mxN = 507;
struct Ed{
  int u, v, rev_id;
  ll cap, cur_flow;
};
Ed edges[2*mxM];
vi adj[mxN];
int par[mxN];
int n, m;

ll bfs(int s, int t) {
  memset(par, -1, sizeof(par));
  ll flow=0;
  ll inf = 0x3f3f3f3f3f3f3f3f;
  queue<pi> mq;
  par[s] = s;
  for(mq.push({s, inf}); !mq.empty(); mq.pop()) {
    auto [u, curflow] = mq.front();
    each(eid, adj[u]) {
      auto ed = edges[eid];
      if(par[ed.v] != -1) continue;
      if (ed.cur_flow < ed.cap) {
        ll tmpflow = curflow;
        ckmin(tmpflow, ed.cap - ed.cur_flow);
        par[ed.v] = eid;
        if(ed.v==t) {
          return tmpflow;
        }
        mq.push({ed.v, tmpflow});
      }
    }
  }
  return flow;
}

ll maxflow(int s, int t) {
  ll mxflow = 0;
  while(1) {
    ll cur_flow = bfs(s,t);
    debug(cur_flow, mxflow);
    if (!cur_flow) return mxflow;
    mxflow += cur_flow;
    int cp = par[t];
    while(edges[cp].u != s) {
      edges[cp].cur_flow += cur_flow;
      edges[edges[cp].rev_id].cur_flow -= cur_flow;
      cp = par[edges[cp].u];
    }
    edges[cp].cur_flow += cur_flow;
    edges[edges[cp].rev_id].cur_flow -= cur_flow;
  }
  return 0; 
}

void solve() {
  cin >> n >> m;
  FOR(i, 0, m) {
    int a, b ,c;
    cin >> a >> b >> c;
    edges[i*2] = {a, b, i*2|1, c, 0};
    edges[i*2|1] = {b, a, i*2, 0, 0};
    adj[a].eb(i*2);
    adj[b].eb(i*2|1);
  }
  debug("init");
  cout << maxflow(1, n) << endl;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#if HESYDEBUG
  freopen("tmp/in", "r", stdin);
  //freopen("out", "w", stdout);
#endif
  int T=1;
  while(T--) {
      solve();
  }
  return 0;
}
