#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi; 
typedef vector<pair<int,int>> vpi; 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second

int N,L;
vi w,x,d;

ifstream fin("meetings.in");
ofstream fout("meetings.out");

void init() {
    fin >> N >> L;
    w.rsz(N), x.rsz(N), d.rsz(N);
    F0R(i,N) fin >> w[i] >> x[i] >> d[i];
    vi inds(N); iota(all(inds),0);
    sort(all(inds),[](int a, int b) { return x[a] < x[b]; });
    vi W,X,D;
    trav(t,inds) {
        W.pb(w[t]);
        X.pb(x[t]);
        D.pb(d[t]);
    }
    swap(w,W), swap(x,X), swap(d,D);
}

int getTime() {
    vi lef, rig;
    F0R(i,N) {
        if (d[i] == -1) lef.pb(x[i]);
        else rig.pb(x[i]);
    }
    vpi v;
    F0R(i,sz(lef)) v.pb({lef[i],w[i]});
    F0R(i,sz(rig)) v.pb({L-rig[i],w[sz(lef)+i]});
    sort(all(v));
    int tot = 0; trav(t,v) tot += t.s;
    trav(t,v) {
        tot -= 2*t.s;
        if (tot <= 0) return t.f;
    }
    return 0;
}

int main() {
    init();
    int t = getTime(); 
    queue<int> rig;
    int ans = 0;
    F0R(i,N) {
        if (d[i] == -1) {
            while (sz(rig) && rig.front()+2*t < x[i]) rig.pop();
            ans += sz(rig);
        } else rig.push(x[i]);
    }
    fout << ans << "\n";
    return 0;
}
