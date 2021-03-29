#include <stdio.h>
#include <vector>
using namespace std;

//��󶥵��� 
const int MAXV = 1000;
//
const int INF = 1000000000;
//int n, G[MAXV][MAXV];



//ͼG���ڽӱ� 
vector<int> Adj[MAXN]; 
//�������i�ѱ����� ��vis[i] = true 
bool vis[MAXV] = {false};

//uΪ��ǰ���ʵĶ����� depthΪ��� 
void DFS(int u, int depth){
	vis[u] = true;
	//��Ҫ��u����һЩ���� ���ڴ˴�����
	for(int i = 0; i < Adj[u].size(); i++){
		int v = Adj[u][i];
		if(vis[v] == false){
			DFS(V, depth+1);
		}
	} 
}

//����ͼG 
void DFSTrave(){
	//��ÿ������u 
	for(int u = 0; u < n; u++){
		//���uδ������ 
		if(vis[u] == false){
			//����u��u���ڵ���ͨ�� 1��ʾ��ʼΪ��һ�� 
			DFS(u, 1);
		}
	}
}
