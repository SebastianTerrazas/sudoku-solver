//B A C K T R A C K I N G
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

bool reject(){
    //fila
    for(int rF=0; rF<9; rF++){
        if(i == n[rF][y]) return true;
    }
    //columna
    for(int rC=0; rC<9; rC++){
        if(i == n[x][rC]) return true;
    }
    //3 x 3
    int r3x = (x/3)*3;
    int r3y = (y/3)*3;
    for(int r3yC=0; r3yC<3; r3yC++){
        for(int r3xC=0; r3xC<3; r3xC++){
            if(i == n[r3x][r3y]) return true;
            r3x++;
        }
        r3y++;
    }
}

bool accept(){

}

void backtracking(int e[9][9]){
    if(e[x][y] == 1){
        if(reject()) return;
    //}
    //if(accept()) return;
    //procedimiento();

}

void procedimiento(int n[9][9], int e[9][9]){
    for(int i=1; i<10; i++){
        backtracking(e);
    }
}


int main(){
    ifstream Lista;
    ofstream myfile;
    int n[9][9];
    int e[9][9]; // 1's y 0's


    Lista.open("plantilla1.txt");
    if(!Lista.is_open()){
        cout << "\n Error: El archivo 'plantilla1.txt' no esta en la ubicaci"<<(char)162<<"n de este programa.\n"<< endl;
        exit(1);
    }
    for (int y=0;y<9;y++) { //  INICIALIZACION DE CONDICION A LA VARIABLE E
        for (int x=0;x<9;x++){
                e[x][y]=0;
        }
    }
    for (int y=0;y<9;y++) { //   ASIGNACION DE LISTA A LA VARIABLE N
        for (int x=0;x<9;x++){
            Lista>>n[x][y];
            if (n[x][y]!=0)
                e[x][y] = 1;
        }
    }

    procedimiento(n, e);
}



/* en el for no se puede usar "i" porque se iría modificando en todos y se terminaría ciclando (?) arreglo i[729]
implementar error en caso de que no haya respuesta o que haya múltiples respuestas (contador de veces que llega a una solución válida

*/
