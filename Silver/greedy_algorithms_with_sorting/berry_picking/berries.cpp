#include <bits/stdc++.h>
using namespace std;

ifstream fin("berries.in");
ofstream fout("berries.out");

int main() {

    int N,K;
    fin >> N >> K;

    vector<int> trees;
    for (int i = 0; i < K; i++) {
        int t;
        fin >> t;
        trees.push_back(t);
    }
    sort(trees.begin(),trees.end(),greater<int>());
    vector<int> new_trees(trees.begin(),trees.begin()+K);
    trees = new_trees;

    int max_berries = 0;
    for (int basket_size = 1; basket_size <= trees[0]; basket_size++) {
        vector<int> baskets(K);
        int index_ = 0;
        for (int i = 0; i < K; i++) {
            if (trees[i] > basket_size) {
                for (int j = 0; j < floor(trees[i]/basket_size); j++) {
                    baskets[index_] = basket_size;
                    index_++;
                }
            } else {
                baskets[index_] = trees[i];
                index_++;
            }
        }
        sort(baskets.begin(),baskets.end());
        int berries = 0;
        for (int i = 0; i < K/2; i++) {
            berries += baskets[i];
        }
        max_berries = max(max_berries,berries);
    }

    fout << max_berries << endl;
    
}