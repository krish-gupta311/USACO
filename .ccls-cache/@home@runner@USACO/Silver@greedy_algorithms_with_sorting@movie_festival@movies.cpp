#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

// ifstream fin("movies.in");
// ofstream fout("movies.out");

int main() {

    int N;
    cin >> N;

    vector<pii> movies(N);
    for (int i = 0; i < N; i++) {
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(), [] (const pii &a, const pii &b) { return a.second < b.second; });
    
    int num_movies = 0;
    int last_end_time = 0;
    for (const pii &movie : movies) {
        if (movie.first >= last_end_time) {
            num_movies++;
            last_end_time = movie.second;
        }
    }

    cout << num_movies;

    return 0;
}