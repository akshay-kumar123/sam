#include <iostream>
using namespace std;

class edge{
public:
	int s,d;
};

class subset{
public:
	int parent;
	int rank;
};

class graph{
public:
	int V,E;
	edge *alleds;
	graph(int x, int y){
		V = x;
		E = y;
		alleds = new edge[y];
	}
};

int find(subset *sub, int a){
	if(sub[a].parent != a) sub[a].parent = find(sub,sub[a].parent);
	return sub[a].parent; 
}

void Union(subset *sub, int a, int b){
	int x = find(sub,a);
	int y = find(sub,b);
	if(sub[x].rank > sub[y].rank) sub[y].parent = x;
	else if(sub[x].rank < sub[y].rank) sub[x].parent = y;
	else{
		sub[y].parent = x;
		sub[x].rank++;
	}
}

int iscycle(graph *g){
	subset *sub = new subset[g->V];
	int i,a,b;
	for(i=0;i<g->V;i++){
		sub[i].parent = i;
		sub[i].rank = 0;
	}
	for(i=0;i<g->E;i++){
		edge e = g->alleds[i];
		a = find(sub,e.s);
		b = find(sub,e.d);
		cout << a << " " << b << endl;
		if(a == b) return 1;
		Union(sub,a,b);
	}
	return 0;
}

int main(){
	int i,j,v,e;
	v=3;e=3;
	graph *g = new graph(3,3);
	g->alleds[0].s = 0;
    g->alleds[0].d = 1;
 
    g->alleds[1].s = 1;
    g->alleds[1].d = 2;
 
    g->alleds[2].s = 0;
    g->alleds[2].d = 2;
   cout << iscycle(g) << endl;
	return 1;
}