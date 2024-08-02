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

ifstream fin("meetings.in");
ofstream fout("meetings.out");

struct Cow {
    ll x;
    int w, d;
};

int main() {
    int N, L;
    fin >> N >> L;

    ll total_weight = 0;
    vector<Cow> cows(N);
    for (int i = 0; i < N; i++) {
        fin >> cows[i].x >> cows[i].w >> cows[i].d;
        total_weight += cows[i].w;
    }

    // Sort cows by position x
    sort(cows.begin(), cows.end(), [](Cow a, Cow b) { return a.x < b.x; });

    // Separate left-moving and right-moving cows
    vector<pair<ll, int>> lef, rig;
    for (int i = 0; i < N; i++) {
        if (cows[i].d == -1) {
            lef.emplace_back(cows[i].x, cows[i].w);
        } else {
            rig.emplace_back(L - cows[i].x, cows[i].w);
        }
    }

    // Combine and sort by position for getting T
    vector<pair<ll, int>> v;
    v.insert(v.end(), lef.begin(), lef.end());
    v.insert(v.end(), rig.begin(), rig.end());
    sort(v.begin(), v.end());

    ll tot = 0;
    for (const auto& t : v) {
        tot += t.second;
    }

    ll T = 0;
    for (const auto& t : v) {
        tot -= 2 * t.second;
        if (tot <= 0) {
            T = t.first;
            break;
        }
    }

    // Counting meetings
    queue<ll> right_moving_positions;
    ll meetings = 0;
    for (const auto& cow : cows) {
        if (cow.d == 1) {
            right_moving_positions.push(cow.x);
        } else {
            while (!right_moving_positions.empty() && right_moving_positions.front() + 2 * T < cow.x) {
                right_moving_positions.pop();
            }
            meetings += right_moving_positions.size();
        }
    }

    fout << meetings << endl;

    return 0;
}
