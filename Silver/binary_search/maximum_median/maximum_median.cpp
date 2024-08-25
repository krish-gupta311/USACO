#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("maximum_median.in");
ofstream fout("maximum_median.out");

ll last_true(ll lo, ll hi, function<bool(ll)> f) {

    lo--;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
    
}

int main() {

    int N;
    ll K;
    fin >> N >> K;

    vector<ll> arr(N);
    for (int i = 0; i < N; i++) {
        fin >> arr[i];
    }
    sort(arr.begin(),arr.end());

    ll max_median = last_true(arr[(N-1)/2],arr[N-1]+K, [&](ll x) {
        ll opps = 0;
        for (int i = (N-1)/2; i < N; i++) {
            opps += max(0LL,x-arr[i]);
        }
        return opps <= K;
    }); 

    fout << max_median << endl;
    
}