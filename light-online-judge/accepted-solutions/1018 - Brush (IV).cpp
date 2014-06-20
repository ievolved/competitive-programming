//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 1018 - Brush (IV) 
// Time Limit   : .000s
// Description  : 
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 16

int n, m, dp[BIT(maxN)], x[maxN], y[maxN];
int mask[maxN][maxN];

int get(int curMask) {
	if (dp[curMask] != INF) return dp[curMask];
	rep(i, n) if (curMask & BIT(i)) {
		rep(j, n) if (curMask & BIT(j)) {
			int nextMask = AND(curMask, ~mask[i][j]);
			dp[curMask] = min(dp[curMask], get(nextMask) + 1);
		}
		break;
	}
	return dp[curMask];
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n); m = BIT(n);
		rep(i, n) scanf("%d %d", &x[i], &y[i]);
		rep(i, n) {
			fr(j, i + 1, n - 1) {
				mask[i][j] = 0;
				int a, b, c;
				a = y[i] - y[j];
				b = x[j] - x[i];
				c = x[i] * y[j] - x[j] * y[i];
				rep(k, n)
					if (a * x[k] + b * y[k] + c == 0) mask[i][j] |= BIT(k);
				mask[j][i] = mask[i][j];
			}
			mask[i][i] = BIT(i);
		}
		rep(i, m) dp[i] = INF;
		dp[0] = 0;
		printf("Case %d: %d\n", ++caseNo, get(m - 1));
	}
	return 0;
}

// Copyright (C) 2012, LamPhanViet