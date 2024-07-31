#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("siar.in", "r", stdin);
    freopen("siar.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> eastCows;
    vector<int> northCows;
    vector<int> xs(n);
    vector<int> ys(n);

    for (int j = 0; j < n; ++j) {
        char direction;
        cin >> direction;
        if (direction == 'E') {
            eastCows.push_back(j);
        } else {
            northCows.push_back(j);
        }
        cin >> xs[j] >> ys[j];
    }

    sort(eastCows.begin(), eastCows.end(), [&](int a, int b) { return ys[a] < ys[b]; });
    sort(northCows.begin(), northCows.end(), [&](int a, int b) { return xs[a] < xs[b]; });

    vector<bool> isStopped(n, false);
    vector<int> amtStopped(n, 0);

    for (int j : eastCows) {
        for (int k : northCows) {
            if (!isStopped[j] && !isStopped[k] && xs[k] > xs[j] && ys[j] > ys[k]) {
                if (xs[k] - xs[j] > ys[j] - ys[k]) {
                    isStopped[j] = true;
                    amtStopped[k] += 1 + amtStopped[j];
                } else if (ys[j] - ys[k] > xs[k] - xs[j]) {
                    isStopped[k] = true;
                    amtStopped[j] += 1 + amtStopped[k];
                }
            }
        }
    }

    for (int j = 0; j < n; ++j) {
        cout << amtStopped[j] << "\n";
    }

    return 0;
}
