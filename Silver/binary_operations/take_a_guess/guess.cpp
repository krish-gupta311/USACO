#include <bits/stdc++.h>
using namespace std;

// ifstream fin("guess.in");
// ofstream fout("guess.out");

int query(const string &type, int i, int j) {
    cout << type << " " << i + 1 << " " << j + 1 << endl;
    fflush(stdout);
    int result;
    cin >> result;
    if (result == -1) {
        exit(0);
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
d
    vector<int> and_results(n, 0), or_results(n, 0);

    for (int i = 1; i < n; i++) {
        and_results[i] = query("and", 0, i);
        or_results[i] = query("or", 0, i);
    }

    int sum01 = and_results[1] + or_results[1];
    int sum02 = and_results[2] + or_results[2];
    int sum12 = query("and", 1, 2) + query("or", 1, 2);

    vector<int> a(n);
    a[0] = (sum01 + sum02 - sum12) / 2;
    a[1] = sum01 - a[0];
    a[2] = sum02 - a[0];

    for (int i = 3; i < n; i++) {
        a[i] = and_results[i] + or_results[i] - a[0];
    }

    sort(a.begin(), a.end());

    cout << "finish " << a[k - 1] << endl;
    fflush(stdout);

    return 0;
}
