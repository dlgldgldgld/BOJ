#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<cstring>
using namespace std;

set<int> Ans;
int In[30];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf(" %d", &In[i]);
	sort(In, In + n);
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int curr : Ans) tmp.push_back(curr);
		Ans.insert(In[i]);
		if (i != 0) {
			for (int curr : tmp) Ans.insert(curr + In[i]), Ans.insert(abs(curr - In[i]));
		}
	}

	int m;
	scanf(" %d", &m);
	for (int i = 0; i < m; i++) {
		int tmp, chk = 0;
		scanf(" %d", &tmp);
		for (int k : Ans) if (tmp == k) chk = 1;
		if (chk == 1) printf("Y ");
		else printf("N ");
	}
}
