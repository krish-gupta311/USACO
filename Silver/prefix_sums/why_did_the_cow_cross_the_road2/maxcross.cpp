#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("maxcross.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("maxcross.out", "w", stdout);

    int N, K, B;
    cin >> N >> K >> B;

    int signals[N + 1];
    for (int x = 0; x < N + 1; x++) {
        signals[x] = 1;
    }

    for (int x = 0; x < B; x++) {
        int damaged;
        cin >> damaged;
        signals[damaged] = 0;
    }

    for (int x = 1; x < N + 1; x++) {
        signals[x] += signals[x-1];
    }

    int max_working = 0;
    for (int x = 1; x <= N - K + 1; x++) {
        int working = signals[x + K - 1] - signals[x - 1];
        max_working = max(max_working,working);
    }
 
    cout << K - max_working;

}