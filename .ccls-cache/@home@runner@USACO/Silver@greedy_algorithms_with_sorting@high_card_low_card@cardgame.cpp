#include <bits/stdc++.h>
using namespace std;

ifstream fin("cardgame.in");
ofstream fout("cardgame.out");

int main() {

    int N;
    fin >> N;

    set<int> bessie;
    for (int i = 1; i < 2*N+1; i++) {
        bessie.insert(i);
    }
    vector<int> elsie_first(N/2);
    vector<int> elsie_second(N/2);
    for (int i = 0; i < N; i++) {
        int card;
        fin >> card;
        if (i < N/2) {
            elsie_first[i] = card;
        } else {
            elsie_second[i-N/2] = card;
        }
        bessie.erase(card);
    }

    set<int> bessie_first;
    set<int> bessie_second;
    int i = 0;
    for (int card : bessie) {
        if (i < N/2) {
            bessie_second.insert(card);
        } else {
            bessie_first.insert(card);
        }
        i++;
    }

    int wins = 0;
    for (const int card : elsie_first) {
        auto it = bessie_first.upper_bound(card);
        if (it != bessie_first.end()) {
            bessie_first.erase(it);
            wins++;
        } else {
            bessie_first.erase(bessie_first.begin());
        }
    }
    for (const int card : elsie_second) {
        auto it = bessie_second.lower_bound(card);
        if (it != bessie_second.begin()) {
            bessie_second.erase(--it);
            wins++;
        } else {
            bessie_second.erase(--bessie_second.end());
        }
    }
    fout << wins << endl;
    
}
