#include<stdio.h>
const int maxn = 100;
int father[maxn];
bool isRoot[maxn] = {false};

int findFather(int x){
	while(x != father[x]){
		x = father[x];
	}
	return x;
}

//集合的合并 
void Union(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

//路径的压缩
void compressPath(int x){
	//x最终被迭代成根结点  临时变量先保存x的值
	int a = x;
	while(x != father[x]){
		x = father[x];
	} 
	
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
} 

//初始化
void init(int n){
	for(int i = 1; i <= n; i++){
	father[i] = i;
}
} 

int main(){
	int n, m, friendA, friendB;
	scanf("%d%d",&n, &m);
	init(n);
	for(int i = 0; i < m; i++){
		scanf("%d%d",&friendA, &friendB);
		Union(friendA, friendB);
	}
	
	for(int i = 1; i <= n; i++){
		isRoot[findFather(i)] = true;
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += isRoot[i];
	}
	
	printf("%d\n",ans);
	return 0;
	
}

