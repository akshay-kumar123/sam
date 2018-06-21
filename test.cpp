#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
};

class queue{
public:
	Node *rear, *front;
	queue(){
		rear = front = NULL;
	}
	void enqueue(int x){
		Node *temp = new Node();

		temp->data = x;
		temp->next = NULL;
		if(front == NULL && rear == NULL){
			front = rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}

	int dequeue(){
		int ret;
		if(front == NULL) return 1;
		if(front == rear){
			ret = front->data;
			front = rear = NULL;
			return ret;
		}
		Node * temp = front;
		front = front->next;
		ret = temp->data;
		delete temp;
		return ret;
	}

	int get_front(){
		return front->data;
	}

	int length(){
		int count = 0, i = 0;
		if(front == NULL) return 0;
		if(front == rear) return 1;
		Node * temp = front;
		while(temp != NULL){
			count++;
			temp = temp->next;
		}
		return count;
	}

	bool isempty(){
		if(length() == 0) return true;
		else return false;
	}

	void print(){
		if(front == NULL) return;
		Node * temp = front;
		while(temp != NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

class stack{
public:
	queue *q1,*q2;
	stack(){
		q1 = new queue();
		q2 = new queue();
	}
	void push(int x){
		q1->enqueue(x);
	}
	int pop(){
		int len = q1->length(), i = 0, deq;
		for(i=0; i<len-1; i++){
			deq = q1->dequeue();
			q2->enqueue(deq);
		}
		deq = q1->dequeue();
		queue *temp = q1;
		q1 = q2;
		q2 = temp;
		return deq;
	}
	int length(){
		return q1->length();
	}
	void print(){
		q1->print();
	}
};

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *a, int l, int r)
{
   int i;
   if (l == r)
   {
   	for (i = 0; i < 5; ++i)
     {
    	cout << a[i] << " ";
     }
     cout << endl;
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}

int index_change(int x, int y, int m){
	return x*m + y;
}


int BFS(int **matrix, int n, int m, int x, int y, int ** visited){
	if(matrix[0][0] == 0) return -1;
	int len,i,j,poper,conx,cony,count=0;
	queue *q = new queue();
	q->enqueue(index_change(0,0,n));
	visited[0][0] = 1;
	while(!q->isempty()){
		len = q->length();
		count++;
		for(i=0;i<len;i++){
			poper = q->dequeue();
			//cout << poper << " ";
			conx = poper/m;
			cony = poper%m;
			if(conx == x and cony == y) return count-1;
			visited[conx][cony] = 1;
			if(cony != m-1){
				if(visited[conx][cony+1] == 0 and matrix[conx][cony+1] == 1) q->enqueue(index_change(conx, cony+1, m));
			}
			if(cony != 0){
				if(visited[conx][cony-1] == 0 and matrix[conx][cony-1] == 1) q->enqueue(index_change(conx, cony-1, m));
			}
			if(conx != 0){
				if(visited[conx-1][cony] == 0 and matrix[conx-1][cony] == 1) q->enqueue(index_change(conx-1, cony, m));
			}
			if(conx != n-1){
				if(visited[conx+1][cony] == 0 and matrix[conx+1][cony] == 1) q->enqueue(index_change(conx+1, cony, m));
			}

		}
	}
	return -1;
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
	cin >> x >> y;
		int shortdis = BFS(matrix,n,m,x,y,visited);
		cout << shortdis << endl;
	}
    return 0;
}