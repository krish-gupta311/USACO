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

ifstream fin("meetings.in");
ofstream fout("meetings.out");

int N,L;
vector<int> w,x,d;

void init() {
    
    fin >> N >> L;

    w.resize(N);
    x.resize(N);
    d.resize(N);
    for (int i = 0; i < N; i++) {
        fin >> x[i] >> w[i] >> d[i];
    }
    
    vector<int> inds(N);
    for (int i = 0; i < N; i++) {
        inds[i] = i;
    }
    sort(inds.begin(),inds.end(),[](int a, int b) { return x[a] < x[b]; });
    vector<int> W,X,D;
    for (int t : inds) {
        W.push_back(w[t]);
        X.push_back(x[t]);
        D.push_back(d[t]);
    }
    swap(w,W), swap(x,X), swap(d,D);
}

int getTime() {
    vector<int> left, right;
    for (int i = 0; i < N; i++) {
        if (d[i] == -1) {
            left.push_back(x[i]);
        }
        else {
            right.push_back(x[i]);
        }
    }
    vector<pair<int,int> > v;
    for (int i = 0; i < left.size(); i++) {
        v.push_back({left[i],w[i]});
    }
    for (int i = 0; i < right.size(); i++) {
        v.push_back({L-right[i],w[left.size()+i]});
    }
    sort(v.begin(),v.end(), [](pair<int,int> a, pair<int,int> b) { return a.first < b.first; });
    int total_weight = 0;
    for (auto t : v) {
        total_weight += t.second;
    }
    for (auto t : v) {
        total_weight -= 2*t.second;
        if (total_weight <= 0) {
            return t.first;
        }
    } 
    return 0;
}

int main() {
    init();
    int T = getTime(); 
    queue<int> right;
    int meetings = 0;
    for (int i = 0; i < N; i++) {
        if (d[i] == -1) {
            while (!right.empty() && (x[i] - right.front())/2 > T) {
                right.pop();
            }
            meetings += right.size();
        } else { 
            right.push(x[i]);
        }
    }
    fout << meetings << "\n";
    return 0;
}
