#include<iostream>

using namespace std;

class Board{
    public:
    int x;
    int y;
};

int main() {
    int row, col;
    cout<<"Enter the Rows and col of the Grid.\n";
    cin >> row >> col;
    int grid[row][col];
    int initialGrid[row][col];
    // Initialize the Grid.
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            grid[i][j] = 0;
            initialGrid[i][j] = 0;
        }
    }

    // Printing Initial grid.
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<< initialGrid[i][j] << " " ;
        }
        cout<<endl;
    }

    // Get the co-ordinates from the user.
    cout<<"How many co-ordinates you want to give ? \n";
    int max;
    cin>> max;
    Board b[max];

    cout<< "Enter the Co-Ordinates.\n";
    // 0 -> Death , 1 -> Life.
    for(int i=0; i<max; i++){
        cin >> b[i].x >> b[i].y;
    }

    // Changing the Grid variable with user co-ordinates
        for(int j=0; j<max; j++){
            initialGrid[b[j].x][b[j].y] = 1;
        }

    // Printing the changed grid.
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