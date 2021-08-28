#include<iostream>
#include "Board.h"
using namespace std;

int main(){
    int row, col;
    cout<< "Enter number of rows and columns. \n";
    cin>> row >> col;
    int initialGrid[row][col];
    int grid[row][col];

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
        for(int j=0; j<col;j++){
            int count = 0;
            // Checking for death. 8 sides to check therefore 8 conditions.
            if(initialGrid[i][j] == 0){
                // Adjacent Columns
                cout<< initialGrid[i][j-1] <<endl; 
                if(initialGrid[i][j-1] == 1 && j!=0){
                    count += 1;                    
                }
                if(initialGrid[i][j+1] == 1 && j!=col -1 ){
                    count += 1;
                }

                // Adjacent rows
                if(initialGrid[i - 1][j] == 1 && i!=0){
                    count += 1; 
                }
                if(initialGrid[i+1][j] == 1 && i!= row-1){
                    count += 1;
                }

                // Checking diagonals
                if((initialGrid[i+1][j+1] == 1) && (i!=row-1 && j!= col-1)){
                    count += 1;
                }
                if((initialGrid[i-1][j-1] == 1) && (i!=0 && j!=0)){
                    count += 1;
                }

                // Alternate diagonal
                if((initialGrid[i+1][j-1] == 1) && (i!= row-1 && j!=0)){
                    count += 1;
                }

                if((initialGrid[i-1][j+1] == 1) && (i!=0 && j!=col-1)){
                    count += 1;
                }

                if(count == 3){
                    grid[i][j] = 1;
                }
            }
            if(initialGrid[i][j] == 1){
                // Adjacent Columns
                if(initialGrid[i][j-1] == 1 && j!=0){
                    count += 1;                    
                }
                if(initialGrid[i][j+1] == 1 && j!=col -1 ){
                    count += 1;
                }

                // Adjacent rows
                if(initialGrid[i - 1][j] == 1 && i!=0){
                    count += 1; 
                }
                if(initialGrid[i+1][j] == 1 && i!= row-1){
                    count += 1;
                }

                // Checking diagonals
                if((initialGrid[i+1][j+1] == 1) && (i!=row-1 && j!= col-1)){
                    count += 1;
                }
                if((initialGrid[i-1][j-1] == 1) && (i!=0 && j!=0)){
                    count += 1;
                }

                // Alternate diagonal
                if((initialGrid[i+1][j-1] == 1) && (i!= row-1 && j!=0)){
                    count += 1;
                }

                if((initialGrid[i-1][j+1] == 1) && (i!=0 && j!=col-1)){
                    count += 1;
                }

                if(count == 2 || count == 3){
                    grid[i][j] = 1;
                }else{
                    grid[i][j] = 0;
                }
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


