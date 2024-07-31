#include <bits/stdc++.h>
using namespace std;

int getIndex(vector<int> v, int value) {

    auto it = find(v.begin(),v.end(),value);

    if (it != v.end()) {
        int index = it - v.begin();
        return index;
    } else {
        return -1;
    }

}

int main() {

    freopen("lifeguards.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("lifeguards.out", "w", stdout);

    int N;
    cin >> N;
    
    vector<pair<int,int> > endpoints;
    for (int x = 0; x < N; x++) {
        int a,b;
        cin >> a >> b;
        endpoints.push_back(make_pair(a,x));
        endpoints.push_back(make_pair(b,x));
    }

    sort(endpoints.begin(),endpoints.end());

    set<int> working;
    int last_event = -1;
    int total = 0;
    vector<int> alone(N);
    for (auto point : endpoints) {
        if (!working.empty()) {
            total += point.first - last_event;
        }
        if (working.size() == 1) {
            alone[*working.begin()] += point.first - last_event;
        }
        if (working.find(point.second) != working.end()) {
            working.erase(point.second);
        } else {
            working.insert(point.second);
        }
        last_event = point.first;
    }

    sort(alone.begin(),alone.end());
    cout << total - alone[0];

    return 0;

}