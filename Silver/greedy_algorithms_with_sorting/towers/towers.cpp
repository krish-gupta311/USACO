#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ifstream fin("towers.in");
// ofstream fout("towers.out");

int main() {

    int N;
    cin >> N;

    vector<ll> cubes(N);
    for (int i = 0; i < N; i++) {
        cin >> cubes[i];
    }

    vector<ll> towers;
    for (const ll &cube : cubes) {
        if (towers.empty()) {
            towers.push_back(cube);
        } else {
            bool isBroken = false;
            for (int i = 0; i < towers.size(); i++) {
                if (towers[i] > cube) {
                    towers[i] = cube;
                    isBroken = true;
                    break;
                }
            }
            if (!isBroken) {
                towers.push_back(cube);
            }
        }
    }

    cout << towers.size();

    return 0;
    
}