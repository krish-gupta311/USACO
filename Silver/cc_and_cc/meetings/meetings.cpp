#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("meetings.in");
ofstream fout("meetings.out");

struct Cow {
    ll x,finishing_time;
    int w,d;
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
    sort(cows.begin(),cows.end(),[](Cow a, Cow b){return a.d < b.d;});

    vector<ll> finishing_times(N);
    for (int i = 0; i < N; i++) {
        if (cows[i].d == -1) {
            finishing_times[i] = cows[i].x;
        } else {
            finishing_times[i] = L - cows[i].x;
        }
    }
    sort(cows.begin(),cows.end(),[](Cow a, Cow b){return a.x < b.x;});
    
    for (int i = 0; i < N; i++) {
        cows[i].finishing_time = finishing_times[i];
    }
    sort(cows.begin(),cows.end(),[](Cow a, Cow b){return a.finishing_time < b.finishing_time;});

    ll T;
    ll weight = 0;
    for (Cow cow : cows) {
        weight += cow.w;
        T = cow.finishing_time;
        if (weight >= total_weight/2) break;
    }  

    ll meetings = 0;
    queue<Cow> right_moving_cows;
    for (int i = 0; i < N; i++) {
        if (cows[i].d == 1) {
            right_moving_cows.push(cows[i]);
        } else {
            while (!right_moving_cows.empty() && right_moving_cows.front().x + 2 * T < cows[i].x) {
                right_moving_cows.pop();
            }
            meetings += right_moving_cows.size();
        }
    }
    fout << meetings << endl;
        
}