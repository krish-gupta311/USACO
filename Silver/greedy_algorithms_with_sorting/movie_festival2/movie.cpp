#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

// ifstream fin("movie.in");
// ofstream fout("movie.out");

int main() {

    int N, K;
    cin >> N >> K;

    vector<pll> movies(N);
    for (int i = 0; i < N; i++) {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(),movies.end(),[] (const pll &a, const pll &b) {
        return a.second < b.second;
    });
    
    multiset<ll> endpoints;
    for (int i = 0; i < K; i++) {
        endpoints.insert(0);
    }
    int movies_watched = 0;
    for (const auto &movie : movies) {
        auto it = endpoints.upper_bound(movie.first);
        if (it != endpoints.begin()) {
            it--;
            endpoints.erase(it);
            endpoints.insert(movie.second);
            movies_watched++;
        }
    }

    cout << movies_watched << endl;

    return 0;
    
}