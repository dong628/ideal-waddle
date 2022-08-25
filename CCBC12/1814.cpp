#include <cstdio>
#include <iostream>

int graph[3][3] = {
	{0, 1, 2}, 
	{5, 4, 3}, 
	{6, 7, 8} };
/*int graph[3][3] = {
	{0, 5, 6}, 
	{1, 4, 7}, 
	{2, 3, 8} };*/
int turn[3][3] = {
	{0, 3, 0},
	{1, 2, 1},
	{0, 3, 0} }; // 每个位置对应顺时针旋转角度
int nums[750], vis[750];

int pos(int, int, int); // 计算的是坐标对应的次序

int main(){
	freopen("1814.in", "r", stdin);
//	freopen("1814.out", "w", stdout);

	char ch; int tmp;
	for(int i=0; i<729; i++){
		ch = getchar();
		nums[i] = ch-'0';
	}
	for(int i=0; i<27; i++){
		for(int j=0; j<27; j++){
			tmp = pos(i, j, 9);
			vis[tmp] = true;
//			if(tmp>=729) printf("??\n");
			if(nums[tmp]){
				printf("1");
			}
			else{
				printf("0");
			}
//			printf("%d", nums[tmp]);
		}
		printf("\n");
	}

	return 0;
}

int pos(int x, int y, int pow){
	if(pow == 1){
		return graph[x][y];
	}
	else{
		int row = x/pow, col = y/pow, ans = 0, tmp;
//		ans += row*pow*pow*3+col*pow*pow;
		ans += graph[row][col]*pow*pow;
		x = x%pow; y = y%pow;
		// 计算旋转之后的坐标
		switch(turn[row][col]){
			case 3: tmp = x; x = y; y = pow-tmp-1; break;
			case 2: x = pow-x-1; y = pow-y-1; break;
			case 1: tmp = y; y = x; x = pow-tmp-1; break;
		}
		// 计算下一层的贡献
		ans += pos(x, y, pow/3);
		return ans;
	}
}

