using std::vector;
using std::max;

class Union_Find {
public:
	vector<int> ve;
	vector<int> level;

	void init(int size); // vector 초기화
	int find(int num); // 값을 찾아주는 함수
	void merge(int num1, int num2); // 그룹 결합
};
void Union_Find::init(int size) {
	ve.resize(size + 1);
	level.resize(size + 1);

	for (int i = 0; i <= size; i++) {
		ve[i] = i;
		level[i] = 0;
	}
}
int Union_Find::find(int num) {
	if (num == ve[num]) {
		return num;
	}

	int ret = find(ve[num]);
	ve[num] = ret;
	return ret;
}
void Union_Find::merge(int num1, int num2) {
	num1 = find(num1);
	num2 = find(num2);
	if (num1 == num2) {
		return;
	}

	if (level[num1] >= level[num2]) {
		ve[num2] = num1;
		level[num1] = max(level[num1], 1 + level[num2]);
	}
	else {
		ve[num1] = num2;
		level[num2] = max(level[num2], 1 + level[num1]);
	}
}