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

    vector<ll> hay_bales(N);
    for (int i = 0; i < N; i++) {
        fin >> hay_bales[i];
    }
    sort(hay_bales.begin(),hay_bales.end());

    ll min_R = first_true(0,hay_bales[N-1]/2, [&](ll R) {

        ll hay_bale = hay_bales[0];
        for (int i = 0; i < K; i++) {
            auto next_bale = upper_bound(hay_bales.begin(),hay_bales.end(),hay_bale + 2*R);
            if (next_bale == hay_bales.end()) {
                return true;
            }
            hay_bale = *next_bale;
        }
        
        return false;
        
    });

    fout << min_R << endl;
    return 0;  
    
}
