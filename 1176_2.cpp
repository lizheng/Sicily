#include <iostream>
#include <deque>
#include <assert.h>
//使用数组(共用)和左右下标来代替list
//要考虑重合的情况 即分数差和左右下标都相同 使用set？
using namespace std;


int F( deque<int> remainder ){
	assert( remainder.size()%2 == 0 );
	
	pair< int, deque<int> > state;
	pair< int, deque<int> > Left;
	pair< int, deque<int> > Right;
	state = make_pair(0, remainder);
	
	deque< pair< int, deque<int> > > working;
	
	working.push_back(state);
	
	while (working[0].second.size() != 0) {
		state = working[0];
		working.pop_front();
		
//		cout << state.second.size() << endl;
		
		Left = state;
		Left.first += Left.second[0];
		Left.second.pop_front();
		
		if ( Left.second[0] >= Left.second[Left.second.size()-1] ) {
			Left.first -= Left.second[0];
			Left.second.pop_front();
		} else {
			Left.first -= Left.second[Left.second.size()-1];
			Left.second.pop_back();
		}
		working.push_back(Left);
		
		Right = state;
		Right.first += Right.second[Right.second.size()-1];
		Right.second.pop_back();
		
		if ( Right.second[0] >= Right.second[Right.second.size()-1] ) {
			Right.first -= Right.second[0];
			Right.second.pop_front();
		} else {
			Right.first -= Right.second[Right.second.size()-1];
			Right.second.pop_back();
		}
		working.push_back(Right);
	}
	
	int result = -1000;
	for (int i = 0; i < working.size(); i++) {
		if (working[i].first > result) {
			result = working[i].first;
		}
	}
	
	return result;
	
	
};

int main(int argc, char *argv[]) {
	int N=-1;
	cin >> N;
	
	
	while (N!=0) {
		
		deque<int> cards;
		int c;
		
		for (int i = 0; i < N; i++) {
			cin >> c;
			cards.push_back(c);
		}
		
		int result = F(cards);
		cout << result << endl;
		
		cin >> N;
	}
}