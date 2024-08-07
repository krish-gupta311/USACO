#include <bits/stdc++.h>
using namespace std;

ifstream fin("studying.in");
ofstream fout("studying.out");

int main() {

    int N, X;
    fin >> N >> X;

    vector<int> algorithms(N);
    for (int i = 0; i < N; i++) {
        fin >> algorithms[i];
    }
    sort(algorithms.begin(),algorithms.end());

    int time = 0;
    int num = 0;
    while (time < X) {
        time += algorithms[num];
        num++;
    }

    fout << num-1;
}