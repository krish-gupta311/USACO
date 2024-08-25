#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("haybales.in");
ofstream fout("haybales.out");

int main() {

    int N, Q;
    fin >> N >> Q;

    vector<ll> haybales(N);
    for (int i = 0; i < N; i++) {
        fin >> haybales[i];
    }
    sort(haybales.begin(),haybales.end());

    for (int i = 0; i < Q; i++) {
        ll a, b;
        fin >> a >> b;
        fout << upper_bound(haybales.begin(),haybales.end(),b) - lower_bound(haybales.begin(),haybales.end(),a) << endl;
    }
    
}    