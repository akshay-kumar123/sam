#include <iostream>
using namespace std;

int lefter(int **climb, int n, int m, int ** visited, int x, int y){
	if(y == 0) return -1;
	if(climb[x][y-1] != 0) if(visited[x][y-1] == 0) return y-1;
	return -1;
}

int righter(int **climb, int n, int m, int ** visited, int x, int y){
	if(y == m-1) return -1;
	if(climb[x][y+1] != 0) if(visited[x][y+1] == 0) return y+1;
	return -1;
}

int upper(int **climb, int n, int m, int ** visited, int x, int y){
	if(x == 0) return -1;
	int i;
	for(i=1;i<=x;i++){
		if(climb[x-i][y] != 0){
			if(visited[x-i][y] == 0) return i;
			else return -1;
		}
	}
	return -1;
}

int downer(int **climb, int n, int m, int ** visited, int x, int y){
	if(x == n-1) return -1;
	int i;
	for(i=1;i<=n-1-x;i++){
		if(climb[x+i][y] != 0){
			if(visited[x+i][y] == 0) return i;
			else return -1;
		}
	}
	return -1;
}


int DFS(int **climb, int n, int m, int ** visited, int x, int y, int maxi){
	if(climb[x][y] == 3) return maxi;
	visited[x][y] = 1;
	// cout << x << " " << y << endl;
	int i,j, mini=100, val;
	int left = lefter(climb,n,m,visited,x,y);
	int right = righter(climb,n,m,visited,x,y);
	int up = upper(climb,n,m,visited,x,y);
	int down = downer(climb,n,m,visited,x,y);
	if(left != -1){
		val = DFS(climb,n,m,visited,x,left,maxi);
		visited[x][left] = 0;
		if(val != 100) mini = min(mini, val);
	}
	if(right != -1){
		val = DFS(climb,n,m,visited,x,right,maxi);
		visited[x][right] = 0;
		if(val != 100) mini = min(mini, val);
	}
	if(up != -1){
		maxi = max(maxi,up);
		val = DFS(climb,n,m,visited,x-up,y,maxi);
		visited[x-up][y] = 0;
		if(val != 100) mini = min(mini, val);
	}
	if(down != -1){
		maxi = max(maxi,up);
		val = DFS(climb,n,m,visited,x+down,y,maxi);
		visited[x+down][y] = 0;
		if(val != 100) mini = min(mini, val);
	}
	// visited[x][y] = 0;
	return mini;
}

int main(){
	int t,n,m,i,j,x,y;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int ** matrix = new int*[n];
		int ** visited = new int*[n];
		for(i=0; i<n; i++){
			matrix[i] = new int[m];
			visited[i] = new int[m];
			for(j=0;j<m;j++) cin >> matrix[i][j];
			for(j=0;j<m;j++) visited[i][j] = 0;
		}
		int shortdis = DFS(matrix,n,m,visited, n-1, 0, 0);
		cout << shortdis << endl;
	}
	
	return 1;
}