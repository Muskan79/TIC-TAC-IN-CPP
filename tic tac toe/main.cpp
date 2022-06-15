#include <iostream>
#include<stdlib.h>
using namespace std;

// lets first create board  for our game

char board[3][3]={ {'1','2','3'},{'4','5','6'},{'7','8','9'}};
string p1="";
string p2="";
int row,column;
char ch='X';  // now we create 1 varaible if value of tgat variable is x then imput from 1st user will be taken else second
bool tie=false;


// lets us now draw the image of our board
void draw()
{

    cout<<endl;
    cout<<"\t\t\t"<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<endl;
    cout<<"\t\t\t-------------"<<endl;
    cout<<"\t\t\t"<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<endl;
    cout<<"\t\t\t-------------"<<endl;
    cout<<"\t\t\t"<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<endl;
}

// function for placing or accesing the location in board
void access()
{
    int choice;  // now we create 1 varaible if value of tgat variable is x then imput from 1st user will be taken else second
    if (ch=='X'){
        cout<<p1<<" enter the number in which you want to place ";
        cin>>choice;}

     if (ch=='0'){
        cout<<p2<<" enter the number in which you want to place ";
        cin>>choice;}

  // ab hm assign kr rhe h indexe to choice entered by user
    if(choice==1)
    {
        row=0;
        column=0;
    }

    if(choice==2)
    {
         row=0;
         column=1;
    }
    if(choice==3)
    {
        row=0;
        column=2;
    }
     if(choice==4)
    {
        row=1;
        column=0;
    }
     if(choice==5)
    {
        row=1;
        column=1;
    }
     if(choice==6)
    {
        row=1;
        column=2;
    }
     if(choice==7)
    {
        row=2;
        column=0;
    }
     if(choice==8)
    {
        row=2;
        column=1;
    }
     if(choice==9)
    {
       row=2;
       column=2;
    }
    else if(choice<1|| choice>9){
        cout<<"inavlid number "<<endl;
    }


    //
    if(ch=='X' && board[row][column]!='X' && board[row][column]!='0') // this means it is unused place
    {                                            // then insert the token at that particular place
        board[row][column]='X';
        ch='0'; // after inserting X then ch must contain 0 in order for other player to insert
    }
     else if(ch=='0' && board[row][column]!='0' && board[row][column]!='X')
    {
        board[row][column]='0';
        ch='X';
    }
    // if there is no empty space then tell the players to play it again
    else
        {
            cout<<"There is no space "<<endl;
             // we will call the function again
             access();
       }
}


// now we will create a function to check which player is winning and also check if th egame is still going on or its a draw
// this function will be of boolean type to return either true or false
bool win_draw()
{
int j;
//*************************** for wining the game -----------------------------
    // we know a player wins if vertically , horizontally or diagonaly pair matches
    for(int i=0;i<3;i++)  // why i<3 bec we have matrx of 3 by 3
    {
        // checking for horizontally and vertically
        if(board[i][0]==board[i][1]&&board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]== board[2][i]) {return true;}
    }
    // for daigonal elements--
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]|| board[0][2]==board[1][1]&& board[1][1]==board[2][1]){return true;}

// -------------------------------------checking if the game is finished--------------------------
    for(int i=0;i<3;j++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='X' && board[i][j]!='0') {return false;}// here we are checking each index and if each index is not having x or 0 ythen that means game is not finished yet

        }
    }

// -------------------------------------checking if the game is draw--------------------------
tie=true;
// we will return value false to this bool function win_draw in case
return false;
}

int main()
{

    cout<<"\t\t\t\t\tWELCOME TO THE TIC TAC TOE GAME"<<endl;
    //tring p1,p2;
    cout<<"\t\tPLAYER 1 ";
    getline(cin,p1);
    cout<<"\t\tPLAYER 2 ";
    getline(cin,p2);
    cout<<p1<<" will have [x] sign "<<endl;
    cout<<p2<<" will have [0] sign "<<endl;


        while(!win_draw())
        {
         draw();
         access();
         win_draw();
        }


    //
    if(ch='X' && tie==false)
    {
        cout<<p1<<" Wins "<<endl;
    }
    else if(ch='0' && tie==false)
    {
        cout<<p2<<" Wins "<<endl;
    }
   else
    cout<<"draww"<<endl;
    return 0;
}
