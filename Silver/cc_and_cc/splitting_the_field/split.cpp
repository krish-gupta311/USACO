#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> get_psums(vector<pll> coords, int N) {
    vector<pll> psums(N);
    psums[0].first = coords[1].second;
    psums[0].second = coords[1].second;
    for (int i = 2; i <= N; i++) {
        psums[i-1].first = min(psums[i-2].first,coords[i].second);
        psums[i-1].second = max(psums[i-2].second,coords[i].second);
    }
    return psums;
}

vector<pll> get_ssums(vector<pll> coords, int N) {
    vector<pll> ssums(N);
    ssums[N-1].first = coords[N].second;
    ssums[N-1].second = coords[N].second;
    for (int i = N-1; i > 0; i--) {
        ssums[i-1].first = min(ssums[i].first,coords[i].second);
        ssums[i-1].second = max(ssums[i].second,coords[i].second);
    }
    return ssums;
}

ll get_min_area(vector<pll> coords, int N) {
    vector<pll> psums = get_psums(coords, N);
    vector<pll> ssums = get_ssums(coords, N);

    ll min_area = LLONG_MAX;
    for (int i = 1; i < N; i++) {
        ll first_side1 = coords[i].first - coords[1].first;
        ll first_side2 = psums[i-1].second - psums[i-1].first;
        ll second_side1 = coords[N].first - coords[i+1].first;
        ll second_side2 = ssums[i].second - ssums[i].first;
        min_area = min(min_area, first_side1*first_side2+second_side1*second_side2);
    }

    return min_area;
}

int main() {

    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);

    int N;
    cin >> N;
    vector<pll> coords_xy(N+1, make_pair(0,0));
    vector<pll> coords_yx(N+1, make_pair(0,0));
    for (int i = 1; i <= N; i++) {
        ll x,y;
        cin >> x >> y;
        coords_xy[i] = make_pair(x,y);
        coords_yx[i] = make_pair(y,x);
    }

    sort(coords_xy.begin(),coords_xy.end());
    sort(coords_yx.begin(),coords_yx.end());

    ll min_area = min(get_min_area(coords_xy,N),get_min_area(coords_yx,N));

    ll max_width = coords_xy[N].first - coords_xy[1].first;
    ll max_height = coords_yx[N].first - coords_yx[1].first;

    cout << max_width*max_height - min_area;

    return 0;

}


