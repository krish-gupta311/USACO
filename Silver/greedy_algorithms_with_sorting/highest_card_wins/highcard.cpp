#include <bits/stdc++.h>
using namespace std;

ifstream fin("highcard.in");
ofstream fout("highcard.out");

int main() {

    int N;
    fin >> N;

    set<int> bessie;
    for (int i = 0; i < 2*N; i++) {
        bessie.insert(i);
    }
    vector<int> elsie;
    for (int i = 0; i < N; i++) {
        int card;
        fin >> card;
        elsie.push_back(card);
        bessie.erase(card);
    }

    int wins = 0;
    for (const int card : elsie) {
        auto it = bessie.upper_bound(card);
        if (it != bessie.end()) {
            wins++;
            bessie.erase(it);
        } else {
            bessie.erase(bessie.begin());
        }
    }

    fout << wins << endl;
    
}