#include<iostream>
#include "Board.h"
using namespace std;

int row =3 , col = 3;

int countNeighbourCell (int grid[3][3], int r, int c){
    int count =0;
    for(int i=r-1; i<=r+1; i++){
        for(int j=c-1; j<=c+1; j++){
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col)){
                continue;
            }
            if(grid[i][j] == 1){
                count += 1;
            }
        }
    }
    return count;
}

int main(){
    int neighbourCount =0;
    int initialGrid[3][3];
    int grid[3][3];

    // Initialize the Grid.
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            grid[i][j] = 0;
            initialGrid[i][j] = 0;
        }
    }
    // Printing Initial Grid.
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<< initialGrid[i][j] << " " ;
        }
        cout<<endl;
    }
    
    cout<< "How much input you want?. \n";
    int max;
    cin >> max;

    Board b[max];
    cout<< "Enter the values. \n";
    Board::setValues(max, b);

    // User Input. 
    for(int i=0; i<max; i++){
        b[i].getValues();
    }
    
    // Setting grid values according to user Input.
    for(int j=0; j<max; j++){
        initialGrid[b[j].x][b[j].y] = 1;
    }

    // Printing Changed Grid.
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<< initialGrid[i][j] << " " ;
        }
        cout<<endl;
    }
    // Logic to find life and death. 
    for(int i=0; i<row; i++){
        for(int j=0;j<col;j++){
            neighbourCount = countNeighbourCell(initialGrid, i, j);
            if((initialGrid[i][j] == 1) && (neighbourCount == 2 || neighbourCount == 3)){
                grid[i][j] = 1;
            }
            else if((initialGrid[i][j] == 0) && (neighbourCount == 3)){
                grid[i][j] = 1;
            }
            else{
                grid[i][j] = 0;
            }
        }
    }
    cout<< "Final output is \n";
    // Final Output
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<< grid[i][j] << " " ;
        }
        cout<<endl;
    }
}


