#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    freopen("hps.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("hps.out", "w", stdout);

    int N;
    cin >> N;

    int fj[N];
    for (int x = 0; x < N; x++) {
        char temp;
        cin >> temp;
        switch (temp) {
            case 'H':
                fj[x] = 0;
                break;
            case 'P':
                fj[x] = 1;
                break;
            case 'S':
                fj[x] = 2;
                break;
        }
    }

    int ideal_bessie[N];
    for (int x = 0; x < N; x++) {
        ideal_bessie[x] = (fj[x] + 1) % 3;
    }

    int ibs[N+1][3];
    ibs[0][0] = 0;
    ibs[0][1] = 0;
    ibs[0][2] = 0;
    for (int x = 1; x < N + 1; x++) {
        ibs[x][0] = ibs[x - 1][0];
        ibs[x][1] = ibs[x - 1][1];
        ibs[x][2] = ibs[x - 1][2];
        ibs[x][fj[x-1]]++;
    }

    int max_wins = 0;
    for (int x = 1; x < N + 1; x++) {
        int wins = max(max(ibs[x][0],ibs[x][1]),max(ibs[x][0],ibs[x][2]));
        int h = ibs[N][0] - ibs[x][0];
        int p = ibs[N][1] - ibs[x][1];
        int s = ibs[N][2] - ibs[x][2];
        wins += max(max(h,p),max(h,s));
        max_wins = max(wins,max_wins);
    }

    cout << max_wins;

}