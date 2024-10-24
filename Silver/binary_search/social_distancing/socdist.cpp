#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ifstream fin("socdist.in");
ofstream fout("socdist.out");

int main() {

    int N, M;
    fin >> N >> M;

    vector<pll> intervals;
    for (int i = 0; i < M; i++) {
        ll a, b;
        fin >> a >> b;
        intervals.push_back(make_pair(a,b));
    }
    sort(intervals.begin(),intervals.end());

    ll lo = 1;
    ll hi = 1e18;
    lo--;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        bool f = false;
        int cows = 1;
        ll last = intervals[0].first;
        for (pll interval : intervals) {
            while (last + mid <= interval.second) {
                last = max(last+mid,interval.first);
                cows++;
                if (cows == N) {
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
        if (f) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    ll D = lo;
    fout << D << endl;

    return 0;
}