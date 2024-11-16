#include<iostream>
#include "game.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
    char positions[9] = {' ', ' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    int game = true;

    drawGrill(positions);
    while (game)
    {
        /* code */
        playerMove(positions, player);
        drawGrill(positions);
        /*Check if the player win*/
        if(winner(positions)){
            game = false;
            break;
        }
        /*Check if the computer win*/
        computerMove(positions, computer);
        drawGrill(positions);
        if(winner(positions)){
            game = false;
            break;
        }
        
    }
    
    return 0;
}

void drawGrill(char *postions){
    cout<<"_________"<<"\n";
    cout<<postions[0]<<" |"<<postions[1]<<" |"<<postions[2]<<" |\n";
    cout<<"__|__|__|"<<"\n";
    cout<<postions[3]<<" |"<<postions[4]<<" |"<<postions[5]<<" |\n";
    cout<<"__|__|__|"<<"\n";
    cout<<postions[6]<<" |"<<postions[7]<<" |"<<postions[8]<<" |\n";
    cout<<"__|__|__|"<<"\n";
    cout<<"_________"<<"\n";
}

void playerMove(char *positions, char player){
    int number ;
    do
    {
        /* code */
        cout <<"Enter the position between 1 and 9"<<endl;
        cin>>number;
        number--;
        if (positions[number]==' '){
            positions[number] = player;
            break;
        }else{
            cout <<"The position is already occupied"<<endl;
        }
    } while (!number >0 || !number <8);
    cout<<"Done"<<endl;
}


void computerMove(char *positions, char computer){
    int number ;
    do
    {
        /* code */
        cout <<"Enter the position between 1 and 9"<<endl;
        cin>>number;
        number--;
        if (positions[number]==' '){
            positions[number] = computer;
            break;
        }else{
            cout <<"The position is already occupied"<<endl;
        }
    } while (!number >0 || !number <8);
    cout<<"Done"<<endl;
}
char checkDiagonals(char *positions)
{
    if (positions[0] == positions[4] && positions[4] == positions[8] && positions[0] != ' ')
        return positions[0];
    if (positions[2] == positions[4] && positions[4] == positions[6] && positions[2] != ' ')
        return positions[2];
    return 'N';
}

char checkRows(char *positions)
{
    for (int i = 0; i < 9; i += 3)
    {
        if (positions[i] == positions[i + 1] && positions[i + 1] == positions[i + 2] && positions[i] != ' ')
            return positions[i];
    }
    return 'N';
}

char checkCols(char *positions)
{
    for (int i = 0; i < 3; ++i)
    {
        if (positions[i] == positions[i + 3] && positions[i + 3] == positions[i + 6] && positions[i] != ' ')
            return positions[i];
    }
    return 'N';
}

bool winner(char *positions){
    bool isTie = true;
    if (checkDiagonals(positions)!='N' )
    {
        cout <<"the winner is : "<<checkDiagonals(positions);
        return 1;
    }

    if (checkRows(positions)!='N' )
    {
        cout <<"the winner is : "<<checkRows(positions);
        return 1;
    }

    if (checkCols(positions)!='N' )
    {
        cout <<"the winner is : "<<checkCols(positions);
        return 1;
    }
    for (int i = 0; i < 9; i++)
    {
        /* code */
        if (positions[i]==' '){
            isTie=false; 
            break;
        }
    }
    if(isTie){
        cout<<"This is a tie"<<endl;
        return true;
        }
    
    return 0;
}