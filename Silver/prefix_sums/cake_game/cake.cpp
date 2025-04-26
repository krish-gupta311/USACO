#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("cake.in");
ofstream fout("cake.out");

int main() {

    int T;
    fin >> T;

    for (int i = 0 ; i < T; i++) {

        int N;
        fin >> N;

        vector<ll> cakes(N+1);
        for (int j = 1; j < N+1; j++) {
            fin >> cakes[j];
            cakes[j] += cakes[j-1];
        }

        ll min_bessie = LLONG_MAX;
        for (int j = 1; j + N/2 + 1 <= N; j++) {
            min_bessie = min(min_bessie,cakes[j+N/2+1]-cakes[j-1]);
        }

        fout << min_bessie << " " << cakes[N] - min_bessie << endl;

    }

    return 0;

}