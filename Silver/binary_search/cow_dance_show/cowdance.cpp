#include <bits/stdc++.h>
using namespace std;

ifstream fin("cowdance.in");
ofstream fout("cowdance.out");

int first_true(int lo, int hi, function<bool(int)> f) {

    lo--;
    while (lo < hi) {
        int mid = lo + floor((hi - lo)/2);
        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
    
}

int main() {

    int N, T;
    fin >> N >> T;

    vector<int> cows(N);
    for (int i = 0; i < N; i++) {
        fin >> cows[i];
    }

    int min_K = first_true(1,N, [&](int K) {
        multiset<int> stage;
        for (int i = 0; i < K; i++) {
            stage.insert(cows[i]);
        }
        int currentTime = 0;
        int cowNum = K;
        while (currentTime < T) {
            int count = stage.count(currentTime);
            if (count != 0) {
                for (int i = 0; i < count; i++) {
                    stage.erase(stage.begin());
                }
                for (int i = 0; i < count; i++) {
                    if (cowNum != N) {
                        int end_time = currentTime+cows[cowNum++];
                        if (end_time > T) {
                            return false;
                        } else {
                            stage.insert(end_time);
                        }
                    } else {
                        return true;
                    }
                }
            }
            currentTime++;
        }
        return true;
    });

    fout << min_K << endl;
    
}