#include <iostream>
#include <stdio.h>
#include <string.h>
#include <list>

//	新建队列
//	指针指向队头
//	
//	队头展开成各种情况，队头出队
//	选取可能的情况
//	与队中剩余情况比较，剪枝，入队
//	直到队中元素不能再展开
//	
//	此时队中最优就是所求

using namespace std;

string LexicographicallySmallest( string* s, int size ){
	string result="****";
	pair<string, long> * ss;
	
	list< pair<string, long> > worklist;
	list< pair<string, long> > waiting;
	
	ss = make_pair("",0);
	waiting = sonString(ss);
	
	
	
	return result;
};

int main(int argc, char *argv[]) {
	
	int NumCase=-1;
	scanf("%d",&NumCase);
		
	int CaseIndex;
	for (CaseIndex=0; CaseIndex<NumCase; CaseIndex++) {

		int NumInput=-1;
		scanf("%d",&NumInput);
		
		string s[NumInput];
//		char** s_ptr = s;
		
		int InputIndex;
		for (InputIndex=0; InputIndex<NumInput; InputIndex++) {
			cin >> s[InputIndex];
//			cout << s[InputIndex] << endl;
//			scanf("%s",s[InputIndex]);
//			printf("%s",s[InputIndex]);
		}
		
		string result = "----";
		result = LexicographicallySmallest(s, NumInput);
		cout << result << endl;
//		printf("%s", result);
	}
}