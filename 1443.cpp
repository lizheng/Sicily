// Accepted

#include <iostream>
#include <list>

using namespace std;

int isMax(list<int> jobs, int temp){
	list<int>::iterator it;
	bool result = true;
	
	for ( it=jobs.begin() ; it != jobs.end(); it++ ){
		if ( temp < (*it) ) {
			result = false;
			break;
		}
	}
	
	return result;
}

int main(int argc, char *argv[]) {
	int numCase;
	cin >> numCase;
	
	for (int indexCase = 0; indexCase < numCase; indexCase++) {
		int size;
		int position;
		list<int> jobs;
		int temp;
		int time = 0;
		
		cin >> size >> position;
		for (int i = 0; i < size; i++) {
			cin >> temp;
			jobs.push_back(temp);
		}
		
		char isEnd = 'N';
		while ( isEnd != 'Y' ) {
			temp = jobs.front();
			jobs.pop_front();
			position--;
			
			if ( isMax(jobs, temp) ) {
				time++;
				if (position == -1) {
					isEnd = 'Y';
				}
			} else {
				jobs.push_back(temp);
				if (position == -1) {
					position = jobs.size() - 1;
				}
			}
		}
		
		cout << time << endl;
	}
	
}