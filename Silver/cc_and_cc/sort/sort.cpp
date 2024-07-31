#include <bits/stdc++.h>
using namespace std;

bool comp1(vector<int> a, vector<int> b) {
    return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
}

bool comp2(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int main() {

    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);

    int N;
    cin >> N;
    vector<vector<int> > arr(N,vector<int>(3));
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0];
        arr[i][1] = i;
        arr[i][2] = 0;
    }
    sort(arr.begin(),arr.end(),comp1);

    for (int i = 0; i < N; i++) {
        arr[i][2] = i;
    }
    sort(arr.begin(),arr.end(),comp2);

    vector<int> norm(N);
    for (int i = 0; i < N; i++) {
        norm[i] = arr[i][2];
    }

    int max_ = 0;
    for (int i = 0; i < N; i++) {
        max_ = max(max_,i - norm[i]);
    }

    cout << max_ + 1;

    return 0;

}