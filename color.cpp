#include <iostream>
using namespace std;

int color_graph(int **graph, int *color, int s, int m, int n){
	if(color[s] > -1) return 1;
	int i,j,col=-1,flag=0;
	for(i=0;i<n;i++){
		flag = 0;
		for(j=0;j<n;j++)
		if(graph[s][j] == 1) if(color[j] == i) flag = 1;
	if(flag == 0) break;
	}
	color[s] = i;
	if(i+1 > m){
		 return 0;
	}
	for(i=0;i<n;i++){
		if(graph[s][i] == 1) if(color[i] == -1) return color_graph(graph,color,i,m,n);
	}
	return 1;
}

int main(){
	int i,j,t,a,b,n,m,e;
	cin >> t;
	while(t--){
		cin >> n >> m >> e;
		int **graph = new int *[n];
		int *color = new int[n];
		for(i=0;i<n;i++){
			color[i] = -1;
			graph[i] = new int[n];
			for(j=0;j<n;j++) graph[i][j] = 0;
		}
		for(i=0;i<e;i++){
			cin >> a >> b;
			a--;b--;
			graph[a][b] = 1;
			graph[b][a] = 1;
		}
		int flag = 1;
		for(i=0;i<n;i++){
			if(color_graph(graph,color,i,m,n) == 0) flag = 0;
		}
		
		cout << flag << endl;
	}
}