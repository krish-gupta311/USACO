#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

// ifstream fin("bake.in");
// ofstream fout("bake.out");

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        ll X, Y;
        cin >> N >> X >> Y;

        vector<ll> A(N), B(N), C(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i] >> C[i];
        }

        ll lo = 0, hi = X + Y - 2;

        while (hi > l o) {
            ll mid = (lo + hi) / 2;

            ll lx = max(1LL, X - mid);
            ll hx = min(X + Y - mid - 1, X);
            bool valid = true;

            for (int i = 0; i < N; i++) {
                ll a = A[i], b = B[i], c = C[i];
                ll d = X + Y - mid;

                if (b - a > 0) {
                    lx = max(lx, (-c + b * d + (b - a - 1)) / (b - a));
                } else if (a - b > 0) {
                    hx = min(hx, (c - b * d) / (a - b));
                } else {
                    if (a * d > c) {
                        valid = false;
                        break;
                    }
                }

                if (lx > hx) {
                    valid = false;
                    break;
                }
            }

            if (valid) hi = mid;
            else lo = mid + 1;
        }

        cout << lo << endl;
    }

    return 0;
}
