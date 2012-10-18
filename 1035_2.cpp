#include <iostream>
#include <stdio.h>
#include <list>
#include <string.h>

using namespace std;

void ComplementaryString(const char* a, char* b){
	int i;
	char current = 'z';
	for (i=0; i<101; i++) {
		if( a[i] == 'A' ){
			b[i] = 'T';
		}
		if( a[i] == 'T' ){
			b[i] = 'A';
		}
		if( a[i] == 'C' ){
			b[i] = 'G';
		}
		if( a[i] == 'G' ){
			b[i] = 'C';
		}
		if( a[i] == '\0' ){
			b[i] = '\0';
		}
	}
};

int main(int argc, char *argv[]) {
	
	int TestCase=-1;
	scanf("%d",&TestCase);
	
	int Case_index;
	for (Case_index=0; Case_index<TestCase; Case_index++) {
		
		int NumDNA=-1;
		scanf("%d",&NumDNA);
		
		char currentDNA[NumDNA][101];
		
		list<char*> DNAlist;
		list<char*>::iterator it;
	
		int IndexDNA;
		for (IndexDNA=0; IndexDNA<NumDNA; IndexDNA++) {
			scanf("%s", currentDNA[IndexDNA]);
			
			char b[101];
			ComplementaryString( currentDNA[IndexDNA], b );
			
//			printf("a = %s\t", currentDNA[IndexDNA]);
//			printf("b = %s\n", b);
			bool isFind = false;
			for (it = DNAlist.begin(); it != DNAlist.end(); it++) {
				if (strcmp( (*it), b )==0 ) {
					DNAlist.erase(it);
					isFind = true;
				}
			}
			
			if ( !isFind ) {
				DNAlist.push_front(currentDNA[IndexDNA]);
			}
		}
//		printf("dnsset size = %d\n",DNAlist.size());
		printf("%d\n", (NumDNA-(int)DNAlist.size()) / 2 );
		

	}
	printf("\n");
}