#include <bits/stdc++.h>

using namespace std;

int dp[100][100][100][100];

int main(){
	for(int i = 0; i < 100; i++){
		dp[i][i][i][i] = i;
		cout << dp[i][i][i][i];
	}
}