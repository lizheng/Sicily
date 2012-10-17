#include <iostream>
#include <list>
#include <set>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct classcomp {
	bool operator()(double* first, double* second){
//		cout << *(first+2) << "\t" << *(second+2) << endl;
		
		double ppq = *(first+2) - *(second+2);
	
//	if ( !(*(first+2) - *(second+2) <= 0.000001 || *(second+2) - *(first+2) <= 0.000001) ) {
//		cout << "if" << endl;
//		return (*(first+2) < *(second+2) ? false : true);
//	} else {
//		cout << "else" << endl;
//		return (*(first+2) < *(second+2) ? false : true);
//	}
	
	if ( 
	!( 
	(ppq <= 0.00001 && ppq >= 0) 
	|| 
	(-ppq <= 0.00001 && -ppq >= 0) ) 
	){
		return (*(first+2) < *(second+2) ? false : true);
	} else if ( !( (int)*(first+3) == (int)*(second+3)) ) {
		return (*(first+3) < *(second+3) ? false : true);
	} else {
		return (*(first+1) < *(second+1) ? true : false);
	}
	
//		if ( !(*(first+2) - *(second+2) <= 0.00001 || *(second+2) - *(first+2) <= 0.00001) ) {
//			return (*(first+2) < *(second+2) ? false : true);
//		} else if ( !(*(first+3) - *(second+3) <= 0.0000001 || *(second+3) - *(first+3) <= 0.0000001) ) {
//			return (*(first+3) < *(second+3) ? false : true);
//		} else if ( !(*(first+1) - *(second+1) <= 0.0000001 || *(second+1) - *(first+1) <= 0.0000001) ) {
//			return (*(first+1) < *(second+1) ? true : false);
//		}
	}
};



int main(int argc, char *argv[]) {
	
	int NumCase=-1;
	cin >> NumCase;
		
	int CaseIndex;
	for (CaseIndex=0; CaseIndex<NumCase; CaseIndex++) {

		int NumQ=-1;
		int best;
		int min;
		cin >> NumQ >> best >> min;
		
		int q[301];
		int InputIndex;
		for (InputIndex=0; InputIndex<NumQ; InputIndex++) {
			cin >> q[InputIndex];
		}
		
		//threshold
//		设置阈值
//		
//		遍历可能的情况
//			如果高于阈值
//				入队
//				更新阈值
//		list<int*> working;
//		int threhold[5] = {0,0,0,0,0};

		set<double*, classcomp> working;
		for (int i = 0; i < NumQ-min+1; i++) {
			for (int j = i+min-1; j < NumQ; j++) {
//					cout << "i = " << i << " j = " << j << endl;
					int sum=0;
					for (int k=i; k<=j; k++) {
						sum += q[k];
					}
					double* a;
					a = (double*)malloc(4*sizeof(double));
					*(a+0) = i;
					*(a+1) = j;
					*(a+2) = (double)sum / (double)(j-i+1);
					*(a+3) = j-i+1;
					working.insert(a);
			}
		}
		
//		cout << working.size() << endl;

		cout << "Result for run " << CaseIndex+1 << ":" << endl;
		for (int i = 0; i < best && working.size()!=0; i++) {
			cout << (int)(*working.begin())[0]+1 << "-" << (int)(*working.begin())[1]+1 << endl;
			working.erase(working.begin());
		}
		

		
	}
}