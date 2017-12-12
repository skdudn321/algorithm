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

//����콺 �Լ�
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



//���� ����
d[n] = (n - 1) (d[n - 1] + d[n - 2]);
d[n] - n * d[n] = (-1) ^ n
1 0 1 2 9 44 265


//īŻ�� ��
n���� ��ȣ�� ���� �� �ִ� �ùٸ� ��ȣ ������ ����
n + 2������ n���� �ﰢ������ ������ ����� ���̴�.
Cn�� n + 1���� �׿� ��ȣ�� ����� ��� ����� ���̴�.Ȥ�� n + 1���� �׿� ���׿����ڸ� �����ϴ� ������ ��� �������ε� �� �� �ִ�.
Cn�� n + 1���� �ܸ� ��带 ���� ���� ���� Ʈ���� ����
A[k] == 1 or A[k] == -1 �� ��, A[1] + A[2] + .. + A[2n] = 0 �� ��, ���� �κ��� A[1], A[1] + A[2], .., A[1] + A[2] + .. + A[n]�� ��� 0 �̻� �ǵ��� �ϴ� ����� ��
��Ź�� �ִ� ������� �������� �ʰ� �Ǽ��ϴ� ����� ��
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

//Ȯ�� ��Ŭ����
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