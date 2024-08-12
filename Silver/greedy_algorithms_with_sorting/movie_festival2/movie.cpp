// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef pair<ll,ll> pll;

// // ifstream fin("movie.in");
// // ofstream fout("movie.out");

// int main() {

//     int N, K;
//     cin >> N >> K;

//     vector<pll> movies(N);
//     for (int i = 0; i < N; i++) {
//         cin >> movies[i].first >> movies[i].second;
//     }
//     sort(movies.begin(),movies.end(),[] (const pll &a, const pll &b) {
//         return a.second < b.second;
//     });
    
//     int avail = K;
//     vector<ll> endpoints;
//     int movies_watched = 0;
//     for (const auto &movie : movies) {
//         if (!endpoints.empty()) {
//             auto it = upper_bound(endpoints.begin(),endpoints.end(),movie.first);
//             if (it != endpoints.end()) {
//                 avail += it - endpoints.begin();
//                 vector<ll> sub_vec(it,endpoints.begin()+endpoints.size());
//                 endpoints = sub_vec;
//             } else {
//                 avail += endpoints.size();
//                 endpoints.clear();
//             }
//         }
//         if (avail > 0) {
//             endpoints.push_back(movie.second);
//             movies_watched++;
//             avail--;
//         }    
//     }

//     cout << movies_watched << endl;

//     return 0;
    
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pll> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    // Sort movies by their ending time
    sort(movies.begin(), movies.end(), [](const pll &a, const pll &b) {
        return a.second < b.second;
    });

    // Priority queue to track end times of movies currently being watched by club members
    multiset<ll> endTimes;

    // Initially, all club members are available (i.e., they can start watching any movie)
    for (int i = 0; i < k; i++) {
        endTimes.insert(0);
    }

    int moviesWatched = 0;

    for (const auto &movie : movies) {
        // Find the first member who is available before the movie starts
        auto it = endTimes.upper_bound(movie.first);

        if (it != endTimes.begin()) {
            // Assign the movie to this member
            it--;

            endTimes.erase(it);  // Remove the old end time
            endTimes.insert(movie.second);  // Update with the new end time

            moviesWatched++;
        }
    }

    cout << moviesWatched << endl;

    return 0;
}
