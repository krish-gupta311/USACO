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

struct Cow {
    ll x;
    int w, d;
};

int main() {
    ifstream fin("meetings.in");
    ofstream fout("meetings.out");

    int N, L;
    fin >> N >> L;

    vector<Cow> cows(N);
    ll total_weight = 0;
    for (int i = 0; i < N; i++) {
        fin >> cows[i].x >> cows[i].w >> cows[i].d;
        total_weight += cows[i].w;
    }

    // Separate left-moving and right-moving cows
    vector<pair<ll, int>> left, right;
    for (int i = 0; i < N; i++) {
        if (cows[i].d == -1) {
            left.emplace_back(cows[i].x, cows[i].w);
        } else {
            right.emplace_back(L - cows[i].x, cows[i].w);
        }
    }

    // Combine and sort by position for getting T
    vector<pair<ll, int>> events;
    events.insert(events.end(), left.begin(), left.end());
    events.insert(events.end(), right.begin(), right.end());
    sort(events.begin(), events.end());

    ll T = 0;
    ll weight = total_weight;
    for (const auto& event : events) {
        weight -= 2 * event.second;
        if (weight <= 0) {
            T = event.first;
            break;
        }
    }

    // Sort cows by position x
    sort(cows.begin(), cows.end(), [](Cow a, Cow b) { return a.x < b.x; });

    // Count meetings
    ll meetings = 0;
    queue<ll> right_moving_cows;
    for (int i = 0; i < N; i++) {
        if (cows[i].d == 1) {
            right_moving_cows.push(cows[i].x);
        } else {
            while (!right_moving_cows.empty() && right_moving_cows.front() + 2 * T < cows[i].x) {
                right_moving_cows.pop();
            }
            meetings += right_moving_cows.size();
        }
    }

    fout << meetings << endl;
    return 0;
}
