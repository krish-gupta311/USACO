#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("bcount.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("bcount.out", "w", stdout);

	// cin now reads from the input file instead of standard input
	int N,Q;
	cin >> N >> Q;

	int cows[N];
	for (int x=0; x < N; x++) {
		cin >> cows[x];
	}

	int sums[N+1][3];
	for (int i = 0; i < N+1; i++) {
  		for (int j = 0; j < 3; j++) {
    		sums[i][j] = 0;
  		}
	}
	for (int x=1; x <= N; x++) {
		sums[x][0] = sums[x-1][0];
		sums[x][1] = sums[x-1][1];
		sums[x][2] = sums[x-1][2];
		sums[x][cows[x-1] - 1]++;
	}
	// for (int i = 0; i < N+1; i++) {
  	// 	for (int j = 0; j < 3; j++) {
    // 		cout << sums[i][j] << " ";
  	// 	}
	// 	cout << "\n";
	// }


	for (int x=0; x < Q; x++) {
		int a,b;
		cin >> a >> b;
		cout << sums[b][0] - sums[a-1][0] << " " << sums[b][1] - sums[a-1][1] << " " << sums[b][2] - sums[a-1][2] << "\n";
	}
}

