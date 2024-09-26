#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("convention.in");
ofstream fout("convention.out");

bool test_T(vector<ll> cows, int N, int M, int C, int T) {
    int buses = 1;
    int occupied = 1;
    ll earliest_cow = cows[0];

    for (int i = 1; i < cows.size(); i++) {
        if (occupied == C || cows[i] - earliest_cow > T) {
            buses++;
            earliest_cow = cows[i];
            occupied = 1;
            if (buses > M) {
                return false;
            }
        } else {
            occupied++;
        }
    }
    return true;
}

ll first_true(vector<ll> cows, int N, int M, int C, ll lo, ll hi) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (test_T(cows, N, M, C, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    int N, M, C;
    fin >> N >> M >> C;

    vector<ll> cows(N);
    for (int i = 0; i < N; i++) {
        fin >> cows[i];
    }
    sort(cows.begin(), cows.end());

    ll max_wait = first_true(cows, N, M, C, 0, cows.back() - cows[0]);
    fout << max_wait << endl;

    return 0;
}
y