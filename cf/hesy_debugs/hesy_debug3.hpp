#include <bits/stdc++.h>

using namespace std;

#define debugc(x) { x }

//void _print() {cerr << "]\n\033[0m";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {cerr<<t; if (sizeof...(v)) cerr << ", "; _print(v...);}
//#define debug(x...) {cerr <<  "\033[1;92m" << __LINE__ << "L:\033[1;95m[" << #x << "]\033[1;97m = \033[1;94m["; _print(x);}
#define debug(x...) {cerr <<__LINE__ << "L:[" << #x << "] = ["; _print(x);}
//#define debug(x...) cerr << __LINE__ << "L:[" << #x << "] = ["; cerr << x << "]\n";
