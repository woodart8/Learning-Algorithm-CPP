#pragma GCC optimize ("Ofast")

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;



int histogram[51][36];	//[자릿수][해당digit] 개수 (0~35)


//36(digit) -> dec
constexpr int trans_digit(char n) {
	if (n>='0' && n<='9')
		return n-'0';
	return n - 'A' + 10;
}

//dec(digit) -> 36
constexpr char rtrans_digit(int n) {
	if (n < 10)
		return static_cast<char>(n+'0');
	return static_cast<char>(n-10+'A');
}

//dec(num) -> 36
string rtrans(int n) {
	string ret;

	while (n) {
		ret += rtrans_digit(n % 36);
		n /= 36;
	}

	reverse(ret.begin(), ret.end());
	return ret;
}

//36(num) + 36(num)
string add(string a, string b) {
	// a>=b가 되도록 (자릿수)
	if (b.size() > a.size())
		swap(a, b);

	// b 앞에 0으로 채움
	b = string(a.size()-b.size(), '0') + b;

	string ret;

	int carry=0;
	for (auto it1=a.rbegin(), it2=b.rbegin();
		it1 != a.rend();
		++it1, ++it2)
	{
		int sum = carry + trans_digit(*it1) + trans_digit(*it2);
		carry = sum / 36;
		sum %= 36;

		ret += rtrans_digit(sum);
	}

	if (carry)
		ret += '1';

	reverse(ret.begin(), ret.end());
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n;

	vector<string> words(n);
	for (auto& w : words) {
		cin >> w;

		int counter = 0;	//자릿수
		for (auto rit = w.rbegin();
			rit != w.rend();
			++rit, ++counter) {
			int digit = trans_digit(*rit);
			++histogram[counter][digit];

			// carry 발생
			if (histogram[counter][digit] == 36) {
				int current_idx = counter;
				while (histogram[current_idx][digit] == 36) {
					histogram[current_idx][digit] = 0;
					++current_idx;
					++histogram[current_idx][digit];
				}
			}
		}
	}

	cin >> k;
	vector<char> candidates;	// Z로 바꿀거

	vector<pair<string, int>> vp;	// diff, digit_idx
	for (int i = 0; i < 35; ++i) {	//z 빼고
		string diff;
		for (int j = 0; j < 51; ++j) {
			if (histogram[j][i]) {
				string s = rtrans(histogram[j][i] * (35-i)) + string(j, '0');
				diff = add(diff, s);
			}
		}

		vp.emplace_back(diff, i);
	}

	sort(vp.begin(), vp.end(), [](auto& lhs, auto& rhs) {
		auto &[s1, ign1] = lhs;
		auto &[s2, ign2] = rhs;
		
		if (s1.size() != s2.size())
			return s1.size() > s2.size();

		return s1 > s2;
	});

	for (int i = 0; i < min(k,35); ++i)
		candidates.push_back(rtrans_digit(vp[i].second));


	// 알파벳 변환
	for (auto& w : words) {
		for (auto& c : candidates) {
			replace(w.begin(), w.end(), c, 'Z');
		}
	}

	// 더함 (36진수)
	string ans;
	for (auto& w : words)
		ans = add(ans, w);
	cout << ans << '\n';

	return 0;
}