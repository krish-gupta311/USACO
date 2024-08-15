#include <bits/stdc++.h>
using namespace std;

ifstream fin("berries.in");
ofstream fout("berries.out");

int main() {

    int N,K;
    fin >> N >> K;

    vector<int> trees(N);
    for (int i = 0; i < N; i++) {
        fin >> trees[i];
    }

    int max_berries = 0;
    for (int basket_size = 1; basket_size <= 1000; basket_size++) {
        
        vector<int> baskets;
        for (int i = 0; i < N; i++) {
            int count = trees[i] / basket_size;
            for (int j = 0; j < count; j++) {
                baskets.push_back(basket_size);
            }
            int remainder = trees[i] % basket_size;
            if (remainder > 0) {
                baskets.push_back(remainder);
            }
        }

        sort(baskets.rbegin(), baskets.rend());

        int berries_total = 0;
        for (int i = K / 2; i < min(K, (int)baskets.size()); i++) {
            berries_total += baskets[i];
        }

        max_berries = max(max_berries, berries_total);
    }

    fout << max_berries << endl;

    return 0;
    
}