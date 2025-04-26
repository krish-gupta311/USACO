#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// ifstream fin("one.in");
// ofstream fout("one.out");

int main() {

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {

        int N;
        cin >> N;

        vector<ll> cakes;
        for (int j = 0; j < N; j++) {
            ll a;
            cin >> a;
            cakes.push_back(a);
        }

        ll elsie = 0;
        int turn = 0;

        while (N > 1) {
            if (turn == 0) {
                ll stack = cakes[N/2] + cakes[N/2-1];
                cakes[N/2] = stack;
                cakes.erase(cakes.begin()+N/2-1);
            } else {
                if (cakes[0] > cakes[N-1]) {
                    elsie += cakes[0];
                    cakes.erase(cakes.begin());
                } else {
                    elsie += cakes[N-1];
                    cakes.erase(cakes.begin()+N-1);
                }
            }
            N--;
            turn = 1 - turn;
        }
        ll bessie = cakes[0];
        cout << bessie << " " << elsie << endl;

    }

    return 0;

}