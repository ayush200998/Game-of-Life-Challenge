#include<iostream>

using namespace std;

class Board{
    public:
    int x;
    int y;

    static void setValues(int max, Board *b){
        for(int i=0; i<max; i++){
            cin >> b[i].x >> b[i].y;
    }
    }
    void getValues(){
        cout<<"x:" <<this->x <<" " <<" y:"  <<this->y << endl;
    }
};