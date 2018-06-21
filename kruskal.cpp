#include <iostream>
using namespace std;

class edge
{
public:
	int s,d,w;
};

class graph
{
public:
	int V,E;
	edge *alleds;
	graph(int x, int y){
		V=x;
		E=y;
		alleds = new edge[y];
	}
};

class subset
{
public:
	int parent,rank;
};

void swap(edge &x, edge &y){
	edge t = x;
	x = y;
	y = t;
}

void sort(edge *alleds,int e){
	int i,j,maxi,index;
	for(i=0;i<e-1;i++){
		maxi = alleds[i].w;
		index = i;
		for(j=i;j<e;j++){
			if(maxi > alleds[j].w){
				maxi = alleds[j].w;
				index = j;
				//cout << alleds[j].s << " " << alleds[j].d << " " << alleds[j].w << endl;
			}
			
		}
		swap(alleds[index], alleds[i]);
	}
	//for(i=0;i<e;i++) cout << alleds[i].w << " ";
}

int find(subset *sub,int a){
	if(sub[a].parent != a) sub[a].parent = find(sub,sub[a].parent);
	return sub[a].parent;
}

void Union(subset *sub, int a, int b){
	a = find(sub,a);
	b = find(sub,b);
	if(sub[a].rank > sub[b].rank) sub[b].parent = a;
	else if(sub[a].rank < sub[b].rank) sub[a].parent = b;
	else {
		sub[a].parent = b;
		sub[b].rank++;
	}
}

int MST(subset *sub, graph *g){
	int i,j,s1,d1,w1,s,d,w,sum=0;
	for(i=0;i<g->E;i++){
		edge ed = g->alleds[i];
		s1 = ed.s;
		d1 = ed.d;
		w1 = ed.w;
		s = find(sub,s1);
		d = find(sub,d1);
		if(s == d) continue;
		sum += w1;
		Union(sub, s, d);
		cout << s1 << " " << d1 << endl;
	}
	return sum;
}

int main(){
	int i,j,v,e,a,b,w;
	cin >> v >> e;
	graph *g = new graph(v,e);
	subset *sub = new subset[v];
	for(i=0;i<v;i++) {
		sub[i].parent = i;
		sub[i].rank = 0;
	}
	for(i=0;i<e;i++) {
		cin >> a >> b >> w;
		g->alleds[i].s = a;
		g->alleds[i].d = b;
		g->alleds[i].w = w;
	}
	sort(g->alleds,e);
	cout << MST(sub,g) << endl;
	//for(i=0;i<e;i++) cout << g->alleds[i].s << " " << g->alleds[i].d << " " << g->alleds[i].w << endl;
	return 1;
}