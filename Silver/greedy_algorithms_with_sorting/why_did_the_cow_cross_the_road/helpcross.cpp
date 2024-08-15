#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ifstream fin("helpcross.in");
ofstream fout("helpcross.out");

int main() {

    int C,N;
    fin >> C >> N;

    vector<ll> chickens(C);
    for (int i = 0; i < C; i++) {
        fin >> chickens[i];
    }
    sort(chickens.begin(),chickens.end());

    vector<pll> cows(N);
    for (int i = 0; i < N; i++) {
        fin >> cows[i].second >> cows[i].first;
    }
    sort(cows.begin(),cows.end());
    
    int ans = 0;
    for (const auto &cow : cows) {
        auto it = lower_bound(chickens.begin(),chickens.end(),cow.second);
        if (it != chickens.end() && *it <= cow.first) {
            ans++;
            chickens.erase(it);
        }
    }

    fout << ans << endl;
    
}