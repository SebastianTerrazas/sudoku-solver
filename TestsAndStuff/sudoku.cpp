#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

using namespace std;

void Ocultarcursor () {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 100;
    cci.bVisible =  FALSE;

    SetConsoleCursorInfo(hCon,&cci);
}

void gotoxy (int cx, int cy) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD Anita;
    Anita.X=cx;
    Anita.Y=cy;
    SetConsoleCursorPosition(hCon, Anita);
}

void renglon (int request,int nively) {
    int temp=0;

    if (request==1){ //             IMPRIME EL TOP DEL TABLERO
        cout <<"        "<<(char)218;
        for (int nylon=1;nylon<28;nylon++){
            cout<<(char)196; temp++;
            if ((temp%3)==0&&nylon!=27){
                cout<<(char)194;
            }
        }
        cout<<(char)191<<endl;
    }

    if (request==2){ //               IMPRIME ELINTERMEDIO DEL TABLERO
        cout <<"        "<<(char)195;
        for (int nylon=1;nylon<28;nylon++){
            cout<<(char)196; temp++;
            if ((temp%3)==0&&nylon!=27){
                cout<<(char)197;
            }
        }
        cout<<(char)180;
        if (nively==1) {//              TODOS LOS "NIVELY" SON PARA ELMENU A LA DERECHA nivel del renglon
            cout << "   "<<(char)201;
            for (int iterate=0;iterate<20;iterate++)
                cout << (char)205;
            cout <<(char)187;
        }
        if (nively==2) {
            cout << "   "<<(char)200;
            for (int iterate=0;iterate<20;iterate++)
                cout << (char)205;
            cout <<(char)188;
        }
        if (nively==3) {
                cout << "     (C) CARGAR la partida.   (L) COMPROBAR tablero.";
        }
        if (nively==4) {
            cout << "   "<<(char)201;
            for (int iterate=0;iterate<63;iterate++)
                cout << (char)205;
            cout <<(char)187;
        }
        if (nively==5) {
            cout << "   "<<(char)200;
            for (int iterate=0;iterate<63;iterate++)
                cout << (char)205;
            cout <<(char)188;
        }
        cout <<endl;
    }

    if (request==3){//                  IMPRIME LO DE ABAJO DEL TABLERO
        cout <<"        "<<(char)192;
        for (int nylon=1;nylon<28;nylon++){
            cout<<(char)196; temp++;
            if ((temp%3)==0&&nylon!=27){
                cout<<(char)193;
            }
        }
        cout<<(char)217<<endl;
    }

}

