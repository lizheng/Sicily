#include <stdio.h>
#include <stack>

using namespace std;

int main() {
	int N=-1;
	scanf("%d",&N);
	
	while ( N!=0 ) {
		int index;
		int a,b;
		int couples[200001];
		for (index=0; index<N; index++) {
			scanf("%d",&a);
			scanf("%d",&b);
			couples[a] = b;
			couples[b] = a;
		}
		
		
		stack<int> s;
		int i;
		for (i=1; i<=2*N; i++) {
			if(s.empty() || s.top() != couples[i]){
				s.push(i);
			}
			else {
				s.pop();
			}
		}
		
		if (s.empty()) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
		
		scanf("%d",&N);
	}

}