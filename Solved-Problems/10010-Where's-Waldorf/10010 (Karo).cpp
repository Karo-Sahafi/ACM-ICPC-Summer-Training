#include <iostream>
#include <cstdio>
#include <array>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

#define DEF 50

using namespace std;

char arr[150][150];

bool check(char name[],int m,int n,int x,int y){
	int dirX = 0,dirY = 0;
	int i;

	for(i = 0 ; name[i] ; i++){
		if(tolower(name[i]) != arr[DEF+m+dirX][DEF+n+dirY]){
			return false;
		}
		dirX += x;
		dirY += y;
	}
	return true;
}

void fill_array(){
	int i,j;
	for(i = 0 ; i < 150 ; i++){
		for(j = 0 ; j < 150 ; j++){
			arr[i][j] = ' ';
		}
	}
}


int main(){
	int i,j,t,u,flag;
	int m,n,k;
	int p;
	char c;
	char name[100];
	scanf("%d",&t);
	int dir[8][2] = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
	int x,y;
	while(t--){
		scanf("%d%d",&m,&n);
		fill_array();
		for(i = 0 ; i < m ; i++){
			scanf("%s",name);
			for(j = 0 ; j < n ; j++){
				arr[DEF + i][DEF + j] = tolower(name[j]);
			}
		}

		scanf("%d",&p);
		for(u = 0 ; u < p ; u++){
			scanf("%s",name);
			x = 300;
			y = 300;
			for(i = 0 ; i < m ; i++){
				for(j = 0 ; j < n ; j++){
					for(k = 0 ; k < 8 ; k++){
						if(check(name,i,j,dir[k][0],dir[k][1])){
							//printf("-> %d %d\n",i,j);
							if(i <= x && j < y){
								x = i;
								y = j;
							}
						}
					}
				}
			}
			printf("%d %d\n",x+1,y+1);
		}
		if(t != 0) printf("\n");
	}
	return 0;
}
