#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

// ifstream fin("tasks.in");
// ofstream fout("tasks.out");

int main() {

    int N;
    cin >> N;
    vector<pii> tasks(N);
    for (int i = 0; i < N; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end(), [] (const pii &a, const pii &b) { return a.first < b.first; });

    int time = 0;
    int reward = 0;
    for (const pii &task : tasks) {
        time += task.first;
        reward += task.second - time;
    }

    cout << reward;

    return 0;
    
}