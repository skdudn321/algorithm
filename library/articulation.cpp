class articulation {
public:
	int size;
	vector< vector<int> > graph;
	vector<bool> ans_dot;
	vector<pii> ans_line;

	int V, E;
	int ind;
	vector<int> dfn, low;
	vector<bool> check;

	void put_data() {
		//데이터 입력부분 (V, E / init / after)
	}
	void init(int N) {
		graph.resize(N + 1);
		check.resize(N + 1, 0);
		dfn.resize(N + 1, 0);
		low.resize(N + 1, 0);
		for (int i = 0; i <= N; i++) {
			graph[i].clear();
		}
		ans_dot.resize(N + 1, 0);
		ans_line.clear();
		ind = 0;
	}
	void make_ans() {
		for (int i = 1; i <= V; i++) {
			if (!check[i]) {
				dfs(i, 0);
			}
		}
	}
	int dfs(int num, int parent) {
		if (check[num]) return low[num];
		int cou = 0;
		check[num] = true;
		dfn[num] = ind++;
		low[num] = dfn[num];

		for (int i = 0; i < graph[num].size(); i++) {
			if (!check[graph[num][i]]) {
				cou++;
			}
			if (graph[num][i] != parent) {
				low[num] = std::min(low[num], dfs(graph[num][i], num));
			}
		}
		if (dfn[parent] <= low[num]) ans_dot[parent] = true;
		if (parent == 0) {
			if (cou >= 2) ans_dot[num] = true;
			else ans_dot[num] = false;
		}
		if (parent != 0 && dfn[parent] < low[num]) ans_line.push_back(pii(std::min(parent, num), std::max(parent, num)));

		return low[num];
	}
};