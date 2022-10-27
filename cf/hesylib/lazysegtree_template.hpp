#ifndef HESY_LAZYSEGTREE_HPP
#define HESY_LAZYSEGTREE_HPP 1

#include<hesylib/bumpallocator.hpp> // be care of memory bank size 

// [a, b]

const ll inf = 1e18;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
    ll mset = -inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(V<ll>& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid+1, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	ll query(int L, int R) {
		if (R < lo || hi < L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R < lo || hi < L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, ll x) {
		if (R < lo || hi < L) return;
		if (L <= lo && hi <= R) {
			if (mset != -inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid+1, hi);
		}
		if (mset != -inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = -inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

#endif // HESY_LAZYSEGTREE_HPP
