#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int n[26];
char input[1000001];
string a;
int atoi(char c) {
	int tmp = (int)c - 65;
	if (tmp >= 32) tmp -= 32;
	return tmp;
}
int main(void) {
	scanf("%1000000s", input);
	a = input;
	for (int i = 0; i < a.size(); i++) {
		n[atoi(a.at(i))]++;
	}
	int idx = 0, value = 0, chk = 0;
	for (int i = 0; i < 26; i++) {
		if (value < n[i]) {
			value = n[i];
			idx = i;
			chk = 0;
		}
		else if (value == n[i]) {
			chk = 1;
		}
	}
	if (chk == 1) printf("?");
	else printf("%c", (char)(idx + 65));
}