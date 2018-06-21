#include <iostream>
using namespace std;

int dfs(int **graph, int *visited, int n, int s, int &count){
	int i;
	visited[s] = 1;
	count++;
	if(count == n){
		 return 1;
	}
	for(i=0;i<n;i++){
		if(graph[s][i] == 1 and visited[i] == 0){
			if(dfs(graph,visited,n,i,count) == 1) return 1;
		}
	}
	visited[s] = 0;
	count--;
	return 0;
}

int main(){
	int t,n,m,i,j,k,a,b,c;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int **graph = new int*[n];
		int *visited = new int[n];
		for(i=0;i<n;i++){
			visited[i] = 0;
			graph[i] = new int[n];
			for(j=0;j<n;j++) graph[i][j] = 0;
		}
		for(i=0;i<m;i++){
			cin >> a >> b;
			a--;b--;
			graph[a][b] = 1;
			graph[b][a] = 1;
		}
		int count = 0;
		int flag = 0;
		for(i=0;i<n;i++)
		if(dfs(graph,visited,n,i,count)) flag = 1;
		cout << flag << endl;
	}
	return 0;
}