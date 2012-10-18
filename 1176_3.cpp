#include <iostream>

using namespace std;

int cards[1001];
int FR[1001][1001];

int F( int l, int r ){

	if (FR[l][r] != 0) {
		return FR[l][r];
	}

	if ( l>=r ) {
		return 0;
	}
	
	int takeLeft=0;
	int ll = l;
	int lr = r;
	int takeRight=0;
	int rl = l;
	int rr = r;
	
	takeLeft += cards[ll];
	ll++;
	if (cards[ll]>=cards[lr]) {
		takeLeft -= cards[ll];
		ll++;
		takeLeft += F(ll,lr);
	} else {
		takeLeft -= cards[lr];
		lr--;
		takeLeft += F(ll,lr);
	}
	
	takeRight += cards[rr];
	rr--;
	if (cards[rl]>=cards[rr]) {
		takeRight -= cards[rl];
		rl++;
		takeRight += F(rl,rr);
	} else {
		takeRight -= cards[rr];
		rr--;
		takeRight += F(rl,rr);
	}
	
	FR[l][r] = takeLeft >= takeRight ? takeLeft : takeRight;
	
	return FR[l][r];
};

int main(int argc, char *argv[]) {
	int N=-1;
	cin >> N;
	int numCase = 1;
	
	while (N!=0) {
		
		for (int i = 0; i < 1001; i++) {
			cards[i] = 0; 
		}
		
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++) {
				FR[i][j] = 0;
			}
		}
		
		for (int i = 0; i < N; i++) {
			cin >> cards[i];
		}
		
		int result = F(0,N-1);
//		cout << result << endl;
		
		cout << "In game " << numCase << ", the greedy strategy might lose by as many as " << result << " points." << endl;
		
		cin >> N;
		numCase++;
	}
}