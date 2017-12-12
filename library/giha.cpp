#define EQUAL(x, y) (fabs(x - y) < EPSILON) //x == y
#define LARGE(x, y) ((x - y) > EPSILON) //x > y
#define ELARGE(x, y) (EQUAL(x, y) || LARGE(x, y)) //x >= y

using std::vector;

const double PI = 2.0 * acos(0.0);
const double EPSILON = 0.000001;
const double D_INF = 1e200;

class DOT {
public:
	double x, y;
	
	DOT(double _x = 0, double _y = 0) { x = _x, y = _y; }

	bool operator== (const DOT & temp) { return (EQUAL(x, temp.x)) && (EQUAL(y, temp.y)); }
	bool operator!= (const DOT & temp) { return !((EQUAL(x, temp.x)) && (EQUAL(y, temp.y))); }
	bool operator< (const DOT & temp) { return (!(EQUAL(x, temp.x)) ? (LARGE(temp.x, x)) : (LARGE(temp.y, y))); } // x, y 순서
	bool operator<= (const DOT & temp) {
		return (EQUAL(x, temp.x)) && (EQUAL(y, temp.y)) ||
			(!(EQUAL(x, temp.x)) ? (LARGE(temp.x, x)) : (LARGE(temp.y, y)));
	}
	bool operator>(const DOT & temp) { return (!(EQUAL(x, temp.x)) ? (LARGE(x, temp.x)) : (LARGE(y, temp.y))); }
	bool operator>= (const DOT & temp) {
		return (EQUAL(x, temp.x)) && (EQUAL(y, temp.y)) ||
			(!(EQUAL(x, temp.x)) ? (LARGE(x, temp.x)) : (LARGE(y, temp.y)));
	}
	DOT operator+ (const DOT & temp) { return DOT(x + temp.x, y + temp.y); }
	DOT operator- (const DOT & temp) const { return DOT(x - temp.x, y - temp.y); }
	DOT operator* (const double temp) { return DOT(x * temp, y * temp); }

	double length() const { return hypot(x, y); }
	DOT unit_vector() const { return DOT(x / length(), y / length()); } // 단위벡터

	double seta() { return fmod(atan2(y, x) + 2 * PI, 2 * PI); } // x축으로 부터 양의 세타각
	double ne(const DOT & temp) { return x * temp.x + y * temp.y; } // 내적 a*b*cos (cos을 잘 활용하자 ex 직각 표현)
	double wae(const DOT & temp) const { return x * temp.y - y * temp.x; } // 외적 a*b*sin == a,b를 두변으로 하는 평행 사변형의 넓이

	DOT project(const DOT & temp) { DOT ret = temp.unit_vector(); return ret * ret.ne(*this); } // temp 벡터에 정사영
};

// first-second-third 반시계 양수, 시계 음수
double ccw(const DOT & a, const DOT & b, const DOT & c) { return (b - a).wae(c - a); }

class LINE {
public:
	DOT first, second; double a, b, c; // ax + by + c = 0;

	LINE() {}
	LINE(const DOT & _a, const DOT & _b) { first = _a, second = _b; if (first > second) swap(first, second); make_fun(); }

	void make_fun(void) { a = first.y - second.y; b = second.x - first.x; c = -(b * first.y) - (a * first.x); }
};

class POLYGON { public: vector<DOT> ve; };

DOT get_foot(DOT & dot, LINE & line) { return line.first + (dot - line.first).project(line.second - line.first); }

