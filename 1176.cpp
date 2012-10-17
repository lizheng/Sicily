#include <iostream>
#include <deque>
#include <assert.h>

using namespace std;

inline int F( deque<int> remainder ){
	assert( remainder.size()%2 == 0 );
	
	if ( remainder.size() == 0 ) {
		return 0;
	}
	
	int takeLeft;
	int takeRight;
	
	deque<int> temp;
	
	temp = remainder;
	takeLeft = temp[0];
	temp.pop_front();
	
	if ( temp[0] >= temp[temp.size()-1] ) {
		takeLeft -= temp[0];
		temp.pop_front();
	} else {
		takeLeft -= temp[temp.size()-1];
		temp.pop_back();
	}
	takeLeft += F(temp);
	
	temp = remainder;
	takeRight = temp[temp.size()-1];
	temp.pop_back();
	if ( temp[0] >= temp[temp.size()-1] ) {
		takeRight -= temp[0];
		temp.pop_front();
	} else {
		takeRight -= temp[temp.size()-1];
		temp.pop_back();
	}
	takeRight += F(temp);
	
	return takeLeft > takeRight ? takeLeft : takeRight;
	
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