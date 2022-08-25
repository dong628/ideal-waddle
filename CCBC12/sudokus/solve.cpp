#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int ss[9][9]={
	{6,  6,  6,  6,  6,  6,  6,  6,  6},
	{6,  7,  7,  7,  7,  7,  7,  7,  6},
	{6,  7,  8,  8,  8,  8,  8,  7,  6},
	{6,  7,  8,  9,  9,  9,  8,  7,  6},
	{6,  7,  8,  9,  10, 9,  8,  7,  6},
	{6,  7,  8,  9,  9,  9,  8,  7,  6},
	{6,  7,  8,  8,  8,  8,  8,  7,  6},
	{6,  7,  7,  7,  7,  7,  7,  7,  6},
	{6,  6,  6,  6,  6,  6,  6,  6,  6},
};
int hang[10][10], lie[10][10], sq[3][3][10], cnt[10][10], mapp[10][10], rear[10], hxb[10], rh, score, maxs=-1, z;
void dfs(int, int, int);
int co();

int main(){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin >> mapp[i][j];
			if(mapp[i][j]){
				hang[i][mapp[i][j]]=1;
				lie[j][mapp[i][j]]=1;
				sq[(i+1)/3-((i+1)%3?0:1)][(j+1)/3-((j+1)%3?0:1)][mapp[i][j]]=1;
			}
			else{
				z++;
			}
		}
		cnt[z][rear[z]++]=i;
		z=0;
	}

/*	for(int i=0; i<9; i++){
		for(int j=0; j<rear[i]; j++){
			dfs(cnt[i][rear[i]], 1);
		}
	}*/
	
	for(int i=0; i<=9; i++){
		for(int j=0; j<rear[i]; j++){
			hxb[rh++]=cnt[i][j];
		}
	}

	dfs(hxb[0], 0, 0);
	cout << maxs;

	return 0;
}

void dfs(int x, int y, int h){
	if(h==9) return;
	if(score=co()){
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				cout << mapp[i][j] << ' ';
			}
			cout << endl;
		}
		exit(0);
	}
	if(y==9){
		for(int i=0; i<=9; i++){
			if(mapp[hxb[h+1]][i]==0){
				dfs(hxb[h+1], i, h+1);
				return;
			}
		}
	}
	if(mapp[x][y]!=0){
		dfs(x, y+1, h);
		return;
	}
	else{
		for(int i=1; i<=9; i++){
			if(hang[x][i]==0 && lie[y][i]==0 && sq[(x+1)/3-((x+1)%3?0:1)][(y+1)/3-((y+1)%3?0:1)][i]==0){

				hang[x][i]=1;
				lie[y][i]=1;
				sq[(x+1)/3-((x+1)%3?0:1)][(y+1)/3-((y+1)%3?0:1)][i]=1;

				mapp[x][y]=i;
				dfs(x, y+1, h);
				mapp[x][y]=0;

				hang[x][i]=0;
				lie[y][i]=0;
				sq[(x+1)/3-((x+1)%3?0:1)][(y+1)/3-((y+1)%3?0:1)][i]=0;
			}
		}
	}
}

int co(){
	int sco=0;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(mapp[i][j]==0){
				return 0;
			}
			else{
				sco+=mapp[i][j]*ss[i][j];
			}
		}
	}
	return sco;
}
