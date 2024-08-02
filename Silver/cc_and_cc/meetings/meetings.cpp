// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// ifstream fin("meetings.in");
// ofstream fout("meetings.out");

// struct Cow {
//     ll x,finishing_time;
//     int w,d;
// };

// int main() {

//     int N, L;
//     fin >> N >> L;

//     ll total_weight = 0;
//     vector<Cow> cows(N);
//     for (int i = 0; i < N; i++) {
//         fin >> cows[i].x >> cows[i].w >> cows[i].d;
//         total_weight += cows[i].w;
//     }
//     sort(cows.begin(),cows.end(),[](Cow a, Cow b){return a.d < b.d;});

//     vector<ll> finishing_times(N);
//     for (int i = 0; i < N; i++) {
//         if (cows[i].d == -1) {
//             finishing_times[i] = cows[i].x;
//         } else {
//             finishing_times[i] = L - cows[i].x;
//         }
//     }
//     sort(cows.begin(),cows.end(),[](Cow a, Cow b){return a.x < b.x;});
    
//     for (int i = 0; i < N; i++) {
//         cows[i].finishing_time = finishing_times[i];
//     }
//     sort(cows.begin(),cows.end(),[](Cow a, Cow b){return a.finishing_time < b.finishing_time;});

//     ll T;
//     ll weight = 0;
//     for (Cow cow : cows) {
//         weight += cow.w;
//         T = cow.finishing_time;
//         if (weight >= total_weight/2) break;
//     }  

//     ll meetings = 0;
//     queue<Cow> right_moving_cows;
//     for (int i = 0; i < N; i++) {
//         if (cows[i].d == 1) {
//             right_moving_cows.push(cows[i]);
//         } else {
//             while (!right_moving_cows.empty() && right_moving_cows.front().x + 2 * T < cows[i].x) {
//                 right_moving_cows.pop();
//             }
//             meetings += right_moving_cows.size();
//         }
//     }
//     fout << meetings << endl;
        
// }

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

ifstream fin("meetings.in");
ofstream fout("meetings.out");

int N,L;
vi w,x,d;

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
    } return 0;
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
