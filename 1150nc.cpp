#include <iostream>
#include <string>
#include <memory.h>
#include <queue>

#define F8 (8*7*6*5*4*3*2)
#define F7 (7*6*5*4*3*2)
#define F6 (6*5*4*3*2)
#define F5 (5*4*3*2)
#define F4 (4*3*2)
#define F3 (3*2)
#define F2 (2)

using namespace std;

bool onPlan[F8];


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
		int oc[7];
		int item[7];
		
		for (int i = 0; i < 7; i++) {
			oc[i] = 0;
			for (int j = i+1; j < 8; j++) {
				if (c[i] > c[j]) {
					oc[i]++;
				}
			}
		}
		
		item[0] = oc[0] * F7;
		item[1] = oc[1] * F6;
		item[2] = oc[2] * F5;
		item[3] = oc[3] * F4;
		item[4] = oc[4] * F3;
		item[5] = oc[5] * F2;
		item[6] = oc[6] * 1;
		
//		for (int i = 0; i < 7; i++) {
//			item[i] = 1;
//			
//			for (int j = 2; j <= 7-i; j++) {
//				item[i] *= j;
//			}
//			
//			item[i] *= oc[i];
//		}
		
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
	};
	
	void operate_C(struct MagicBoard* a){
		a->c[0] = c[0];
		a->c[1] = c[5];
		a->c[2] = c[1];
		a->c[3] = c[3];
		
		a->c[4] = c[4];
		a->c[5] = c[6];
		a->c[6] = c[2];
		a->c[7] = c[7];
		
		a->op = op + "C";
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
		int ONm = m.toON();
		
		memset(&onPlan, 0, sizeof(bool)*sizeof(onPlan));
		
		queue<MagicBoard> MBL;
		MBL.push(MBgoal);
		onPlan[MBgoal.toON()] = true;
//cout << m.toON() << endl;

		struct MagicBoard MBcurrent;
		bool isEnd = false;
		bool succeed = false;
		struct MagicBoard* MBresult;
		
		for (; !isEnd; ) {
			if ( MBL.size() == 0 ) {
				isEnd = true;
				succeed = false;
			} else {
				MBcurrent = MBL.front();
				MBL.pop();
				
				int ONcurrent = MBcurrent.toON();
				
				if (ONcurrent == ONm) {
					isEnd = true;
					succeed = true;
					MBresult = &MBcurrent;
				} else {
					 if ( MBcurrent.op.length() >= N ) {
					 		continue;
					}

					int ONtemp;
					//--------------- A ---------------
					struct MagicBoard MBsonA;
					MBcurrent.operate_A(&MBsonA);
					ONtemp = MBsonA.toON();
					
					if ( onPlan[ONtemp] == false ) {
						MBL.push(MBsonA);
						onPlan[ONtemp] = true;
					}

					//--------------- B ---------------
					struct MagicBoard MBsonB;
					MBcurrent.operate_B(&MBsonB);
					ONtemp = MBsonB.toON();

					if ( onPlan[ONtemp] == false ) {
						MBL.push(MBsonB);
						onPlan[ONtemp] = true;
					}
					
					//--------------- C ---------------
					struct MagicBoard MBsonC;
					MBcurrent.operate_C(&MBsonC);
					ONtemp = MBsonC.toON();
					
					if ( onPlan[ONtemp] == false ) {
						MBL.push(MBsonC);
						onPlan[ONtemp] = true;
					}
				}				
			}

			
			
		}
		
		if (succeed && MBresult->op.length() <= N) {
			if (MBresult->op.length() == 0) {
				cout << "0" << endl;
			} else {
				cout << MBresult->op.length() << " " << MBresult->op << endl;
			}
		} else {
			cout << "-1" << endl;
		}
		
//		string* ops = &MBresult->op;
//		*ops = "BCABCBCABCBCBB";
//		struct MagicBoard t;
//		if ( (*ops).length() > 0 ) {
//			for (int i = 0; i < (*ops).length(); i++) {
//				if ( (*ops)[i] == 'A' ) {
//					m.operate_A(&t);
//				}
//				
//				if ( (*ops)[i] == 'B' ) {
//					m.operate_B(&t);
//				}
//				
//				if ( (*ops)[i] == 'C' ) {
//					m.operate_C(&t);
//				}
//				
//				m = t;
//			}
//			cout << "t: " << endl;
//			t.show();
//		}
		
		cin >> N;
	}
	return 0;
}