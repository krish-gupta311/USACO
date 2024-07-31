// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// bool comp(pair<int, int> p1, pair<int, int> p2) {
//     return p1.second > p2.second;
// }

// pair<ll, vector<pair<int, int> > > getMoneyEarnedByCow(int gal, vector<pair<int, int> > stores) {
//     ll moneyEarnedByCow = 0;
//     int store = 0;
//     while (gal > 0 && store < stores.size()) {
//         int amountToSell = min(stores[store].first, gal);
//         moneyEarnedByCow += amountToSell * stores[store].second;
//         gal -= amountToSell;
//         stores[store].first -= amountToSell;
//         if (stores[store].first == 0) {
//             store++;
//         }
//     }
//     stores.erase(stores.begin(), stores.begin() + store);
//     return make_pair(moneyEarnedByCow, stores);
// }

// int main() {
//     freopen("rental.in", "r", stdin);
//     freopen("rental.out", "w", stdout);

//     int N, M, R;
//     cin >> N >> M >> R;

//     vector<int> cows(N);
//     for (int x = 0; x < N; x++) {
//         cin >> cows[x];
//     }
//     sort(cows.begin(), cows.end());

//     vector<pair<int, int> > stores(M);
//     for (int x = 0; x < M; x++) {
//         cin >> stores[x].first >> stores[x].second;
//     }
//     sort(stores.begin(), stores.end(), comp);

//     vector<int> farmers(R);
//     for (int x = 0; x < R; x++) {
//         cin >> farmers[x];
//     }
//     sort(farmers.begin(), farmers.end(), greater<int>());

//     int c1 = 0;
//     int c2 = N - 1;
//     ll total = 0;
//     while (c1 <= c2) {
//         ll sellToFarmer = c1 < farmers.size() ? farmers[c1] : 0;

//         auto result = getMoneyEarnedByCow(cows[c2], stores);
//         ll sellToStore = result.first;

//         if (sellToFarmer >= sellToStore) {
//             total += sellToFarmer;
//             c1++;
//         } else {
//             total += sellToStore;
//             stores = result.second;
//             c2--;
//         }
//     }

//     cout << total << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int N, M, R;
    cin >> N >> M >> R;

    vector<int> cows(N);
    for (int x = 0; x < N; x++) {
        cin >> cows[x];
    }
    sort(cows.begin(), cows.end());

    vector<pair<int, int> > stores(M);
    for (int x = 0; x < M; x++) {
        cin >> stores[x].second >> stores[x].first;
    }
    sort(stores.begin(), stores.end(), comp);

    vector<int> farmers(R);
    for (int x = 0; x < R; x++) {
        cin >> farmers[x];
    }
    sort(farmers.begin(), farmers.end(), greater<int>());

    long long total = 0;
    int left = 0;
    int right = N-1;
    int s = 0;
    int f = 0;

    while ((s < M || f < R) && left <= right) {
        if (s==M) {
        total += farmers[f];
        f++;
        left++;
        continue;
        }

        int sValue = 0;
        int ss = s;
        int newVal = 0;
        int milk = cows[right];
        while (ss < M) {
        if (stores[ss].second >= milk) {
            sValue += milk * stores[ss].first;
            newVal = stores[ss].second - milk;
            break;
        }
        sValue += stores[ss].second * stores[ss].first;
        milk -= stores[ss].second;
        ss++;
        }

        int fValue = f == R ? 0 : farmers[f];

        if (sValue >= fValue) {
        s = ss;
        if (s < M) {
            stores[s].second = newVal;
        }
        total += sValue;
        right--;
        } else {
        total += farmers[f];
        f++;
        left++;
        }
    }

    cout << total << endl;


    return 0;
}