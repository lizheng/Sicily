// Accepted
// !!!! 为什么跑一个TestCase的时间比跑2个要多？
#include <iostream>
#include <list>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

struct toNode{
	int end;
	int d;
	
	toNode(int e, int distance){
		end = e;
		d = distance;
	}
};

vector<struct toNode> path[10001];
int used[10001];


int N, K;
int X, Y, D;
int maxDistance = -1;

int dfs(int K, int distance){
	
//	cout << "dfs " << K << endl;

	if (distance > maxDistance){
//		cout << distance << " > " << maxDistance << endl;
		maxDistance = distance;		//!!!!
	}
	
	for (int i = 0; i < path[K].size(); i++) {

		int to = path[K].at(i).end;
		int dis = path[K].at(i).d;

		if ( used[to] == 0 ){
			used[to] = 1;//!!!!
			dfs( to, dis + distance );
			used[to] = 0;//!!!!
		}
	}
};

int main(int argc, char *argv[]) {
	
	while (cin >> N) {
		cin >> K;

		memset(path, 0, sizeof(path));
		memset(used, 0, sizeof(int)*10001);
		
		for (int i = 0; i < N-1; i++) {
			cin >> X >> Y >> D;
			
			path[X].push_back( toNode(Y,D) );
			path[Y].push_back( toNode(X,D) );
		}
		
		used[K] = 1;						//!!!!
		dfs(K, 0);
		cout << maxDistance << endl;
		
		maxDistance = -1;
	}
	return 0;
}