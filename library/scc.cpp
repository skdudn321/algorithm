class SCC {
public:
	int V, vertexCounter;
	vector< vector<int> > graph;
	std::stack<int> st;
	vector<int> low;

	int scc_V;
	vector<int> scc_num;

	void solve() {
		//get_data;
		init();
		for (int i = 1; i <= V; i++) {
			if (low[i] == -1) {
				scc(i);
			}
		}
	}
	int scc(int cur) {
		int ret = low[cur] = vertexCounter++;
		st.push(cur);
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (low[next] == -1) {
				ret = std::min(ret, scc(next));
			}
			else if (scc_num[next] == -1) {
				ret = std::min(ret, low[next]);
			}
		}

		if (ret == low[cur]) {
			while (1) {
				int t = st.top();
				scc_num[t] = scc_V;
				st.pop();
				if (t == cur) break;
			}
			scc_V++;
		}
		return ret;
	}
	void init() {
		vertexCounter = 0;
		scc_V = 0;
		while (!st.empty()) {
			st.pop();
		}
		low.clear();
		low.resize(V + 1, -1);
		scc_num.clear();
		scc_num.resize(V + 1, -1);
	}
};