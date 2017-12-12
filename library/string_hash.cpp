#define HASHA 107
#define HASHB 109

using pll = std::pair<lint, lint>;
vector<int> str;
pll get_hash() {
	lint ret1 = 0, ret2 = 0;
	lint jisu1 = HASHA;
	lint jisu2 = HASHB;
	for (int i = str.size(); i >= 0; i--) {
		ret1 = (ret1 + (str[i] - 'A' + 1) * jisu1);
		ret2 = (ret2 + (str[i] - 'A' + 1) * jisu2);
		jisu1 = (jisu1 * HASHA);
		jisu2 = (jisu2 * HASHB);
	}
	return pll(ret1, ret2);
}