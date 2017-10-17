//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
int mat[9][9];
bool fi=false;

void printmat()
{
    int i, j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int valid(int row, int col, int value)
{
    //row check
    int a, b;
    for(a=0;a<9;a++){
        if(a==col)
            continue;
        if(mat[row][a]==value)
            return 0;
    }
    //col check
    for(a=0;a<9;a++){
        if(a==row)
            continue;
        if(mat[a][col]==value)
            return 0;
    }
    //sub set check
    for(a=row/3*3;a<row/3*3+3;a++){
        for(b=col/3*3;b<col/3*3+3;b++){
            if(a==row && b==col)
                continue;
            if(mat[a][b]==value)
                return 0;
        }
    }
    return 1;
}

void rec(int row, int col)
{
    //answer found
    if(row==8 && col==8){
        printmat(), fi=true;
    }
    //stop tree
    if(fi)
        return;
    //update row and col
    col++;
    if(col==9)
        col=0, row++;
    //special case
    if(mat[row][col]){
        rec(row, col);
        return;
    }
    //generate random answer
    for(int i=1; i<=9;i++){
        if(valid(row, col, i)){
            mat[row][col]=i;
            rec(row, col);
        }
    }
    mat[row][col]=0;
}

int main()
{
    int i, j;
    
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            cin >> mat[i][j];
        }
    }
    
    rec(0, -1);
    if(!fi)
        cout << "NO SOLUTION" << endl;
    return 0;
}
