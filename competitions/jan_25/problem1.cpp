#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    int matches = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            for (int n = 0; n < N; n++) {
                if (i <= n && j >= n) {
                    if (a[j-n+i] == b[n]) {
                        matches++;
                    }
                } else {
                    if (a[n] == b[n]) {
                        matches++;
                    }
                }
            }
        }
    }

    cout << matches << endl;
    return 0;

}