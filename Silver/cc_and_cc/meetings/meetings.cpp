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
typedef vector<pair<int, int>> vpi;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second

ifstream fin("meetings.in");
ofstream fout("meetings.out");

void readInput(int& N, int& L, vi& x, vi& w, vi& d) {
    fin >> N >> L;
    x.rsz(N);
    w.rsz(N);
    d.rsz(N);
    F0R(i, N) fin >> x[i] >> w[i] >> d[i];
}

ll calculateTotalWeight(const vi& w) {
    ll total_weight = 0;
    trav(weight, w) total_weight += weight;
    return total_weight;
}

ll determineT(int N, int L, const vi& x, const vi& w, const vi& d, ll total_weight) {
    vi lef, rig;
    F0R(i, N) {
        if (d[i] == -1) lef.pb(x[i]);
        else rig.pb(x[i]);
    }

    vpi events;
    F0R(i, sz(lef)) events.pb({lef[i], w[i]});
    F0R(i, sz(rig)) events.pb({L - rig[i], w[sz(lef) + i]});

    sort(all(events));
    ll weight = total_weight;
    trav(event, events) {
        weight -= 2 * event.s;
        if (weight <= 0) return event.f;
    }
    return 0;
}

int countMeetings(int N, ll T, const vi& x, const vi& d) {
    queue<ll> right_moving_cows;
    int meetings = 0;

    F0R(i, N) {
        if (d[i] == 1) {
            right_moving_cows.push(x[i]);
        } else {
            while (!right_moving_cows.empty() && right_moving_cows.front() + 2 * T < x[i]) {
                right_moving_cows.pop();
            }
            meetings += sz(right_moving_cows);
        }
    }
    return meetings;
}

int main() {

    int N, L;
    vi x, w, d;
    readInput(N, L, x, w, d);

    ll total_weight = calculateTotalWeight(w);
    ll T = determineT(N, L, x, w, d, total_weight);

    vpi cows(N);
    F0R(i, N) cows[i] = {x[i], d[i]};
    sort(all(cows), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });

    vi x_sorted(N), d_sorted(N);
    F0R(i, N) {
        x_sorted[i] = cows[i].first;
        d_sorted[i] = cows[i].second;
    }

    int meetings = countMeetings(N, T, x_sorted, d_sorted);
    fout << meetings << "\n";

    return 0;
}
