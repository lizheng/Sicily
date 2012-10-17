#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char *argv[]) {
	float pi = 3.1415927;
	
	int i = 1;
	
	float diameter;
	int revolutions;
	float time;
	cin >> diameter >> revolutions >> time;
	while (revolutions != 0) {
		float distance = diameter*revolutions*pi;
		distance /= 12;
		distance /= 5280;
		
		float MPH = distance*3600;
		MPH /= time;
		
		cout << "Trip #" << i << ": " << fixed << setprecision(2) << distance << " " << fixed << setprecision(2) << MPH << endl;
		i++;
		
		cin >> diameter >> revolutions >> time;
	}
	
//26*3.1415927*1000/12/5280/(5/60/60)
}