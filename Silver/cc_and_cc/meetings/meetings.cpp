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
    int w;
    int x;
    int d;
};

int main() {
    ifstream fin("meetings.in");
    ofstream fout("meetings.out");

    int N;
    int L;
    fin >> N >> L;

    vector<Cow> cows(N);
    int total_weight = 0;
    for (int i = 0; i < N; i++) {
        fin >> cows[i].x >> cows[i].w >> cows[i].d;
        total_weight += cows[i].w;
    }

    sort(cows.begin(), cows.end(), [](Cow a, Cow b) { return a.x < b.x; });

    // get the cows that start off going to the left & right
    vector<Cow> left;
    vector<Cow> right;
    for (Cow cow : cows) {
        if (cow.d == -1) {
            left.push_back(cow);
        } else if (cow.d == 1) {
            right.push_back(cow);
        }
    }

    /*
     * calculate each of the times when the cows meet the end
     * the leftmost cows get all of the -1 cow's positions as their times,
     * and similarly for the rightmost ones
     */
    vector<pair<int, int>> weight_times;
    for (int i = 0; i < left.size(); i++) {
        // time of arrivial at barn & weight, respectively
        weight_times.push_back(make_pair(left[i].x, cows[i].w));
    }
    for (int i = 0; i < right.size(); i++) {
        weight_times.push_back(make_pair(L - right[i].x, cows[left.size() + i].w));
    }

    // sort them by their occurrence
    sort(weight_times.begin(), weight_times.end(),[]( pair<int, int> a, pair<int, int> b) { return a.first < b.first; });

    int T = -1;
    for (auto z : weight_times) {
        total_weight -= 2 * z.second;
        if (total_weight <= 0) {
            T = z.first;
            break;
        }
    }

    // count how many meetings occur before the end time
    int meetings = 0;
    // the cows that a left-going cow can meet before the end time
    queue<int> moving_right;
    for (int i = 0; i < N; i++) {
        if (cows[i].d == 1) {
            moving_right.push(cows[i].x);
        } else {
            // remove all the cows that can't meet this left-going cow
            while (!moving_right.empty() && (cows[i].x - moving_right.front())/2 > T) {
                moving_right.pop();
            }
            meetings += moving_right.size();
        }
    }

    fout << meetings << endl;
}