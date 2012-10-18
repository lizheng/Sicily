#include <iostream>
#include <stdio.h>
#include <set>
#include <string.h>

using namespace std;

struct lt_post_pair{
	bool operator()(const pair<unsigned int, char*> &a, const pair<unsigned int, char*> &b) const{
		return a.first<b.first;
	};
};

struct lt_IDs_pair{
	bool operator()(const pair<char*, char*> &a, const pair<char*, char*> &b) const{
			return strcmp(a.first, b.first) < 0;
		};
};

int main(int argc, char *argv[]) {
//	unsigned int a, b, c, d;
//	scanf("%u.%u.%u.%u",&a,&b,&c,&d);
//	unsigned int IP = (a<<24) + (b<<16) + (c<<8) + d;
//	printf("%u.%u.%u.%u\n",a<<24,b<<16,c<<8,d);
//	printf("%u",IP);
	
	int N=-1;
	scanf("%d",&N);
	
	while (N!=0) {
		int post_index;
		
		set< pair<unsigned int, char*>, lt_post_pair > main_post;
		set< pair<unsigned int, char*>, lt_post_pair > MJ_post;
		
		
		for (post_index=0; post_index<N; post_index++) {
			char BBS_ID[30][20];
			unsigned int a, b, c, d;
			unsigned int IP_Address;
			pair<unsigned int, char*> post_pair;
			
			scanf("%s",BBS_ID[post_index]);
			
			scanf("%u.%u.%u.%u",&a,&b,&c,&d);
			IP_Address = (a<<24) + (b<<16) + (c<<8) + d;
			
			post_pair = make_pair(IP_Address,BBS_ID[post_index]);
			
			if( main_post.find(post_pair)==main_post.end() ){
				main_post.insert(post_pair);
			} else {
				MJ_post.insert(post_pair);
			}
			
		}
//		assert( main_post.size() == MJ_post.size() );
		set< pair<unsigned int, char*>, lt_post_pair >::iterator main_it;
		set< pair<unsigned int, char*>, lt_post_pair >::iterator MJ_it;
		pair<char*, char*> IDpair;
		set< pair<char*, char*>, lt_IDs_pair > mainAndMJ;
		
		for (		main_it=main_post.begin(), MJ_it=MJ_post.begin() ;
					main_it != main_post.end(); 
					main_it++, MJ_it++ )
		{
			IDpair = make_pair( (*main_it).second, (*MJ_it).second );
			mainAndMJ.insert(IDpair);
//			printf("%s is the MaJia of %s\n",(*MJ_it).second,(*main_it).second);
		}
		
		set< pair<char*, char*>, lt_IDs_pair >::iterator IDpair_it;
		for (IDpair_it = mainAndMJ.begin(); IDpair_it != mainAndMJ.end(); ) {
			printf("%s is the MaJia of %s\n", (*IDpair_it).second, (*IDpair_it).first);
			IDpair_it++;
//			if(IDpair_it != mainAndMJ.end()){
//				printf("\n");
//			}
		}
		printf("\n");
		
		scanf("%d",&N);
//		if(N!=0){
//			printf("\n");
//		}
	}
};