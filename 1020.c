#include <stdio.h>
#include <assert.h>

int GetNumberDight(int number){
	int i = 0;
	while (number != 0)
	{
	  number /= 10;
	  i++;
	}
	return i;
};

int MyMod(char VeryLongInteger[], int Bn){
	int isEnd = 0;
	int CurrentDight = 0;
	int r = 0;
	
	while (isEnd == 0) {


		r *= 10;
		r += VeryLongInteger[CurrentDight]-'0';

		r %= Bn;
		CurrentDight++;
		if (CurrentDight>=400 || !(VeryLongInteger[CurrentDight]-'0'>=0 || VeryLongInteger[CurrentDight]-'0'>=9) ){
			isEnd = 1;
		}
	}
	return r;
	
};

int main(int argc, char *argv[]) {
	int TestTime;
	scanf("%d",&TestTime);
	
	int i;
	for (i=0; i<TestTime; i++) {
		int N;
		scanf("%d",&N);
		
		int B[N];
		int j;
		for (j=0; j<N; j++) {
			scanf("%d",&B[j]);
		}
		
		char VeryLongInteger[400];

		scanf("%s",VeryLongInteger);

		int representation[N];

		int N_index;
		for (N_index=0; N_index<N; N_index++) {
			representation[N_index] = MyMod(VeryLongInteger, B[N_index]);
		}
		
		printf("(");
		for (N_index=0; N_index<N-1; N_index++) {
			printf("%d,",representation[N_index]);
		}
		printf("%d",representation[N-1]);
		printf(")\n");
	}
}