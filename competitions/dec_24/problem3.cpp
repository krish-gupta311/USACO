#include <bits/stdc++.h>
using namespace std;

ifstream fin("three.in");
ofstream fout("three.out");

int floodfill(vector<vector<char> >& grid) {

    

}

int main () {

    int N, Q;
    fin >> N >> Q;

    vector<vector<char> > grid(N,vector<char>(N,'?'));
    vector<vector<int> > days;
    for (int i = 0; i < Q; i++) {
        int r,c;
        char t;
        fin >> r >> c >> t;
        r--;
        c--;
        days.emplace_back(r,c,t);
    }

    for (auto day : days) {
        grid[day[0]][day[1]] = day[2];
    }

}