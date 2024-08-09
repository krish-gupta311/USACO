#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

// ifstream fin("tasks.in");
// ofstream fout("tasks.out");

int main() {

    ll N;
    cin >> N;
    vector<pll> tasks(N);
    for (ll i = 0; i < N; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end());

    ll time = 0;
    ll reward = 0;
    for (const pll &task : tasks) {
        time += task.first;
        reward += task.second - time;
    }

    cout << reward;

    return 0;
    
}