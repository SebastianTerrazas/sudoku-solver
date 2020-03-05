#include <iostream>
using namespace std;

int main(){
    system("color F0");

    for(int i=0; i<9; i++){
        cout << i << " = " << (i/3)*3 << endl;
        cout << i << " = " << (i/3)*3+1 << endl;
        cout << i << " = " << (i/3)*3+2 << endl;
    }
}
