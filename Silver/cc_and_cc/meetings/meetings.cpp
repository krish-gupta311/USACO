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

ifstream fin("meetings.in");
ofstream fout("meetings.out");

void readInput(int& N, int& L, vector<Cow>& cows) {
    fin >> N >> L;
    cows.resize(N);
    for (int i = 0; i < N; i++) {
        fin >> cows[i].x >> cows[i].w >> cows[i].d;
    }
}

ll calculateTotalWeight(const vector<Cow>& cows) {
    ll total_weight = 0;
    for (const auto& cow : cows) {
        total_weight += cow.w;
    }
    return total_weight;
}

ll determineT(int N, int L, const vector<Cow>& cows, ll total_weight) {
    vector<pair<ll, int>> events;
    for (const auto& cow : cows) {
        if (cow.d == -1) {
            events.emplace_back(cow.x, cow.w);
        } else {
            events.emplace_back(L - cow.x, cow.w);
        }
    }

    sort(events.begin(), events.end());

    ll weight = total_weight;
    for (const auto& event : events) {
        weight -= 2 * event.second;
        if (weight <= 0) {
            return event.first;
        }
    }
    return 0;
}

int countMeetings(int N, ll T, const vector<Cow>& cows) {
    queue<ll> right_moving_cows;
    int meetings = 0;

    for (const auto& cow : cows) {
        if (cow.d == 1) {
            right_moving_cows.push(cow.x);
        } else {
            while (!right_moving_cows.empty() && right_moving_cows.front() + 2 * T < cow.x) {
                right_moving_cows.pop();
            }
            meetings += right_moving_cows.size();
        }
    }
    return meetings;
}

int main() {

    int N, L;
    vector<Cow> cows;
    readInput(N, L, cows);

    ll total_weight = calculateTotalWeight(cows);
    ll T = determineT(N, L, cows, total_weight);

    sort(cows.begin(), cows.end(), [](Cow a, Cow b) { return a.x < b.x; });

    int meetings = countMeetings(N, T, cows);
    fout << meetings << "\n";

    return 0;
}
