#include <iostream>
#include <windows.h>
using namespace std;

void Change(int color){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main(){
    system("color F0");
    /*int gris = 248;

    cout << "Hello world" << endl;

    Change(gris);

    cout << "Hello world x2" << endl;*/

    for(int i=0; i<=255; i++){
        Change(i);
        cout << "\n#" << i;
    }
    return 0;
}
