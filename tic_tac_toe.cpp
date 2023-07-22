#include <iostream>
using namespace std;
void design(int rows, int columns, char array[3][3]);
int main()
{

//char **array;
int rows = 3;
int columns = 3;
int count_X=0;
int count_O=0;
int coke, fanta;
bool exist;
int plus=0;
char array[3][3] ={'1', '2', '3', '4', '5', '6', '7','8','9'};
char player;

 char number;
 int round =1;

////////////////////ARRAY MAKER IF I USED  A POINTER////////////////
//array = new char* [rows];

//for(int i=0; i<rows; i++)
//{
  //  array[i] = new char [columns];
//}
///////////////////END IF ARRAY MAKER///////////////

//////////////////PLAY THE GAME///////////
cout << "Rules:" <<'\n';
cout << "Players can only play in positions occupied by a number" << '\n' << '\n';

int k=0;

while(k==0)
{
    design(rows, columns, array);
    for (int i=1; i<10; i++)
    {
        plus = 0;
        if ( i % 2 == 1)
        { 
            if(i==1)
            {
                cout << " Player X BEGIN! " << endl;
            }
            else
            {
                 cout << "Your turn Player X" <<'\n' << '\n';
            }
        player = 'X';
        }
        else
        {
            cout << "Your turn Player O " <<'\n' << '\n';
            player = 'O';
        }
            
        char temp = number;
    
        cout <<" Enter a number shown to fill a position: ";
        cin >> number;
        
////////////////////////// VERIFIER//////////////////////////


       ////////////// ENSURES YOU ENTER A NUMBER POSITION SHOWN (1-9)/////////////
        while(number != '1'&& number != '2' && number != '3'&& number != '4'&& number != '5'&&
                         number != '6'&& number != '7' && number != '8'&& number != '9')
            {
                
                cout << "ERROR: INVALID INPUT " << '\n' << "Enter a number shown to fill a position ";
                cin >> number;

            }
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////ENSURES YOU CAN'T FILL A POSITION OCCUPIED BY A PLAYER///////////////
            
            for (int i=0; i< rows; i++)
                {
                    for(int j=0; j< columns; j++)
                    {
                            if (array[i][j] != number)
                            {
                              
                              plus++;

                            } 
                            
                    }
                    
                }
                 // cout << "The value of plus is :" << plus << '\n';
                  while(plus == 9)
                  {
                    plus =0;
                      cout << "ERROR: Enter a valid number" << '\n' << "Enter a number shown to fill a position ";
                      cin >> number;

                        for (int i=0; i< rows; i++)
                        {
                            for(int j=0; j< columns; j++)
                            {
                                    if (array[i][j] != number)
                                    {
                                    
                                    plus++;

                                    } 
                                    
                            }
                            
                        }

                  }

//////////////////////////////////////////////////////////////////////////////////////////////////////
        
           /////////////// FILLS POSITION INDICATED BY NUMBER WITH PLAYER /////////////////////////////     
            for (int i=0; i< rows; i++)
                {
                    for(int j=0; j< columns; j++)
                    {
                            if (array[i][j]== number)
                            {
                                coke = i;
                                fanta = j;
                                array[i][j] = player; 

                                
                            } 
                    }
                }
///////////////////////////////////////////////////////////////////////////////////////////////////////
                cout << '\n' ;
                design(rows, columns, array);
                //cout << "The new value of plus is: " << plus <<'\n';

///////////////////////////////////// WINNER //////////////////////////////////////////////////////////////////
                for (int q=0; q< rows; q++)
                {
                        if (array[q][0] == array[q][2] && array[q][1] == array[q][2] )
                        {
                            if (array[q][0] == 'X'|| array[q][0] == 'x'){
                            cout << "PLAYER " << array[0][0] << " WINS ROUND "<< round << endl;
                            count_X++;
                            round++;
                            i=10;

                            }
                            else {
                                cout << "PLAYER " << array[0][0] << " WINS ROUND " << round << endl;
                                count_O++;
                                round++;
                            i=10;
                            }
                        }
        
                }

                if((array[0][0]== array[1][1] && array[0][0]== array[2][2]) || (array[0][2] == array[1][1] && array[0][2]==array[2][0]))
                    {
                    if (array[1][1] == 'X' || array[1][1]=='x'){
                            cout << "PLAYER " << array[0][0] << " WINS ROUND "<< round << endl;
                            count_X++;
                            round++;
                            i=10;
                            }
                            else {
                                cout << "PLAYER " << array[1][1] << " WINS ROUND " << round << endl;
                                count_O++;
                                round++;
                                i=10;
                            } 


                    }

                    for(int c=0; c < columns; c++)
                        {
                          if(array[0][c] == array[1][c] && array[1][c] == array[2][c])
                          {
                            if (array[0][c] == 'X'|| array[0][c] == 'x'){
                            cout << "PLAYER " << array[0][c] << " WINS ROUND "<< round << endl;
                            count_X++;
                            round++;
                            i=10;

                            }
                            else {
                                cout << "PLAYER " << array[0][c] << " WINS ROUND " << round << endl;
                                count_O++;
                                round++;
                            i=10;
                            }
                          }
                          
                        }

                                  
        }
               ///////////RESETS THE ARRAY//////////////
                    array[0][0] = '1';
                    array[0][1] = '2';
                    array[0][2] = '3';
                    array[1][0] = '4';
                    array[1][1] = '5';
                    array[1][2] = '6';
                    array[2][0] = '7';
                    array[2][1] = '8';
                    array[2][2] = '9'; 

////////////////////////////////////////////////////

///////////////////// EXECUTES IF IT'S A DRAW////////////////
            char Answer;
            if (count_X==0 && count_O==0)
            {
            cout << " NO WINNER " << '\n';
            }
 /////////////////////////////////////////////////////////////

 //////////////////////////REPLAY OR END GAME/////////////////           
            cout << "To play again ENTER Y, TO quit ENTER N" <<'\n';
            cin >> Answer;
            if (Answer ==  'y' || Answer == 'Y')
            k=0;
            else if (Answer == 'n' || Answer == 'N')
            k=1;
////////////////////////////////////////////////////////////            
}

////////////////////////////PRINT SCORES AND RESULT///////////////////

cout << "SCORES: " <<'\n';
cout <<"player X: " << count_X << '\n';
cout << "player O: " << count_O << '\n' << '\n';
if(count_X > count_O)
    {
        cout << "PLAYER X WINS!!!!";
    }
else if(count_O > count_X) 
{
    cout << "PLAYER O WINS!!!!";
}
else
{
cout << "IT'S A TIE" ;
}
///////////////////////////////////////////////////////////////////
    return 0;
}


////////////////TIC-TAC-TOE DESIGN///////////////////////
void design(int rows, int columns, char array[3][3]){
cout << '\n';
for (int i=0; i< rows; i++)
        {
            for(int j=0; j< columns; j++)
                {
                    cout << array[i][j];
                if (j < (columns-1))
                {
                    cout << " | ";
                }
                 }
                 cout << '\n';
                  if(i != 2 && columns != 2 )  
                 cout << "----------" << endl;
        }

        cout << '\n';
}
///////////////////////////END OF DESIGN///////////////////////