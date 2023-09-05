#include <iostream>
#include <time.h>
#include <conio.h>
#include <unistd.h>
using namespace std;

void Assign(char grid[][30]);
void Simulate(char grid[][30]);
void Print(char Grid[][30]);

int main()
{
    char GRID[30][30];
    Assign(GRID);
    while(1){
        Print(GRID);
        usleep(300000);
        cout<<endl;
        Simulate(GRID);
    }

    return 0;
}
void Assign(char grid[][30]){

    srand(time(0));
    for(int i=0; i<30; ++i){
        for(int j=0; j<30; ++j){
            if(rand()%2==1)
                grid[i][j]='*';
            else
                grid[i][j]=' ';
        }
    }
}
void Simulate(char grid[][30]){

    for(int i=0; i<30; ++i){
        for(int j=0; j<30; ++j){
			int aliveCount=0;
            if(i==0 && j==0){       //Corner-1
                if(grid[i][j+1]=='*')
                       ++aliveCount;
                if(grid[i+1][j]=='*')
                    ++aliveCount;
                if(grid[i+1][j+1]=='*')
                    ++aliveCount;
            }
            else if(i==0 && j==29){     //Corner-2
                if(grid[i][j-1]=='*')
                    ++aliveCount;
                if(grid[i+1][j]=='*')
                    ++aliveCount;
                if(grid[i+1][j-1]=='*')
                    ++aliveCount;
            }
            else if(i==29 && j==0){     //Corner-3
                if(grid[i-1][j]=='*')
                    ++aliveCount;
                if(grid[i-1][j+1]=='*')
                    ++aliveCount;
                if(grid[i][j+1]=='*')
                    ++aliveCount;
            }
            else if(i==29 && j==29){    //Corner-4
                if(grid[i][j-1]=='*')
                    ++aliveCount;
                if(grid[i-1][j-1]=='*')
                    ++aliveCount;
                if(grid[i-1][j]=='*')
                    ++aliveCount;
            }
            else if(i==0 && j>=0 && j<29){      //Side-1
                if(grid[i][j+1]=='*')
                    ++aliveCount;
                if(grid[i][j-1]=='*')
                    ++aliveCount;
                if(grid[i+1][j-1]=='*')
                    ++aliveCount;
                if(grid[i+1][j]=='*')
                    ++aliveCount;
                if(grid[i+1][j+1]=='*')
                    ++aliveCount;
            }
            else if(i>0 && i<29 && j==0){      //Side-2
                if(grid[i][j+1]=='*')
                    ++aliveCount;
                if(grid[i-1][j]=='*')
                    ++aliveCount;
                if(grid[i-1][j+1]=='*')
                    ++aliveCount;
                if(grid[i+1][j]=='*')
                    ++aliveCount;
                if(grid[i+1][j+1]=='*')
                    ++aliveCount;
            }
            else if(i>0 && i<29 && j==29){     //Side-3
                if(grid[i][j-1]=='*')
                    ++aliveCount;
                if(grid[i-1][j-1]=='*')
                    ++aliveCount;
                if(grid[i-1][j]=='*')
                    ++aliveCount;
                if(grid[i+1][j-1]=='*')
                    ++aliveCount;
                if(grid[i+1][j]=='*')
                    ++aliveCount;
            }
            else if(i==29 && j>0 && j<29){	//Side-4
                if(grid[i][j+1]=='*')
                    ++aliveCount;
                if(grid[i][j-1]=='*')
                    ++aliveCount;
                if(grid[i-1][j-1]=='*')
                    ++aliveCount;
                if(grid[i-1][j]=='*')
                    ++aliveCount;
                if(grid[i-1][j+1]=='*')
                    ++aliveCount;
            }
            else{
                if(grid[i-1][j-1]=='*')		//Center
                    ++aliveCount;
                if(grid[i-1][j]=='*')
                    ++aliveCount;
                if(grid[i-1][j+1]=='*')
                    ++aliveCount;
                if(grid[i][j+1]=='*')
                    ++aliveCount;
                if(grid[i][j-1]=='*')
                    ++aliveCount;
                if(grid[i+1][j-1]=='*')
                    ++aliveCount;
                if(grid[i+1][j]=='*')
                    ++aliveCount;
                if(grid[i+1][j+1]=='*')
                    ++aliveCount;
            }
            if(grid[i][j]=='*'){		//Rules for alive and dead
                if(aliveCount==0 || aliveCount==1)
                    grid[i][j]=' ';
                else if(aliveCount==2 || aliveCount==3)
                    grid[i][j]='*';
                else if(aliveCount>3)
                    grid[i][j]=' ';
            }
            else if(aliveCount==3){
                grid[i][j]='*';
            }
        }
    }
}
void Print(char Grid[][30]){
    
    for(int i=0; i<30; ++i){
        for(int j=0; j<30; ++j)
            cout<<Grid[i][j]<<" ";
        cout<<endl;
    }
}
