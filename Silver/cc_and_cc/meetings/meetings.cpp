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

struct Cow {
    int w; // weight
    int x; // position
    int d; // direction
};

int main() {
    ifstream fin("meetings.in");
    ofstream fout("meetings.out");

    int N; // number of cows
    int L; // length of the barn
    fin >> N >> L;

    vector<Cow> cows(N);
    int total_weight = 0;
    for (int i = 0; i < N; i++) {
        fin >> cows[i].w >> cows[i].x >> cows[i].d;
        total_weight += cows[i].w; // correctly summing up the weight
    }

    // Sort cows by their position
    sort(cows.begin(), cows.end(), [](const Cow &a, const Cow &b) { return a.x < b.x; });

    // Separate left-moving and right-moving cows
    vector<Cow> left;
    vector<Cow> right;
    for (const Cow &cow : cows) {
        if (cow.d == -1) {
            left.push_back(cow);
        } else if (cow.d == 1) {
            right.push_back(cow);
        }
    }

    // Calculate the times when cows meet the ends of the barn
    vector<pair<int, int>> weight_times;
    for (int i = 0; i < left.size(); i++) {
        weight_times.push_back({left[i].x, cows[i].w});
    }
    for (int i = 0; i < right.size(); i++) {
        weight_times.push_back({L - right[i].x, cows[left.size()+i].w});
    }

    // Sort them by their occurrence
    sort(weight_times.begin(), weight_times.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.first < b.first; });

    int T = -1;
    int accumulated_weight = 0;
    for (const auto &wt : weight_times) {
        accumulated_weight += wt.second;
        if (accumulated_weight * 2 >= total_weight) {
            T = wt.first;
            break;
        }
    }

    // Count how many meetings occur before time T
    int meetings = 0;
    queue<int> moving_right;
    for (const Cow &cow : cows) {
        if (cow.d == 1) {
            moving_right.push(cow.x);
        } else {
            while (!moving_right.empty() && moving_right.front() + 2 * T < cow.x) {
                moving_right.pop();
            }
            meetings += moving_right.size();
        }
    }

    fout << meetings << endl;

    return 0;
}
