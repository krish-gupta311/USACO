#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

bool comp(pii peak1, pii peak2) {
    return peak1.second > peak2.second;
}

int main() {

    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    int N;
    cin >> N;

    vector<pii> peaks;
    for (int z = 0; z < N; z++) {
        int x,y;
        cin >> x >> y;
        peaks.push_back(make_pair(x,y));
    }
    sort(peaks.begin(),peaks.end(),comp);

    int not_obscure = N;
    vector<int> obscure(N);
    for (int x = 0; x < N; x++) {
        obscure[x] = 1;
    }
    for (int i = 0; i < N - 1; i++) {
        if (obscure[i] == 0) {
            continue;
        }
        for (int j = i + 1; j < N; j++) {
            if (obscure[j] == 0) {
                continue;
            }
            if (abs(peaks[j].second - peaks[i].second) >= abs(peaks[j].first - peaks[i].first)) {
                obscure[j] = 0;
                not_obscure--;
            }
        }
    }

    cout << not_obscure;
    
}