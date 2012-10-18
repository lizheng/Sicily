#include <iostream>
#include <stdio.h>
#include <set>
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
			break;
		}
	}
};

struct lt_string{
	bool operator()(const char* a, const char* b) const{
		return strcmp(a,b) < 0;
	}
};

int main(int argc, char *argv[]) {
	
	int TestCase=-1;
	scanf("%d",&TestCase);
	
	int Case_index;
	for (Case_index=0; Case_index<TestCase; Case_index++) {
		int count=0;
		
		
		int NumDNA=-1;
		scanf("%d",&NumDNA);
		
		char currentDNA[NumDNA][101];
		
		set<char*, lt_string> DNAset;
		set<char*, lt_string>::iterator it;
	
		int IndexDNA;
		for (IndexDNA=0; IndexDNA<NumDNA; IndexDNA++) {
			scanf("%s", currentDNA[IndexDNA]);
			
			char b[101];
			ComplementaryString( currentDNA[IndexDNA], b );
			
//			printf("a = %s\t", currentDNA[IndexDNA]);
//			printf("b = %s\n", b);
			
			it = DNAset.find( b );
			if ( it==DNAset.end() ) {
				DNAset.insert(currentDNA[IndexDNA]);
			} else {
				DNAset.erase(it);
				count++;
			}
		}
//		printf("dnsset size = %d\n",DNAset.size());
//		printf("%d\n", (int)(NumDNA-(int)DNAset.size()) / 2 ); // ?
		printf("%d\n", count );		

	}

}