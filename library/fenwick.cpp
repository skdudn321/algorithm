using std::vector;

class fenwick { // seg_update, seg_data
private:
	vector<lint> data[2];
	int size;

	int cal_size(int data_size) {
		int ret = 1;
		while (ret < data_size) {
			ret *= 2;
		}
		return ret + 1;
	}
	void change(int num, int ind, lint new_data) {
		for (; ind <= size; ind += (ind & (-ind))) {
			data[num][ind] += new_data;
		}
	}
	lint get(int num, int ind) {
		lint ret = 0;
		for (; ind != 0; ind &= (ind - 1)) {
			ret += data[num][ind];
		}
		return ret;
	}
	lint get(int ind) {
		return get(0, ind) * ind - get(1, ind);
	}
public:
	void change_data(int left, int right, lint new_data) {
		change(0, left, new_data);
		change(0, right + 1, -new_data);
		change(1, left, new_data * (left - 1));
		change(1, right + 1, -new_data * right);
	}
	lint get_data(int left, int right) {
		return get(right) - get(left - 1);
	}

	fenwick(int data_size) {
		size = cal_size(data_size);
		data[0].resize(size);
		data[1].resize(size);
		for (int i = 0; i < size; i++) {
			data[0][i] = 0;
			data[1][i] = 0;
		}
	}
};

class fenwick { // // one_update seg_data
private:
	lint * data;
	int size;

	int cal_size(int data_size) {
		int ret = 1;
		while (ret < data_size) {
			ret *= 2;
		}
		return ret + 1;
	}
	lint get_data(int ind) {
		lint ret = 0;
		while (ind != 0) {
			ret += data[ind];
			ind &= ind - 1;
		}
		return ret;
	}
public:
	void change_data(int ind, lint new_data) {
		lint cur_data = get_data(ind) - get_data(ind - 1);
		lint temp = new_data - cur_data;

		while (ind <= size) {
			data[ind] += temp;
			ind += (ind & -ind);
		}
	}
	lint get_data(int a, int b) {
		return get_data(std::max(a, b)) - get_data(std::min(a, b) - 1);
		return ret;
	}
	fenwick(int data_size) {
		size = cal_size(data_size);

		data = new lint[size];
	}
	fenwick() {
		delete[]data;
	}
};