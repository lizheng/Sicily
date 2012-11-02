#include <iostream>
#include <assert.h>
#include <list>

#define MAX_PRIME 4294967296

//#define MAX_PRIME 4611686018427387904

using namespace std;

list<unsigned long long> primeFactors;

list<unsigned long long> prime;

void findPrime(){
	
//cout << "haha" << endl;
	unsigned long long c;
	c = 3;
	
	while (c <= MAX_PRIME){
		bool iPrime = true;
//		cout << c << endl;
		for (list<unsigned long long>::iterator it = prime.begin(); it != prime.end(); ++it){
			if ( c % (*it) == 0 ){
				iPrime = false;
				break;
			}
		}

		if (iPrime){
			prime.push_back(c);
		}

		c += 2;
	}
};


bool primeFactorization(unsigned long long n){
	bool result = false;
	unsigned long long f;
	
	f = 3;
	while (f <= n/3 +1) {
		
		if ( n % f == 0 ) {
			n = n/f;
			primeFactors.push_back(f);
			result = true;
		} else {
			f += 2;
		}
		
	}
	
	return result;
};

bool isPrime(unsigned long long f){
	return 0;
};

int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	assert(k>=2);
	
	findPrime();
	return 0;
	
	int ii;
	for (ii = 2; ii < k; ii++) {

		if ( !isPrime(ii) ){
			continue;
		}

		unsigned long long a = 1;
		for (int j = 0; j < ii; j++) {
			a *= 2;
		}
		a = a-1;
		
//		cout << a << endl;
		
		primeFactors.clear();
		if (primeFactorization(a)) {
			bool first = true;
			list<unsigned long long>::iterator it;
			for (it = primeFactors.begin(); it != primeFactors.end(); it++) {
				if (first) {
					first = false;
				} else {
					cout << " * ";
				}
				cout << (*it);
			}
			
			cout << " = " << a << " = ( 2 ^ " << ii <<  ") - 1" << endl;
		}
	}
	
	
	
	
	return 0;
}