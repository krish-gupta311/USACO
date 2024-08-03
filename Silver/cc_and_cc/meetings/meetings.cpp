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
    int weight;
    int pos;
    int speed;
};

int main() {
    ifstream fin("meetings.in");
    ofstream fout("meetings.out");

    int cow_num;
    int barn_pos;
    fin >> cow_num >> barn_pos;

    vector<Cow> cows(cow_num);
    int total_weight = 0;
    for (Cow &c : cows) {
        fin >> c.weight >> c.pos >> c.speed;
        total_weight += c.weight;
    }

    sort(cows.begin(), cows.end(),
              [](const Cow &c1, const Cow &c2) { return c1.pos < c2.pos; });

    // get the cows that start off going to the left & right
    vector<Cow> left;
    vector<Cow> right;
    for (const Cow &c : cows) {
        if (c.speed == -1) {
            left.push_back(c);
        } else if (c.speed == 1) {
            right.push_back(c);
        }
    }

    /*
     * calculate each of the times when the cows meet the end
     * the leftmost cows get all of the -1 cow's positions as their times,
     * and similarly for the rightmost ones
     */
    vector<pair<int, int>> weight_times;
    for (int c = 0; c < left.size(); c++) {
        // time of arrivial at barn & weight, respectively
        weight_times.push_back({left[c].pos, cows[c].weight});
    }
    for (int c = 0; c < right.size(); c++) {
        weight_times.push_back(
            {barn_pos - right[c].pos, cows[left.size() + c].weight});
    }

    // sort them by their occurrence
    sort(weight_times.begin(), weight_times.end(),
              [](const pair<int, int> &a, const pair<int, int> &b) {
                  return a.first < b.first;
              });

    int endTime = -1;
    for (const auto &[time, weight] : weight_times) {
        total_weight -= 2 * weight;
        if (total_weight <= 0) {
            endTime = time;
            break;
        }
    }

    // count how many meetings occur before the end time
    int meeting_num = 0;
    // the cows that a left-going cow can meet before the end time
    queue<int> leftSide;
    for (int c = 0; c < cow_num; c++) {
        if (cows[c].speed == 1) {
            leftSide.push(cows[c].pos);
        } else if (cows[c].speed == -1) {
            // remove all the cows that can't meet this left-going cow
            while (!leftSide.empty() &&
                   leftSide.front() + 2 * endTime < cows[c].pos) {
                leftSide.pop();
            }
            meeting_num += leftSide.size();
        }
    }

    fout << meeting_num << endl;
}