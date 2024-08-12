#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ifstream fin("movie.in");
ofstream fout("movie.out");

int main() {

    int N, K;
    fin >> N >> K;

    vector<pll> movies(N);
    for (int i = 0; i < N; i++) {
        fin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(),movies.end(),[] (const pll &a, const pll &b) {
        return a.second < b.second;
    });
    
    int avail = K;
    vector<ll> endpoints;
    int movies_watched = 0;
    for (const auto &movie : movies) {
        if (!endpoints.empty()) {
            auto it = upper_bound(endpoints.begin(),endpoints.end(),movie.first);
            if (it != endpoints.end()) {
                avail += it - endpoints.begin();
                vector<ll> sub_vec(it,endpoints.begin()+endpoints.size());
                endpoints = sub_vec;
            } else {
                avail += endpoints.size();
                endpoints.clear();
            }
        }
        if (avail > 0) {
            endpoints.push_back(movie.second);
            movies_watched++;
            avail--;
        }    
    }

    fout << movies_watched << endl;

    return 0;
    
}