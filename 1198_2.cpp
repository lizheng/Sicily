#include <iostream>
#include <stdio.h>
#include <string.h>
#include <list>
#include <assert.h>

// do more

using namespace std;

string LexicographicallySmallest( list<string> remainder ){
	string result="****";

	assert(remainder.size()!=0);
	
	if (remainder.size() == 1) {
		return *remainder.begin();
	}


	list<string> LSstrings;
	string temp;
	
	list<string>::iterator it;
	for (it=remainder.begin(); it!=remainder.end(); it++) {
		list<string> r;
		
		r = remainder;
		
//		r.remove(*it);
		
		list<string>::iterator it2;
		for (it2=r.begin(); it2!=r.end(); it2++){
			if ( (*it2) == (*it) ){
//				printf("hahaff\n");
					r.erase(it2);
					break;
			}
		}
		
//		removeOnes(r,(*it));
		// !!!!!!
		string temp = "";
		temp += (*it);
		temp += LexicographicallySmallest(r);
		LSstrings.push_back( temp );
		
//		r.erase(it);
		
	}
	
	LSstrings.sort();
	result = *LSstrings.begin();
	
	return result;
};

int main(int argc, char *argv[]) {
	
	int NumCase=-1;
	scanf("%d",&NumCase);
		
	int CaseIndex;
	for (CaseIndex=0; CaseIndex<NumCase; CaseIndex++) {

		int NumInput=-1;
		scanf("%d",&NumInput);
		
		string temp;
		list<string> s;
		
		int InputIndex;
		for (InputIndex=0; InputIndex<NumInput; InputIndex++) {
			cin >> temp;
			s.push_back(temp);
		}
		
//		cout << "list:" << endl;
//		list<string>::iterator it;
//		for (it=s.begin(); it!=s.end(); it++) {
//			cout << (*it) << "\t";
//		}
//		cout << endl;
		
		
		string result = "----";
		result = LexicographicallySmallest(s);
		cout << result << endl;

	}
}