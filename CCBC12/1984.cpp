#include <cstdio>
#include <iostream>
using std::min, std::max;

int num[15][15], red[15][15], green[15][15], color[15][15], blue[15][15];
int cnt;
void dfs(int);

int main(){
	freopen("1984.in", "r", stdin);
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			scanf("%d", &num[i][j]);
		}
	}
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			scanf("%d", &color[i][j]);
			switch(color[i][j]){
				case 2: red[i][j] = num[i][j]; break;
				case 3: green[i][j] = num[i][j]; break;
				case 4: blue[i][j] = num[i][j]; break;
			}
		}
	}

	dfs(0);

	return 0;
}

void dfs(int cur){
	if(cur == 81){
		cnt++;
//		printf("R\n");
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				printf("%d ", red[i][j]);
			}
			printf("\n");
		}
		printf("\n");
//		printf("G\n");
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				printf("%d ", green[i][j]);
			}
			printf("\n");
		}
		printf("\n");
//		printf("B\n");
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				printf("%d ", blue[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	if(color[cur/9][cur%9]<=4) dfs(cur+1);
	else{
		bool flag;
		int row = cur/9, col = cur%9;
		int r1 = row-row%3, c1 = col-col%3;
		if(color[row][col] == 5){
			for(int i=max(num[row][col]-9, 1); i<min(10, num[row][col]); i++){
				flag = true;
				for(int j=0; j<9; j++){
					if(red[j][col]==i||red[row][j]==i||green[j][col]==num[row][col]-i||green[row][j]==num[row][col]-i){
						flag = false;
						break;
					}
				}
				for(int j=0; j<3; j++){
					for(int k=0; k<3; k++){
						if(red[r1+j][c1+k]==i||green[r1+j][c1+k]==num[row][col]-i){
							flag = false;
							break;
						}
					}
				}
				if(flag){
					red[row][col] = i;
					green[row][col] = num[row][col] - i;
					dfs(cur+1);
					red[row][col] = 0;
					green[row][col] = 0;
				}
			}
		}
		if(color[row][col] == 6){
			for(int i=max(num[row][col]-9, 1); i<min(10, num[row][col]); i++){
				flag = true;
				for(int j=0; j<9; j++){
					if(red[j][col]==i||red[row][j]==i||blue[j][col]==num[row][col]-i||blue[row][j]==num[row][col]-i){
						flag = false;
						break;
					}
				}
				for(int j=0; j<3; j++){
					for(int k=0; k<3; k++){
						if(red[r1+j][c1+k]==i||blue[r1+j][c1+k]==num[row][col]-i){
							flag = false;
							break;
						}
					}
				}
				if(flag){
					red[row][col] = i;
					blue[row][col] = num[row][col] - i;
					dfs(cur+1);
					red[row][col] = 0;
					blue[row][col] = 0;
				}
			}
		}
		if(color[row][col] == 7){
			for(int i=max(num[row][col]-9, 1); i<min(10, num[row][col]); i++){
				flag = true;
				for(int j=0; j<9; j++){
					if(green[j][col]==i||green[row][j]==i||blue[j][col]==num[row][col]-i||blue[row][j]==num[row][col]-i){
						flag = false;
						break;
					}
				}
				for(int j=0; j<3; j++){
					for(int k=0; k<3; k++){
						if(green[r1+j][c1+k]==i||blue[r1+j][c1+k]==num[row][col]-i){
							flag = false;
							break;
						}
					}
				}
				if(flag){
					green[row][col] = i;
					blue[row][col] = num[row][col] - i;
					dfs(cur+1);
					green[row][col] = 0;
					blue[row][col] = 0;
				}
			}
		}
	}
}
