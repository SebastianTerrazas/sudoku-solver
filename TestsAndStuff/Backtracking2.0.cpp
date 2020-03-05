//B A C K T R A C K I N G     == 2  .  0 ==
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
#define UNASSIGNED 0
#define N 9

bool FindUnassignedLocation(int n[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (n[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool UsedInRow(int n[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (n[row][col] == num)
            return true;
    return false;
}

bool UsedInCol(int n[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (n[row][col] == num)
            return true;
    return false;
}

bool UsedInBox(int n[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (n[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}

bool isSafe(int n[N][N], int row, int col, int num)
{
    return !UsedInRow(n, row, num) &&
           !UsedInCol(n, col, num) &&
           !UsedInBox(n, row - row%3 , col - col%3, num);
}

bool SolveSudoku(int n[N][N])
{
    int row, col;

    if (!FindUnassignedLocation(n, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(n, row, col, num))
        {
            n[row][col] = num;

            if (SolveSudoku(n))
                return true;

            n[row][col] = UNASSIGNED;
        }
    }
    return false;
}

void printGrid(int n[N][N])
{
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
             printf("%2d", n[row][col]);
        printf("\n");
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

    printGrid(n);
    printf("\n");
    if (SolveSudoku(n) == true)
          printGrid(n);
    else
         printf("No solution exists");

    return 0;
}
