using std::vector;

class matrix {
public:
	int N, M;
	vector< vector<lint> > dat;

	void operator=(matrix other) {
		dat.clear();
		N = other.N;
		M = other.M;
		dat = other.dat;
	}
	matrix operator+(matrix other) {
		matrix ret(N, M);
		for (unsigned int i = 0; i < dat.size(); i++) {
			for (unsigned int j = 0; j < dat[i].size(); j++) {
				ret.dat[i][j] = dat[i][j] + other.dat[i][j];
			}
		}
		return ret;
	}
	matrix operator-(matrix other) {
		matrix ret(N, M);
		for (unsigned int i = 0; i < dat.size(); i++) {
			for (unsigned int j = 0; j < dat[i].size(); j++) {
				ret.dat[i][j] = dat[i][j] - other.dat[i][j];
			}
		}
		return ret;
	}
	matrix operator*(matrix other) {
		matrix ret(N, other.M);
		for (unsigned int i = 0; i < ret.dat.size(); i++) {
			for (unsigned int j = 0; j < ret.dat[i].size(); j++) {
				for (unsigned int k = 0; k < dat[i].size(); k++) {
					ret.dat[i][j] = (ret.dat[i][j] + (dat[i][k] * other.dat[k][j]));
				}
			}
		}
		return ret;
	}
	void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				printf("%lld ", dat[i][j]);
			}
			printf("\n");
		}
	}
	matrix(int _N, int _M) {
		N = _N;
		M = _M;
		dat.resize(N);
		for (int i = 0; i < N; i++) {
			dat[i].resize(M, 0);
		}
	}
};

matrix my_pow(matrix a, lint b) { //a^b
	matrix ret(a.N, a.M);
	for (int i = 0; i < a.N; i++) {
		ret.dat[i][i] = 1;
	}
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