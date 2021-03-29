#include <stdio.h>
#include <vector>
using namespace std;
const int maxn = 100; 
struct node{
	//边的终点编号 
	int v;
	//边的权重
	int w; 
	
	//构造函数 
	node(int _v, int _w) : v(_v), w(_w){};
};

int main(){
	vector<node> Adj[maxn]; 
	return 0;
} 

