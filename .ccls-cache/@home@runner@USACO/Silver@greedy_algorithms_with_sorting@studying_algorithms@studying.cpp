#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, X;
    cin >> N >> X;

    vector<int> algorithms(N);
    for (int i = 0; i < N; i++) {
        cin >> algorithms[i];
    }
    sort(algorithms.begin(),algorithms.end());

    int time = 0;
    int num = 0;
    while (time < X) {
        time += algorithms[num];
        num++;
    }

    cout << num-1;
}