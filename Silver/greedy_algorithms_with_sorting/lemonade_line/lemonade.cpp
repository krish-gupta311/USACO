#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("lemonade.in");
ofstream fout("lemonade.out");

int main() {

    int N;
    fin >> N;

    vector<ll> cows(N);
    for (int i = 0; i < N; i++) {
        fin >> cows[i];
    }
    sort(cows.begin(), cows.end(),greater<ll>());
    
    int line = 0;
    for (const ll cow : cows) {
        if (cow >= line) {
            line++;
        } else {
            break;
        }
    }
    fout << line << endl;
}