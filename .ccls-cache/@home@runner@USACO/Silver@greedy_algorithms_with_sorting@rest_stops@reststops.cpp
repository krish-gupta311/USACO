#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

ifstream fin("reststops.in");
ofstream fout("reststops.out");

int main() {

    int L,N,rf,rb;
    fin >> L >> N >> rf >> rb;

    vector<pii> stops(N);
    for (int i = 0; i < N; i++) {
        fin >> stops[i].first >> stops[i].second;
    }

    deque<pii> good_stops;
    int max_tasty = 0;
    for (int i = N - 1; i > -1; i--) {
        if (stops[i].second > max_tasty) {
            good_stops.push_front(stops[i]);
            max_tasty = stops[i].second;
        }
    }

    int last_stop = 0;
    int ans = 0;
    for (const auto &stop : good_stops) {
        ans += stop.second*(stop.first - last_stop)*(rf-rb);
        last_stop = stop.first;
    }

    fout << ans << endl;

    return 0;
    
}