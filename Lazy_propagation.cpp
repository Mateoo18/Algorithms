//Mateusz Nowak
#include <bits/stdc++.h>
using namespace std;

const int mx = 100005;

/******* param ***********
 * arr[]  - main array
 * tree[] - conceptual tree
 * b      - begin index
 * e      - end index
 * node   - root node index
 * ls     - left part sum
 * rs     - right part sum
 * val    - new value to add
 * prop   - propagate value
 * carry  - carrying propagate value
 *************************/

int arr[mx];

struct info {
	int sum, prop;
} tree[mx * 4];

void init(int node, int b, int e) {
	if (b == e) {
		tree[node].sum = arr[b];
		return;
	}
	int left = node << 1;
	int right = (node << 1) + 1;
	int mid = (b + e) >> 1;
	init(left, b, mid);
	init(right, mid + 1, e);
	tree[node].sum = tree[left].sum + tree[right].sum;
}

int query(int node, int b, int e, int i, int j, int carry = 0) {
	if (i > e || j < b) return 0;
	if (b >= i && e <= j) return tree[node].sum + carry * (e - b + 1);
	int left = node << 1;
	int right = (node << 1) + 1;
	int mid = (b + e) >> 1;
	int ls = query(left, b, mid, i, j, carry + tree[node].prop);
	int rs = query(right, mid + 1, e, i, j, carry + tree[node].prop);
	return ls + rs;
}

void update(int node, int b, int e, int i, int j, int val) {
	if (i > e || j < b) return;
	if (b >= i && e <= j) {
		tree[node].sum += ((e - b + 1) * val);
		tree[node].prop = val;
		return;
	}
	int left = node << 1;
	int right = (node << 1) + 1;
	int mid = (b + e) >> 1;
	update(left, b, mid, i, j, val);
	update(right, mid + 1, e, i, j, val);
	tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
}

int main() {
	// freopen("in", "r", stdin);

	int n, q, k, i, j, val;
	cin>>n>>q;
	for (int i = 1; i <= n; i++)cin>>arr[i];
	init(1, 1, n);
	while (q--) {
            cin>>k>>i>>j;
		if (k == 0) cout<< query(1, 1, n, i, j, 0);
		else if (k == 1) {
			cin>>val;
			update(1, 1, n, i, j, val);
		}
	}
}