class INTERSECTION {
public:
	bool DOT_LINE(DOT & dot, LINE & line) {
		if (EQUAL(line.a * dot.x + line.b * dot.y + line.c, 0)) { return true; } return false;
	}
	bool DOT_SEG(DOT & dot, LINE & line) {
		if (DOT_LINE(dot, line) && line.first <= dot && dot <= line.second) { return true; } return false;
	}
	// 반환값 (1)-만남 (0)-안만남 (-1)-겹침
	int LINE_LINE(LINE & a, LINE & b, DOT & dot) {
		double value = (a.second - a.first).wae(b.second - b.first);
		if (EQUAL(value, 0)) { if (DOT_LINE(a.first, b)) { return -1; } return 0; }
		dot = a.first + (a.second - a.first) * ((b.first - a.first).wae(b.second - b.first) / value);
		return 1;
	}
	int SEG_LINE(LINE & seg, LINE & line, DOT & dot) {
		int ret = LINE_LINE(seg, line, dot);
		if (ret == 1) { if (!(seg.first <= dot && dot <= seg.second)) { return 0; } }
		return ret;
	}
	int SEG_SEG(LINE & a, LINE & b, DOT & dot) {
		int ret = LINE_LINE(a, b, dot);
		if (ret == -1) {
			if (a.second < b.first || b.second < a.first) { return 0; }
			if (a.second == b.first) { dot = b.first; return 1; }
			if (b.second == a.first) { dot = a.first; return 1; }
		}

		if (ret == 1) {
			if (!(a.first <= dot && dot <= a.second && b.first <= dot && dot <= b.second)) { return 0; }
		}
		return ret;
	}
	//모든 다각형과 점의 관계
	// 반환값 (1)-만남 (0)-외부 (-2)-내부
	int DOT_POLYGON(DOT & dot, POLYGON & polygon) {
		int cou = 0;
		for (int i = 0; i < polygon.ve.size(); i++) {
			int j = (i + 1) % polygon.ve.size();
			LINE cur_line(polygon.ve[i], polygon.ve[j]);
			if (DOT_SEG(dot, cur_line)) { return 1; }
			if (LARGE(polygon.ve[i].y, dot.y) != LARGE(polygon.ve[j].y, dot.y)) {
				double meet_x = -(cur_line.b * dot.y + cur_line.c) / cur_line.a;
				if (LARGE(meet_x, dot.x)) { cou++; }
			}
		}
		if (cou % 2 == 1) { return -2; }
		return 0;
	}
	//볼록다각형만
	// 반환값 (1이상)-만남 (0)-외부 (-1)-겹침 (-2)-내부
	int SEG_POLYGON(LINE & seg, POLYGON & polygon) {
		int ret = 0;
		for (int i = 0; i < polygon.ve.size(); i++) {
			LINE cur_seg(polygon.ve[i], polygon.ve[(i + 1) % polygon.ve.size()]);
			DOT temp_dot;
			int temp = SEG_SEG(seg, cur_seg, temp_dot);
			if (temp == 1) { if (temp_dot != polygon.ve[i]) { ret++; } }
			if (temp == -1) { return -1; }
		}
		if (DOT_POLYGON(seg.first, polygon) + DOT_POLYGON(seg.second, polygon) == -4) { return -2; }
		return ret;
	}
};

class LENGTH {
public:
	INTERSECTION inter; DOT temp;

	double DOT_DOT(DOT & a, DOT & b) { return (a - b).length(); }
	double DOT_SEG(DOT & dot, LINE & seg) {
		DOT foot = get_foot(dot, seg);
		if (seg.first <= foot && foot <= seg.second) { return (dot - foot).length(); }
		return min((dot - seg.first).length(), (dot - seg.second).length());
	}
	double DOT_LINE(DOT & dot, LINE & line) { return (dot - get_foot(dot, line)).length(); }
	double SEG_SEG(LINE & a, LINE & b) {
		if (inter.SEG_SEG(a, b, temp) == 0) {
			return min(min(DOT_SEG(a.first, b), DOT_SEG(a.second, b)), min(DOT_SEG(b.first, a), DOT_SEG(b.second, a)));
		}
		return 0;
	}
	double SEG_LINE(LINE & seg, LINE & line) {
		if (inter.SEG_LINE(seg, line, temp) == 0) { return min(DOT_SEG(seg.first, line), DOT_SEG(seg.second, line)); }
		return 0;
	}
	double LINE_LINE(LINE & a, LINE & b) { return SEG_LINE(a, b); }
};

//다각형이 반시계 or 시계로 주어질 때
double area(POLYGON & polygon) {
	double ret = 0;
	for (int i = 0; i < polygon.ve.size(); i++) {
		int j = (i + 1) % polygon.ve.size();
		ret += polygon.ve[i].x * polygon.ve[j].y - polygon.ve[i].y * polygon.ve[j].x;
	}
	return fabs(ret) / 2.0;
}

