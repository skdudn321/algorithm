using pll = std::pair<lint, lint>;
using std::vector;

class segtree { // seg_update, seg_data
private:
	vector<pii> lor;
	vector<pll> data;
	int size;

	int cal_size(int data_size) {
		int ret = 1;
		while (ret < data_size) {
			ret *= 2;
		}
		return ret * 2 + 1;
	}
	void make_lor(int ind, int left, int right) {
		lor[ind] = pii(left, right);
		if (left == right) {
			return;
		}
		int mid = (left + right) / 2;
		make_lor(ind * 2, left, mid);
		make_lor(ind * 2 + 1, mid + 1, right);
	}
	void change_data(int ind, int left, int right, lint num) {
		if (left == lor[ind].first && right == lor[ind].second) {
			data[ind].second += num;
			ind /= 2;
			while (ind != 0) {
				data[ind].first += num * (right - left + 1);
				ind /= 2;
			}
			return;
		}

		int mid = (lor[ind].first + lor[ind].second) / 2;
		if (left > mid) {
			change_data(ind * 2 + 1, left, right, num);
		}
		else if (right <= mid) {
			change_data(ind * 2, left, right, num);
		}
		else {
			change_data(ind * 2, left, mid, num);
			change_data(ind * 2 + 1, mid + 1, right, num);
		}
	}
	lint get_data(int ind, int left, int right) {
		if (left == lor[ind].first && right == lor[ind].second) {
			lint ret = data[ind].first + data[ind].second * (right - left + 1);
			return ret;
		}

		lint ret = 0;

		int mid = (lor[ind].first + lor[ind].second) / 2;
		if (data[ind].second != 0) {
			data[ind].first += data[ind].second * (lor[ind].second - lor[ind].first + 1);
			data[ind * 2].second += data[ind].second;
			data[ind * 2 + 1].second += data[ind].second;
			data[ind].second = 0;
		}
		if (left > mid) {
			ret = get_data(ind * 2 + 1, left, right);
		}
		else if (right <= mid) {
			ret = get_data(ind * 2, left, right);
		}
		else {
			ret = get_data(ind * 2, left, mid) + get_data(ind * 2 + 1, mid + 1, right);
		}

		return ret;
	}
public:
	void change_data(int left, int right, lint num) {
		change_data(1, left, right, num);
	}
	lint get_data(int left, int right) {
		return get_data(1, left, right);
	}
	segtree(int N) {
		size = cal_size(N);
		lor.resize(size);
		data.resize(size, pll(0, 0));
		make_lor(1, 1, size / 2);
	}
};


using std::vector
using lint = long long int;

class index_tree { // one_update seg_data add_data 
private:
	vector<lint> data;
	int size;
	int cal_size(int N) {
		int ret = 1;
		while (ret < N) {
			ret *= 2;
		}
		return ret;
	}
public:
	void change_data(int idx, lint new_data) {
		idx += size - 1;
		while (idx != 0) {
			data[idx] += new_data;
			idx /= 2;
		}
	}
	lint get_data(int left, int right) {
		lint ret = 0;
		left += size - 1; right += size - 1;
		while (left <= right) {
			if (left % 2 == 1)ret += data[left];
			if (right % 2 == 0)ret += data[right];
			left = (left + 1) / 2;
			right = (right - 1) / 2;
		}
		return ret;
	}
	index_tree(int N) {
		size = cal_size(N);
		data.resize(size * 2 + 1);
	}
};