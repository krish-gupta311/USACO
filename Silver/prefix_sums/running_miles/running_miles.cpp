#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("running_miles.in","r",stdin);
    freopen("running_miles.out","w",stdout);

    int T;
    cin >> T;
    for (int x = 0; x < T; x++) {
    
        int N;
        cin >> N;

        int sights[N];
        for (int x = 0; x < N; x++) {
            cin >> sights[x];
        }

        int prefix_sums[N];
        int suffix_sums[N];

        for (int x = 0; x < N; x++) {
            prefix_sums[x] = sights[x] + x;
            suffix_sums[x] = sights[x] - x;
        }

        for (int x = 1; x < N; x++) {
            prefix_sums[x] = max(prefix_sums[x], prefix_sums[x-1]);
        }

        for (int x = N - 2; x > 0; x--) {
            suffix_sums[x] = max(suffix_sums[x], suffix_sums[x+1]);
        }

        int ans = 0;
        for (int x = 1; x < N - 1; x++) {
            ans = max(ans, prefix_sums[x-1] + sights[x] + suffix_sums[x+1]);
        }

        cout << ans << endl;

    }

}