void celda (int num, int point, int cc){

    if (point==0) {     //          | 6 |
        if (num == 0) {
            cout << "  ";
        } else {
            cout << " "<< num;
        }
        if (cc==1) { //             | 6[|
            cout << (char)176;
        } else {
            cout << " ";
        }
    } else if (point==1) {//        |> <|
        if (num == 0) {
            cout << (char)175<<" ";
        } else {
            cout << (char)175<< num;
        }
        if (cc==1) { //             |> [|
            cout << (char)176;
        } else {
            cout << (char)174;
        }
    }

}
//              x               y        Numero     condicion
void sudoku (int & zeldax, int & zelday, int & nc, int & cn) {
    int u=220,d=223,m=219;

            if (zelday==0&&zeldax==0) {         //         PRIMER / n RENGLON
printf("=========                   %c%c%c%c%c%c%c   %c%c    %c%c   %c%c%c%c%c%c       %c%c%c%c%c%c   %c%c    %c%c%c   %c%c    %c%c               ===========\n",u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u,u);
printf("=========                  %c%c%c        %c%c    %c%c   %c%c    %c%c   %c%c    %c%c   %c%c  %c%c%c%c    %c%c    %c%c               ===========\n",m,m,d,m,m,m,m,m,m,m,m,m,m,m,m,m,m,u,m,m,d,m,m,m,m);
printf("=========                  %c%c%c%c%c%c%c    %c%c    %c%c   %c%c    %c%c   %c%c    %c%c   %c%c%c%c%c%c      %c%c    %c%c               ===========\n",d,m,m,u,u,u,u,m,m,m,m,m,m,m,m,m,m,m,m,m,m,u,m,m,d,m,m,m,m);
printf("=========                       %c%c%c   %c%c    %c%c   %c%c    %c%c   %c%c    %c%c   %c%c %c%c%c%c     %c%c    %c%c               ===========\n",d,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,d,m,m,u,m,m,m,m);
printf("=========                  %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c   %c%c%c%c   %c%c%c%c%c%c%c%c               ===========\n",u,u,u,u,u,m,m,d,m,m,u,u,u,u,d,d,m,m,u,u,u,u,d,d,m,m,u,u,u,u,d,d,m,m,d,m,m,u,m,m,u,u,u,u,d,d);

                renglon(1,0);
            } else if (zeldax==0) {
                renglon(2,zelday);
            }
            if (zeldax==0)
                cout << "        ";
            cout <<(char)179;   //          CELDA INDIVIDUAL
                celda(nc,0,cn);
            //                                          MANEJO DE VALORES POR EJE X

            zeldax++;

                                                    //  MANEJO DE VALORES POR EJE y
            if(zeldax == 9){
                cout <<(char)179<<"\t";
                switch (zelday) {
                    case 1: cout << (char)186 << " TECLAS DE COMANDOS "<< (char)186;
                        break;
                    case 2: cout << "  (S) GUARDAR la partida.  (R) REINICIAR TABLERO.";
                        break;
                    case 3: cout << "  (ESC) SALIR del tablero.";
                        break; //                 =================================================================
                    case 4: cout << (char)186 << " Mensajes:                                                     "<< (char)186;
                        break;
                }
                cout << endl;
                zeldax=0;
                zelday++;
            }
            if(zelday==9) //                              ULTIMO RENGLON
                renglon(3,0);

}

