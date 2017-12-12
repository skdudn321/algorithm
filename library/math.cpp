template<typename T>
T my_abs(T a) {
	return a < 0 ? -a : a;
}

lint gcd(lint a, lint b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

lint my_pow(lint a, lint b) { //a^b
	lint ret = 1;
	while (b != 0) {
		if (b % 2 == 0) {
			a = a*a;
			b /= 2;
		}
		else {
			ret = ret * a;
			b--;
		}
	}
	return ret;
}

lint my_pow(lint a, lint b, lint mod) { //a^b % mod
	lint ret = 1;
	a %= mod;
	while (b != 0) {
		if (b % 2 == 0) {
			a = (a * a) % mod;
			b /= 2;
		}
		else {
			ret = (ret * a) % mod;
			b--;
		}
	}
	return ret;
}

lint get_mod_inverse(lint div, lint mod) {
	return my_pow(div, mod - 2, mod);
}

lint phi(lint n) {
	lint ret = n;
	for (lint i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			ret -= (ret / i);
		}
	}
	if (n > 1) {
		ret -= ret / n;
	}
	return ret;
}

#define MOD 1000000007
#define SIZE 4000000
int f[SIZE + 1];
int inv[SIZE + 1];
void make_com() {
	inv[0] = inv[1] = f[0] = f[1] = 1;
	for (int i = 2; i <= SIZE; i++)f[i] = 1LL * f[i - 1] * i % MOD;
	for (int i = 2; i <= SIZE; i++)inv[i] = -1LL * (MOD / i) * inv[MOD % i] % MOD;
	for (int i = 2; i <= SIZE; i++)inv[i] = 1LL * inv[i - 1] * ((inv[i] + MOD) % MOD) % MOD;
}
int C(int n, int r) { return (long long)f[n] * inv[r] % MOD * inv[n - r] % MOD; }

//뫼비우스 함수
#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint dy[50003], chk[50003];
int main() {
	lint tc; scanf("%lld", &tc);
	dy[1] = 1;
	for (lint i = 1; i <= 50000; i++)
		chk[i] = 1;

	for (lint i = 2; i <= 50000; i++) {
		dy[i] = -chk[i];
		for (lint j = i; j <= 50000; j += i)
			chk[j] += dy[i];
		dy[i] += dy[i - 1];
	}

	while (tc--) {
		lint a, b, d; scanf("%lld %lld %lld", &a, &b, &d);

		lint ans = 0;
		a /= d, b /= d;
		d = 1;
		while (d <= a & d <= b) {
			lint ax = a / d;
			lint bx = b / d;
			lint idx = min((a / ax) + 1, (b / bx) + 1);

			ans += ax * bx * (dy[idx - 1] - dy[d - 1]);

			d = idx;
		}
		printf("%lld\n", ans);
	}
}



//교란 순열
d[n] = (n - 1) (d[n - 1] + d[n - 2]);
d[n] - n * d[n] = (-1) ^ n
1 0 1 2 9 44 265


//카탈랑 수
n쌍의 괄호로 만들 수 있는 올바른 괄호 구조의 개수
n + 2각형을 n개의 삼각형으로 나누는 방법의 수이다.
Cn은 n + 1개의 항에 괄호를 씌우는 모든 경우의 수이다.혹은 n + 1개의 항에 이항연산자를 적용하는 순서의 모든 가지수로도 볼 수 있다.
Cn은 n + 1개의 단말 노드를 갖는 이진 순서 트리의 개수
A[k] == 1 or A[k] == -1 일 때, A[1] + A[2] + .. + A[2n] = 0 일 때, 각각 부분합 A[1], A[1] + A[2], .., A[1] + A[2] + .. + A[n]이 모두 0 이상 되도록 하는 방법의 수
원탁에 있는 사람들이 엇갈리지 않고 악수하는 경우의 수
1 1 2 5 14 42 132 429

#include <stdio.h>
long long dp[10004];
int main()
{
	long long n;
	scanf("%lld", &n);
	n /= 2;
	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += dp[j] * dp[i - j - 1];
			dp[i] %= 987654321;
		}
	}
	printf("%lld", dp[n]);
}

//확장 유클리드
lint exdgcd(lint a, lint b, lint& x, lint& y) { // ax + by = return value
	lint d = a;
	if (b != 0) {
		d = exdgcd(b, a%b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}