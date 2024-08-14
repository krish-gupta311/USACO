#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

ifstream fin("reststops.in");
ofstream fout("reststops.out");

int main() {

    ll L,N,rf,rb;
    fin >> L >> N >> rf >> rb;

    vector<pii> stops(N);
    for (ll i = 0; i < N; i++) {
        fin >> stops[i].first >> stops[i].second;
    }

    deque<pii> good_stops;
    ll max_tasty = 0;
    for (ll i = N - 1; i > -1; i--) {
        if (stops[i].second > max_tasty) {
            good_stops.push_front(stops[i]);
            max_tasty = stops[i].second;
        }
    }

    ll last_stop = 0;
    ll ans = 0;
    for (const auto &stop : good_stops) {
        ans += stop.second*(stop.first - last_stop)*(rf-rb);
        last_stop = stop.first;
    }

    fout << ans << endl;

    return 0;
    
}