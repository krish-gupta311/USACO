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
    int num = -1;
    while (time < X && num + 1 < N) {
        time += algorithms[num+1];
        num++;
    }

    cout << num;
}