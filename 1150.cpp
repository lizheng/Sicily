#include <iostream>
#include <bitset>
#include <list>

using namespace std;

bitset<40500> onPlan;

struct MagicBoard{
	
	char c[8];
	string op;
	
	void init(char* cs){
		for (int i = 0; i < 8; i++) {
			c[i] = cs[i];
		}
		op = "";
	}
	
	void show(){
		cout << "M:\t";
		for (int i = 0; i < 8; i++) {
			cout << "\t" << c[i];
		}
		cout << endl;
		
		cout << "O:\t";
		cout << op << endl;
	}
	
	int toON(){
		
		int result;
		int oc[8];
		int item[7];
		
		for (int i = 0; i < 8; i++) {
			int count = 0;
			for (int j = i+1; j < 8; j++) {
				c[i] > c[j] ? count += 1 : count += 0;
			}
			oc[i] = count;
		}
		
		for (int i = 0; i < 7; i++) {
			item[i] = 1;
			
			for (int j = 2; j <= 7-i; j++) {
				item[i] *= j;
			}
			
			item[i] *= oc[i];
		}
		
		result = 0;
		for (int i = 0; i < 7; i++) {
			result += item[i];
		}
			
		return result;
	}
	
	void operate_A(struct MagicBoard* a){
		a->c[0] = c[4];
		a->c[1] = c[5];
		a->c[2] = c[6];
		a->c[3] = c[7];
		
		a->c[4] = c[0];
		a->c[5] = c[1];
		a->c[6] = c[2];
		a->c[7] = c[3];
		
		a->op = op + "A";
		
//		a->show();
//		cout << "ON:\t" << a->toON() << endl;
	};
	
	void operate_B(struct MagicBoard* a){
		a->c[0] = c[3];
		a->c[1] = c[0];
		a->c[2] = c[1];
		a->c[3] = c[2];
		
		a->c[4] = c[7];
		a->c[5] = c[4];
		a->c[6] = c[5];
		a->c[7] = c[6];
		
		a->op = op + "B";
		
//		a->show();
//		cout << "ON:\t" << a->toON() << endl;
	};
	
	void operate_C(struct MagicBoard* a){
		a->c[0] = c[0];
		a->c[3] = c[3];
		a->c[4] = c[4];
		a->c[7] = c[7];
		
		a->c[1] = c[5];
		a->c[2] = c[1];
		a->c[6] = c[2];
		a->c[5] = c[6];
		
		a->op = op + "C";
		
//		a->show();
//		cout << "ON:\t" << a->toON() << endl;
	};
};

int main(int argc, char *argv[]) {
	int N;
	char c[8];
	int ONgoal;
	struct MagicBoard MBgoal;
	c[0] = 1;
	c[1] = 2;
	c[2] = 3;
	c[3] = 4;
	c[4] = 8;
	c[5] = 7;
	c[6] = 6;
	c[7] = 5;
	MBgoal.init(c);
	ONgoal = MBgoal.toON();
	
	cin >> N;
	while (N != -1) {
		
		for (int i = 0; i < 8; i++) {
			cin >> c[i];
		}
		struct MagicBoard m;
		m.init(c);
//		m.show();
//		cout << "the ON: " << m.toON();
		
		onPlan.reset();
		
		list<MagicBoard> MBL;
		MBL.push_back(m);
		onPlan[m.toON()] = 1;
		
		// dfs
		struct MagicBoard MBcurrent;
cout << "DFS begin" << endl;
		bool isEnd = false;
		bool succeed = false;
		struct MagicBoard* MBresult;
		while ( !isEnd ) {
			// TODO if don't find in N step
			if ( MBL.size() == 0 ) {
				isEnd = true;
				succeed = false;
cout << "size of MBL is 0" << endl;
				break;
			}

			MBcurrent = MBL.front();
			MBL.pop_front();
			
			int ONcurrent = MBcurrent.toON();
			
cout << "MBcurrent:" << endl;
MBcurrent.show();
cout << "ON: " << MBcurrent.toON() << endl;
			
			if (ONcurrent == ONgoal) {
				isEnd = true;
				succeed = true;
				MBresult = &MBcurrent;
cout << "reach goal!" << endl;
				break;
			}
			
			if ( MBcurrent.op.length() >= N ) {
cout << "reach N step" << endl;
				continue;
			}

//--------------- A ---------------
			struct MagicBoard MBsonA;
			MBcurrent.operate_A(&MBsonA);
			
cout << "the son A is:" << endl;
MBsonA.show();
cout << "ON: " << MBsonA.toON() << endl;
			
			if ( onPlan[MBsonA.toON()] == 0 ) {
				
cout << "push back son A" << endl; 
				MBL.push_back(MBsonA);
cout << "size of MBL: " << MBL.size() << endl;

				onPlan[MBsonA.toON()] = 1;
			}

//--------------- B ---------------
			struct MagicBoard MBsonB;
			MBcurrent.operate_B(&MBsonB);
			
cout << "the son B is:" << endl;
MBsonB.show();
cout << "ON: " << MBsonB.toON() << endl;
			
			if ( onPlan[MBsonB.toON()] == 0 ) {
				
cout << "push back son B" << endl; 
				MBL.push_back(MBsonB);
cout << "size of MBL: " << MBL.size() << endl;

				onPlan[MBsonB.toON()] = 1;
			}
			
//--------------- C ---------------
			struct MagicBoard MBsonC;
			MBcurrent.operate_C(&MBsonC);
			
cout << "the son C is:" << endl;
MBsonA.show();
cout << "ON: " << MBsonC.toON() << endl;
			
			if ( onPlan[MBsonC.toON()] == 0 ) {
				
cout << "push back son C" << endl; 
				MBL.push_back(MBsonC);
cout << "size of MBL: " << MBL.size() << endl;

				onPlan[MBsonC.toON()] = 1;
			}

cout << "next" << endl;
//		check whether current is goal
//		if yes, end			

//		if visited
//			go to next current
//		else
//			set as checked
//			find current's sons
//			push them to MBL;

		}
		
		if (succeed) {
//			MBresult->show();
			cout << MBresult->op.length() << " " << MBresult->op << endl;
		}

		
		cin >> N;
	}
	return 0;
}