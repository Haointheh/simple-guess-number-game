#include <iostream>
#include <string>
#include <stdlib.h>       //c standard library for random number generation
#include <ctime>
using namespace std;

char playername[50];

void gamestart()
{
    int guess;           //variable to store the users guess
    int tries=5;
    int range;

    cout<<"\n\n              GAME START   "<<endl;
    cout<<"          Enter your choice of range: ";
    cin>>range;
    cout<<"                Range choosen "<<range<<endl;

    int randomnum;
    randomnum=rand()%range;
    cout<<"("<<randomnum<<")"<<endl;


    cout<<"\n     Guess the number between 0 to "<<range-1<<endl;
    cout<<"        You have 5 tries. Good luck!"<<endl;
    while (tries!=0 and guess!=randomnum)
    {
        cout<<"\nEnter your guess: ";
        cin>>guess;
        tries-=1;
        if (guess<randomnum)
        {
            cout<<"  (the number is greater) , no.of tries left: "<<tries<<endl;
        }
        else if(guess>randomnum)
        {
            cout<<"  (the number is smaller) , no.of tries left:"<<tries<<endl;
        }
    }

    if (tries==0)
    {
        cout<<"\n  ..................................................................\n";
        cout<<"\n  .                         YOU LOST                               .\n";
        cout<<"\n  .            Sorry but your number of tries ran out.             .\n";
        cout<<"\n  .               Returning back to main menu..                    .\n";
        cout<<"\n  ..................................................................\n";
    }
    else if (guess==randomnum)
    {
        cout<<"\n  ..................................................................\n";
        cout<<"\n                              YOU WON                               \n";
        cout<<"\n      Congratulations "<<playername<< ". You guessed it right       \n";
        cout<<"\n                   Returning back to main menu..                    \n";
        cout<<"\n  ..................................................................\n";
    }


}

int main()
{
    cout<<".........................................................................................\n";
    cout<<"  .....................................................................................\n";
    cout<<"                                                                         \n";
    cout<<"                        WELCOME TO THE GUESSING GAME                        \n";
    cout<<"                         ------------------------                             \n";
    cout<<"                                                                         \n";
    cout<<"                                                                         \n";
    cout<<"                                                                         \n";
    cout<<"                                                                         \n";
    cout<<"                                                                         \n";
    cout<<"                                  :RULES:                                     \n";
    cout<<"                                   -----                                   \n";
    cout<<"                    A random number will be generated   \n";
    cout<<"              Players can choose the range of numbers they want to guess from  \n";
    cout<<"                   The player will have 5 tries to guess the number  \n";


    cout<<"                                                                         \n";
    cout<<"                                                                         \n";
    cout<<"                                                                        \n";
    cout<<"                     ~~press any key to start the game~~                \n";
    cout<<"                                                                 \n";
    cout<<"  .....................................................................................\n";
    cout<<".........................................................................................\n";



    cout<<"Enter player name: ";
    cin>>playername;

    srand(time(NULL));    //starts random number once it runs
    int ch;
    do
    {
        cout<<"\n\n\n  ..Main Menu.."<<endl;
        cout<<"1.play game\n";
        cout<<"0.exit"<<endl;
        cout<<"\n Enter choice:";
        cin>>ch;

        switch(ch)
        {
            case 0:
                cout<<"\n Exitting the game"<<endl;
                break;

            case 1:
                gamestart();
                break;

            default:
                cout<<"Please enter a valid choice";
        }
    }while (ch!=0);

}
