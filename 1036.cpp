#include <iostream>
#include <list>

using namespace std;

struct s{
	char c;
	int index;
};

struct cs{
	string cipher;
	int index;
};

bool campareKeys(struct s s1, struct s s2){
	return s1.c < s2.c;
};

bool campareCipher(struct cs cs1, struct cs cs2){
	return cs1.index < cs2.index;
};

int main(int argc, char *argv[]) {
	string key;
	string cipher;
	
	
	while ( true ) {
		cin >> key;
		if (key != "THEEND") {
			cin >> cipher;
			
			int lengthPerGroup = cipher.size() / key.size();
			struct s* a;
			list<struct s> keyList;
			char table[lengthPerGroup][key.size()];
			
			for (int i = 0; i < key.size(); i++) {
				a = &s();
				(*a).c = key[i];
				(*a).index = i;
				keyList.push_back(*a);
			}
			
			keyList.sort(campareKeys);
			
//			list<struct s>::iterator it;
//			for ( it=keyList.begin() ; it != keyList.end(); it++ ){
//				cout << (*it).c << "\t" << (*it).index << endl;
//			}
			
			list<struct s>::iterator it;
			int indexCipher=0;
			for ( it=keyList.begin() ; it != keyList.end(); it++ ){
				
				for (int i = 0; i < lengthPerGroup; i++) {
					table[ i ][ (*it).index ] = cipher[ indexCipher + i ];
				}
				
				indexCipher += lengthPerGroup;
			}
			
			for (int r = 0; r < lengthPerGroup; r++) {
				for (int c = 0; c < key.size(); c++) {
					cout << table[r][c];
				}
			}
			cout << endl;
			
//			for (int r = 0; r < lengthPerGroup; r++) {
//				for (int c = 0; c < key.size(); c++) {
//					cout << "\t" << table[r][c];
//				}
//				cout << endl;
//			}
			
		} else {
			return 0;
		}
	}
}