class CONVEX { // 가장 왼쪽-아래점으로 부터 반시계 방향의 볼록껍질
public:
	int N;
	static DOT dot;
	POLYGON polygon;
	POLYGON ans; // 기준점 시작 기준점 끝 주의!
				 //make_ans 실행
	void init() { polygon.ve.clear(); ans.ve.clear(); }
	void put_data() { /*직접 입력*/ }
	void make_ans() {
		init(); put_data();
		vector<DOT>::iterator temp = max_element(polygon.ve.begin(), polygon.ve.end(), cmp1);
		swap(*temp, polygon.ve[0]);
		dot = polygon.ve[0];
		DOT temp_dot = *(min_element(polygon.ve.begin(), polygon.ve.end(), cmp1));
		sort(polygon.ve.begin() + 1, polygon.ve.end(), cmp2);
		polygon.ve.push_back(dot);
		stack<DOT> st; st.push(dot); st.push(polygon.ve[1]);
		for (int i = 2; i <= N; i++) {
			DOT b = st.top(); st.pop();
			DOT a = st.top(); st.pop();
			if (LARGE(ccw(a, b, polygon.ve[i]), 0)) { st.push(a); st.push(b); st.push(polygon.ve[i]); }
			else if (st.empty()) { st.push(a); st.push(polygon.ve[i]); }
			else { st.push(a); i--; }
		}

		ans.ve.resize(st.size());
		while (!st.empty()) { ans.ve[st.size() - 1] = st.top(); st.pop(); }

		/*시계 버전
		while (!st.empty()) { ans.ve.push_back(st.top()); st.pop(); }
		*/

		if (ans.ve.size() == 2) { ans.ve[1] = temp_dot; }
		else { ans.ve.pop_back(); }
	}

	static bool cmp1(const DOT & a, const DOT & b) { return (!(EQUAL(a.y, b.y)) ? (LARGE(a.y, b.y)) : (LARGE(a.x, b.x))); }
	static bool cmp2(const DOT & a, const DOT & b) {
		if (EQUAL(ccw(dot, a, b), 0)) { double len = (a - dot).length() - (b - dot).length(); return (LARGE(0, len)); }
		return (LARGE(ccw(dot, a, b), 0));
	}
};
DOT CONVEX::dot;

class Hodgman { // 다각형 교집합 알고리즘(하나는 볼록다각형)
public:
	POLYGON convex_poly, normal_poly;
	void init() { convex_poly.ve.clear(); normal_poly.ve.clear(); }
	void put_data() { /*직접 입력*/ }
	void cut(DOT & a, DOT & b) {
		vector<bool> check;
		for (int i = 0; i < normal_poly.ve.size(); i++) {
			check.push_back(ELARGE(ccw(a, b, normal_poly.ve[i]), 0));
		}
		POLYGON ret; DOT cross; INTERSECTION inter;
		for (int i = 0; i < normal_poly.ve.size(); i++) {
			int j = (i + 1) % normal_poly.ve.size();
			if (check[i]) { ret.ve.push_back(normal_poly.ve[i]); }
			if (check[i] != check[j]) {
				LINE temp1(a, b); LINE temp2(normal_poly.ve[i], normal_poly.ve[j]);
				inter.LINE_LINE(temp1, temp2, cross);
				ret.ve.push_back(cross);
			}
		}
		normal_poly.ve.clear();
		for (int i = 0; i < ret.ve.size(); i++) {
			normal_poly.ve.push_back(ret.ve[i]);
		}
	}
	void make() {
		init(); put_data();
		double check = 0; int i = 0;
		while (EQUAL(check, 0)) { check = ccw(convex_poly.ve[i], convex_poly.ve[i + 1], convex_poly.ve[i + 2]); }
		if (LARGE(check, 0)) {
			for (i = 0; i < convex_poly.ve.size(); i++) {
				cut(convex_poly.ve[i], convex_poly.ve[(i + 1) % convex_poly.ve.size()]);
			}
		}
		else {
			for (i = convex_poly.ve.size() - 1; i >= 0; i--) {
				cut(convex_poly.ve[i], convex_poly.ve[(i - 1 + convex_poly.ve.size()) % convex_poly.ve.size()]);
			}
		}
	}
};

void rotating(POLYGON & convex, DOT & fi, DOT & se) {
	int i = 0, j = 1;
	fi = se = DOT(0, 0);

	for (; i < convex.ve.size(); i++) {
		int ni = (i + 1) % convex.ve.size();
		while (1) {
			int nj = (j + 1) % convex.ve.size();
			if (LARGE(ccw(DOT(0, 0), convex.ve[ni] - convex.ve[i], convex.ve[nj] - convex.ve[j]), 0)) {
				j = nj;
			}
			else { break; }
		}
		if (LARGE((convex.ve[i] - convex.ve[j]).length(), (se - fi).length())) {
			fi = convex.ve[i], se = convex.ve[j];
		}
	}
}
