#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("angry.in");
ofstream fout("angry.out");

int main() {

    int n, k;
    fin >> n >> k; 

    vector<ll> locations(n);
    for (int i = 0; i < n; i++) {
        fin >> locations[i];
    }

    sort(locations.begin(), locations.end());

    ll min = 0; 
    ll max = locations[n-1];
    while (min < max) {
        ll mid = (min + max) / 2; 
        int used = 0;
        ll last = 0;

        while (last < n) {
            used++;
            ll curr = last + 1;
            while (curr < n && locations[curr] - locations[last] <= 2 * mid) {
                curr++;
            }
            last = curr;
        }

        if (used <= k) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }

    fout << min << endl;
    return 0;
}
