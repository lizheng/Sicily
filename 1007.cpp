#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {

    int w=-1;
    cin >> w;

    while ( w!=0 ){
        string s;
        cin >> s;

        int h = s.length()/w;

        int r=0;
        int c=0;
        int d = +1;

        char table[h][w];

        for ( int i = 0; i<s.length(); ++i ){
            
            table[r][c] = s[i];

            if ( c+d >= 0 && c+d < w ){
                c += d;
            } else {
                r++;
                d = -d;
            }
        }

        for (int i = 0; i < w; ++i)
        {
            for (int j = 0; j < h; ++j)
            {
                    cout << table[j][i];
            }
//          cout << endl;
        }
        cout << endl;
        
        cin >> w;
    }
    
}