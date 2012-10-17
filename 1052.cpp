#include <iostream>
#include <stdio.h>

using namespace std;

bool constantArray(int* a, int size){
	int i;
	for (i=1; i<size; i++) {
		if( !(a[i] == a[i-1]) ){
			return false;
		}
	}
	return true;
};

int main(int argc, char *argv[]) {
	int num_student=-1;
	scanf("%d",&num_student);
	
	while (num_student != 0) {
		
		int cake[num_student];
		int index;
		for (index=0; index<num_student; index++) {
			scanf("%d",&cake[index]);
		}
		int round = 0;
		int new_cake[num_student];
		while ( !constantArray(cake, num_student) ){
			
			int index_s;
			for (index_s=0; index_s<num_student; index_s++) {
				new_cake[ (index_s+1) % num_student ] = 
					cake[ index_s % num_student ]/2 + 
					cake[ (index_s+1) % num_student ]/2;
			}
			
			for (index_s=0; index_s<num_student; index_s++) {
				cake[index_s] = new_cake[index_s]%2 == 0 ? new_cake[index_s] : new_cake[index_s]+1 ;
			}			
			round++;
			
		}
		
		printf("%d %d\n", round, cake[0]);
		
		scanf("%d",&num_student);
	}
	
}