#include <iostream>
using namespace std;

int mindist(int *dist, int *visited,int v){
	int i,index=0;
	int mini = 10000;
	for(i=0;i<v;i++){
		if(visited[i] == 0) if(mini > dist[i]){
			mini = dist[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int **cost, int *dist, int *visited,int s, int v){
	visited[s] = 1;
	dist[s] = 0;
	int i,mini,j;
	for(i=0;i<v;i++){
		mini = mindist(dist,visited,v);
		// cout << mini << " ";
		visited[mini] = 1;
		for(j=0;j<v;j++){
			if(visited[j] == 0 && cost[mini][j] && dist[mini] != 10000) if(dist[mini]+cost[mini][j] < dist[j]) dist[j] = dist[mini]+cost[mini][j];
		}
	}

}

int main(){
	int i,j,v;
	cin >> v;
	int **cost = new int*[v];
	int *dist = new int[v];
	int *visited = new int[v];
	for(i=0;i<v;i++){
		cost[i] = new int[v];
		for(j=0;j<v;j++) cin >> cost[i][j];
		dist[i] = 10000;
		visited[i] = 0;
	}
	dijkstra(cost,dist,visited,0,v);
	for(i=0;i<v;i++) cout << i << " " << dist[i] << endl;
	return 1;
}