void Change(int color){
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main(){

    ifstream Lista;
    ofstream myfile;
    int keys, px=0, py=0;
    int celdax=0, celday=0;
    int operandi=0, advertencia;
    int gotx=9, goty=6;
    int n[9][9];
    int e[9][9];
    system("color F0");
    int gris = 248, negro = 240;

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
    Lista.close();
    for (int y=0;y<9;y++) { //               IMPRIME EL SUDOKU
        for (int x=0;x<9;x++){
            sudoku(celdax,celday,n[x][y],e[x][y]);
        }
    }

    gotoxy(60,14);
        cout << "Ningun mensaje hasta ahora.";

    celdax=0; celday=0;

    while (0==0) { //   ESTE WHILE ES EL MANEJO DE LA TABLA DEL SUDOKU Y SUS VALORES

        Ocultarcursor(); // EN CASO DE JUGAR A "PANTALLA COMPLETA"
        gotoxy(gotx,goty); // ESTO "LIMPIA LA CELDA QUE ESTABA APUNTANDO"
        celda(n[px][py],1,e[px][py]);
        Change(negro);

        // SECCION DE MENSAJES DE ADVERTENCIA
            gotoxy(60,14);
            if (advertencia==0)
                cout << "Ningun mensaje hasta ahora.                        ";
            if (advertencia==1)
                cout << "TABLERO CARGADO EXITOSAMENTE!                      ";
            if (advertencia==2)
                cout << "TABLERO GUARDADO EXITOSAMENTE!                     ";
            if (advertencia==3)
                cout << "SE REINICIO EL TABLERO EXITOSAMENTE!               ";
            if (advertencia==4)
                cout << "ERROR: No se encontr"<<(char)162<<" el archivo de guardado!";
            if (advertencia==5)
                cout << "LISTO! Abajo tienes las estadisticas.";

        gotoxy(gotx+1,goty); //ESTO APUNTA A LA SELECCIÓN DE LA CELDA ACTUAL

        keys=_getch();
        advertencia=0;

        if (keys==LEFT) { //======//

            gotoxy(gotx,goty);
            celda(n[px][py],0,e[px][py]);
            px--;
            if (px==-1)
                px=0;
            gotx=(px*4)+9;

        }
        if (keys==RIGHT) { //======//

            gotoxy(gotx,goty);
            celda(n[px][py],0,e[px][py]);
            px++;
            if (px==9)
                px=8;
            gotx=(px*4)+9;

        }
        if (keys==UP) { //======//

            gotoxy(gotx,goty);
            celda(n[px][py],0,e[px][py]);
            py--;
            if (py==-1)
                py=0;
            goty=(py*2)+6;

        }
        if (keys==DOWN) { //======//

            gotoxy(gotx,goty);
            celda(n[px][py],0,e[px][py]);
            py++;
            if (py==9)
                py=8;
            goty=(py*2)+6;

        }               //======//
        if (e[px][py]==0) {         //  ACCESO A PODER MODIFICAR VALORES
            Change(gris);
            switch (keys) {
                case 49:
                    n[px][py] =    1   ;
                    cout << "1";
                    break;
                case 50:
                    n[px][py] =    2   ;
                    cout << "2";
                    break;
                case 51:
                    n[px][py] =    3   ;
                    cout << "3";
                    break;
                case 52:
                    n[px][py] =    4   ;
                    cout << "4";
                    break;
                case 53:
                    n[px][py] =    5   ;
                    cout << "5";
                    break;
                case 54:
                    n[px][py] =    6   ;
                    cout << "6";
                    break;
                case 55:
                    n[px][py] =    7   ;
                    cout << "7";
                    break;
                case 56:
                    n[px][py] =    8   ;
                    cout << "8";
                    break;
                case 57:
                    n[px][py] =    9   ;
                    cout << "9";
                    break;
            }
        }
        if (keys==8||keys==48) { // "BORRAR UN VALOR EN LA TABLA"
            if (e[px][py]==0) {
                n[px][py]=0;
                cout <<" ";
            }
        }
        if (keys==27) { //  ESTE LUGAR TIENE COMO FUNCION SALIR DE LA TABLA
            system("cls");
            break;
        }
        if (keys==115) { //  ESTE LUGAR GUARDA GUARDA EL JUEGO
            myfile.open("plantilla2.txt");
            if (myfile.is_open())
            {
                for (int y=0;y<9;y++) { //   ASIGNACION DE LISTA A LA VARIABLE N
                    for (int x=0;x<9;x++){
                        myfile<<n[x][y]<<"\n";
                    }
                }
                myfile.close();
                advertencia=2;
                system("cls");
                celdax=0; celday=0;
                for (int y=0;y<9;y++) { //               IMPRIME EL SUDOKU
                    for (int x=0;x<9;x++){
                        sudoku(celdax,celday,n[x][y],e[x][y]);
                    }
                }
            } else {
            cout << "Error, no se encuentra el archivo 'plantilla2.txt' para el guardado";
            }
        }
        if (keys==99) { //          CARGA EL DOCUMENTO PLANTILLA 2
            celdax=0; celday=0;
            Lista.open("plantilla2.txt");
            if (!Lista.is_open()) {
                advertencia=4;
            } else {
                system("cls");
                for (int y=0;y<9;y++) { //
                    for (int x=0;x<9;x++){
                        Lista>>n[x][y];
                    }
                }
                Lista.close();
                advertencia=1;
                for (int y=0;y<9;y++) { //               IMPRIME EL SUDOKU
                    for (int x=0;x<9;x++){
                        sudoku(celdax,celday,n[x][y],e[x][y]);
                    }
                }
            }
        }
        if (keys==114) {        //              RESETEA EL SUDOKU COMPLETAMENTE
            celdax=0; celday=0;
            system("cls");
            for (int y=0;y<9;y++) { //  INICIALIZACION DE CONDICION A LA VARIABLE E
                for (int x=0;x<9;x++){
                        e[x][y]=0;
                }
            }
            Lista.open("plantilla1.txt");
            for (int y=0;y<9;y++) { //   ASIGNACION DE LISTA A LA VARIABLE N
                for (int x=0;x<9;x++){
                    Lista>>n[x][y];
                    if (n[x][y]!=0)
                        e[x][y] = 1;
                }
            }
            Lista.close();
            advertencia=3;
            for (int y=0;y<9;y++) { //               IMPRIME EL SUDOKU
                for (int x=0;x<9;x++){
                    sudoku(celdax,celday,n[x][y],e[x][y]);
                }
            }
            advertencia=3;
        }
        if (keys==108)
            advertencia=5;
        //system("cls");
        //cout<< keys;
    }
}
