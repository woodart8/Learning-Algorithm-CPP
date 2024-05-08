#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int,int>> arr;
vector<int> Tree;

int init(int start, int end, int node) {
    if (start == end) return Tree[node] = 1;
    return Tree[node] = init(start, (start+end)/2, node*2) + init((start+end)/2+1, end, node*2+1);
}

int query(int node, int start, int end, int left, int right) {
	if(right < start || left > end) return 0;
	if(left <= start && right >= end) return Tree[node];
	return query(node*2, start, (start+end)/2, left, right) + query(node*2+1, (start+end)/2+1, end, left, right);
}

void updateTree(int node, int start, int end, int idx) {
	if(idx > end || idx < start) return;
	if(start == end) {
		Tree[node] = 0;
		return;
	}
	updateTree(node*2, start, (start+end)/2, idx);
	updateTree(node*2+1, (start+end)/2+1, end, idx);
	Tree[node] = Tree[node*2] + Tree[node*2+1];
	return;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		arr.push_back({k,i});
	}

	int treeDepth = (int)ceil(log2(N));
	int treeSize = 1<<treeDepth+1;
	Tree.resize(treeSize);
	init(0, N-1, 1);
	sort(arr.begin(), arr.end());

	long long ans = 0;
	for(int i=0; i<N; i++) {
		int q = arr[i].second;
		ans += query(1, 0, N-1, 0, q)-1;
		updateTree(1,0,N-1,q);
	}
	cout << ans << '\n';
	return 0;
}