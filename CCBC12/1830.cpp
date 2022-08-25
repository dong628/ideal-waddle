#include <cstdio>
#include <iostream>
#include <cstring>
using std::string;

const int Maxn = 114;
string stat[Maxn];
int answer[Maxn], n, num, len;
bool flag;
void dfs(int, int, string, int);
string shuffle0(string);
string shuffle1(string);

int main(){
//	freopen("1830.in", "r", stdin);

	scanf("%d %d %d", &n, &num, &len);
	for(int i=0; i<num; i++){
		std::cin >> stat[i];
	}
	dfs(0, 0, stat[0], 0);

	return 0;
}

void dfs(int floor, int per, string st, int cur){
	if(per == len){
		flag = true;
		for(int i=0; i<n; i++){
			if(stat[floor+1][i] != '-' && stat[floor+1][i] != st[i]) flag = false;
		}
		if(floor == num-2 && flag){
			answer[floor] = cur;
			for(int i=0; i<num; i++){
				printf("%c", char(answer[i]+96));
			}
			printf("\n");
		}
		else if(flag){
			answer[floor] = cur;
			dfs(floor+1, 0, st, 0);
			answer[floor] = 0;
		}
	}
	else{
		dfs(floor, per+1, shuffle0(st), cur);
		dfs(floor, per+1, shuffle1(st), cur|(1<<(len-per-1)));
	}
}

string shuffle0(string st){
	string s0;
	for(int i=0; i<n/2; i++){
		s0 = s0+st[i];
		s0 = s0+st[i+n/2];
	}
	return s0;
}

string shuffle1(string st){
	string s1;
	for(int i=0; i<n/2; i++){
		s1 = s1+st[i+n/2];
		s1 = s1+st[i];
	}
	return s1;
}
