#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("angry.in");
ofstream fout("angry.out");

ll first_true(ll lo, ll hi, function<bool(ll)> f) {
    
    lo--;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
    
}

int main () {

    int N, K;
    fin >> N >> K;

    vector<ll> cows(N);
    for (int i = 0; i < N; i++) {
        fin >> cows[i];
    }
    sort(cows.begin(),cows.end());

    ll min_R = first_true(cows[0],cows[N-1], [&](ll R) {
        
    });
    
    
}
