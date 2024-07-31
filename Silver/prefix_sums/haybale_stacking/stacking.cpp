#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("stacking.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("stacking.out", "w", stdout);

    int N, K;
    cin >> N >> K;

    int stacks[N + 1];
    for (int x = 0; x < N + 1; x++) {
        stacks[x] = 0;
    }

    for (int x = 0; x < K; x++) {
        int a,b;
        cin >> a >> b;
        stacks[a]++;
        if (b != N) {
            stacks[b+1]--;
        }
    }

    for (int x = 1; x < N + 1; x++) {
        stacks[x] += stacks[x-1];
    }

    sort(stacks, stacks + N + 1);

    cout << stacks[(N+1)/2 - 1];

}