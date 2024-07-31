#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    freopen("div7.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("div7.out", "w", stdout);

    ll N;
    cin >> N;

    ll cows[N+1];
    cows[0] = 0;
    for (ll x = 1; x < N+1; x++) {
        cin >> cows[x];
    }

    for (ll x = 1; x < N+1; x++) {
        cows[x] += cows[x-1];
    } 

    bool isBroken = false;
    for (ll max_cows = N; max_cows > 0; max_cows--) {
        for (ll a = 1; a <= N - max_cows + 1; a++) {
            if ((cows[a + max_cows - 1] - cows[a-1]) % 7 == 0) {
                cout << max_cows;
                isBroken = true;
                break;
            }
        }
        if (isBroken) {
            break;
        }
    }
    if (!isBroken) {
        cout << 0;
    }

}