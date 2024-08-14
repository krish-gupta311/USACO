#include <bits/stdc++.h>
using namespace std;

ifstream fin("reststops.in");
ofstream fout("reststops.out");

int main() {

    int L,N,rf,rb;
    fin >> L >> N >> rf >> rb;

    vector<pair<int,int>> stops(N);
    for (int i = 0; i < N; i++) {
        fin >> stops[i].first >> stops[i].second;
    }

    int last_stop = 0;
    int ans = 0;
    for (const auto &stop : stops) {
        ans += stop.second*(stop.first - last_stop)*(rf-rb);
        last_stop = stop.first;
    }

    fout << ans << endl;

    return 0;
    
}