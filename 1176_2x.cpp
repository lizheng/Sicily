#include <iostream>
#include <deque>
#include <assert.h>
//使用数组(共用)和左右下标来代替list
//要考虑重合的情况 即分数差和左右下标都相同 使用set？

//In function 'int F(int*, int, int)':
//45: error: expected primary-expression at end of input
//45: error: expected ';' at end of input
//45: error: expected '}' at end of input
//45: error: expected '}' at end of input
//23: warning: unused variable 'Right'
//45: error: expected '}' at end of input
//45: warning: no return statement in function returning non-void


using namespace std;

int cards[1001];

struct t{
	int s;
	int l;
	int r;
};

int F( int* remainder, int l, int r ){
//	assert( remainder.size()%2 == 0 );
	
//	cout << "l = " << l << "r = " << r << endl;
	
	struct t state;
	struct t Left;
	struct t Right;
	state.s=0;
	state.l=l;
	state.r=r;
	
	deque< struct t > working;
	
	working.push_back(state);
	
	while ( working[0].l < working[0].r ) {
		state = working[0];
		working.pop_front();
		

//		cout << state.second.size() << endl;
		
		Left = state;
		Left.s += cards[Left.l];
		Left.l++;
		
		if ( cards[Left.l] >= cards[Left.r] ) {
//			cout << "ll" << endl;
			Left.s -= cards[Left.l];
			Left.l++;
		} else {
//			cout << "lr" << endl;
			Left.s -= cards[Left.r];
			Left.r--;	
		}
		working.push_back(Left);
		
		Right = state;
		Right.s += cards[Right.r];
		Right.r--;
		
		if ( cards[Right.l] >= cards[Right.r] ) {
//			cout << "rl" << endl;
			Right.s -= cards[Right.l];
			Right.l++;
		} else {
//			cout << "rr" << endl;
			Right.s -= cards[Right.r];
			Right.r--;	
		}
		working.push_back(Right);
		
//		free(&state);
	}
	
	int result = -1000;
	for (int i = 0; i < working.size(); i++) {
		if (working[i].s > result) {
			result = working[i].s;
		}
	}
	
	return result;
	
	
};

int main(int argc, char *argv[]) {
	int N=-1;
	cin >> N;
	
	
	while (N!=0) {
		
		for (int i = 0; i < N; i++) {
			cin >> cards[i];
		}
		
		int result = F(cards, 0, N-1);
		cout << result << endl;
		
		cin >> N;
	}
}