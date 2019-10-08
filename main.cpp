#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <process.h>
#include <time.h>
#include <fstream>

using namespace std;



/*
 0 = Black       8 = Gray
    1 = Blue        9 = Light Blue
    2 = Green       A = Light Green
    3 = Aqua        B = Light Aqua
    4 = Red         C = Light Red
    5 = Purple      D = Light Purple
    6 = Yellow      E = Light Yellow
    7 = White       F = Bright White
    */


bool bad=false;



void gotoxy(int x,int y)
{
    COORD c;
    PCONSOLE_CURSOR_INFO j;
    c.X=x;
    c.Y=y;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h,c);
}







class Tictactoe
{
    char positionno[10];
    char name1[20];
    char name2[20];
    int i,j;
    int position_no;
    int player1win;
    int player2win;
    int gameno;
    int winner;
    int gamecode;

public:



    void heading()
    {
        system("cls");
        cout<<"________________________________________________________________________________________________________________________________________________________________________";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\tTIC TAC TOE\n";
        cout<<"________________________________________________________________________________________________________________________________________________________________________";
    }




    void board()
    {
        int namelength;

        heading();

        GAMENODISP();

        gotoxy(0,14);
        cout<<"\n                                    |         |                                                             ";
        cout<<"\n                                    |         |                                                             ";
        cout<<"\n                               "<<positionno[7]<<"    |    "<<positionno[8]<<"    |    "<<positionno[9];
        cout<<"\n                                    |         |                                                             ";
        cout<<"\n                           _________|_________|_________                                                      ";
        cout<<"\n                                    |         |                                                             ";
        cout<<"\n                                    |         |                                                             ";
        cout<<"\n                               "<<positionno[4]<<"    |    "<<positionno[5]<<"    |    "<<positionno[6];
        cout<<"\n                                    |         |                                                             ";
        cout<<"\n                           _________|_________|_________                                                      ";
        cout<<"\n                                    |         |                                                             ";
        cout<<"\n                                    |         |                                                             ";
        cout<<"\n                               "<<positionno[1]<<"    |    "<<positionno[2]<<"    |    "<<positionno[3];
        cout<<"\n                                    |         |                                                             ";
        cout<<"\n                                    |         |                                                             ";
    }



    void GAMENODISP(int onlyname=0, int n12=0)
    {
        int namelength;

        if(onlyname==1)
            goto onlyname;

        cout<<"\n                                                                    _______________";

        for(namelength=1;namelength<=strlen(name1);namelength++)
        {
            if(name1[9]==' ' && namelength==10)
                break;//if last to be pinted is space
            cout<<"_";
            if(namelength==10 || (name1[namelength-2]==' ' && namelength>1))
                break;
        }

        cout<<"___";

        for(namelength=1;namelength<=strlen(name2);namelength++)
        {
            if(name2[9]==' ' && namelength==10)
                break;
            cout<<"_";
            if(namelength==10 || (name2[namelength-2]==' ' && namelength>1))
                break;
        }

        cout<<"_";

        cout<<"\n                                                                   |             | ";

        for(namelength=1;namelength<=strlen(name1);namelength++)
        {
            if(name1[9]==' ' && namelength==10)
                break;
            cout<<" ";
            if(namelength==10 || (name1[namelength-2]==' ' && namelength>1))
                break;
        }

        cout<<" | ";

        for(namelength=1;namelength<=strlen(name2);namelength++)
        {
            if(name2[9]==' ' && namelength==10)
                break;
            cout<<" ";
            if(namelength==10 || (name2[namelength-2]==' ' && namelength>1))
                break;
        }

        cout<<" |";

        cout<<"\n                                                                   | GAME NO. ";

        if(gameno/10==0)
            cout<<"0"<<gameno;
        else
            cout<<setw(2)<<gameno;

        cout<<" | ";

        onlyname:

        if(n12==1)
            goto n1;
        else if(n12==2)
            goto n2;

        n1:

        for(namelength=0;namelength<10 && namelength<strlen(name1);namelength++)
        {
            if(name1[9]==' ' && namelength==9)
                break;
            cout<<(name1[namelength]);
            if(name1[namelength-1]==' ' && namelength!=0)
                break;
        }

        if(onlyname==1)
            goto endname;

        cout<<" | ";

        n2:

        for(namelength=0;namelength<10 && namelength<strlen(name2);namelength++)
        {
            if(name2[9]==' ' && namelength==9)
                break;
            cout<<(name2[namelength]);
            if(name2[namelength-1]==' ' && namelength!=0)
                break;
        }

        if(onlyname==1)
            goto endname;

        cout<<" |";

        cout<<"\n                                                                   |_____________|_";

        for(namelength=1;namelength<=strlen(name1);namelength++)
        {
            if(name1[9]==' ' && namelength==10)
                break;
            cout<<"_";
            if(namelength==10 || (name1[namelength-2]==' ' && namelength>1))
                break;
        }

        cout<<"_|_";

        for(namelength=1;namelength<=strlen(name2);namelength++)
        {
            if(name2[9]==' ' && namelength==10)
                break;
            cout<<"_";
            if(namelength==10 || (name2[namelength-2]==' ' && namelength>1))
                break;
        }

        cout<<"_|";

        endname:;
    }



    void HowToPlay()
    {
        char entry;

        heading();

        cout<<"\n";
        cout<<"________________________________________________________________________________________________________________________________________________________________________";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\tHOW TO PLAY?\n";
        cout<<"________________________________________________________________________________________________________________________________________________________________________";
        cout<<"\n\n\n\n\n";
        cout<<"\n                                                                                           INSTRUCTIONS: ";
        cout<<"\n\n";
        cout<<"\n                        |     |                                                           1. Turnwise both the players will get a chance to plot his mark";
        cout<<"\n                     7  |  8  |  9                                                         ";
        cout<<"\n                   _____|_____|_____           SIMILAR TO NUMBER KEYPAD                   2. The objective is to make a straight line with your mark";
        cout<<"\n                        |     |                                                              before the other player.";
        cout<<"\n                     4  |  5  |  6          OR YOU CAN USE THE ARROW KEYS                          ";
        cout<<"\n                   _____|_____|_____        AND PRESS ENTER WHEREVER YOU                  3. Each player, on his chance, has to enter the number at ";
        cout<<"\n                        |     |                   WANT TO ASSIGN                             which he/she desires to get his mark placed.";
        cout<<"\n                     1  |  2  |  3                                                         ";
        cout<<"\n                        |     |                                                           4. PLAYER 1-[X]";
        cout<<"\n                                                                                             PLAYER 2-[0]";
        cout<<"\n\n\n\n                                             PRESS ENTER TO RETURN...";
        do
        {
            entry=getch();
        }while(entry!=13);
    }



    void NameForResult(int chanceno)
    {
        int namelength;

        char name[20];

        if(chanceno%2!=0)
            strcpy(name,name1);
        else
            strcpy(name,name2);

        cout<<"\n           |             "<<positionno[4]<<"  |  "<<positionno[5]<<"  |  "<<positionno[6]<<"              "<<name<<" WINS";
        for(namelength=1;namelength<=99-strlen(name);namelength++)
            cout<<" ";
        cout<<"|";
    }



    void ABOUT()
    {
        char entry;

        heading();
        cout<<"\n";
        cout<<"________________________________________________________________________________________________________________________________________________________________________";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\tHOW TO PLAY?\n";
        cout<<"________________________________________________________________________________________________________________________________________________________________________";
        cout<<"\n\n\n\n\n";
        cout<<"\t\t\t\t THIS GAME WAS CREATED BY TUSHAR MONGA IN 2018.";
        cout<<"\n\n\n\n                                             PRESS ENTER TO RETURN...";
        do
        {
            entry=getch();
        }while(entry!=13);
    }



    void INPUT(int chanceno)
    {
        int namelength;
        int value;

        int updown=0;
        int leftright=0;

        char position;

        gotoxy(90,16);

        if(chanceno%2==1)
        {
            GAMENODISP(1,1);
            cout<<"'s TURN  :  [X]";
        }
        else
        {
            GAMENODISP(1,2);
            cout<<"'s TURN  :  [O]";
        }

        gotoxy(90,19);
        cout<<"USE ARROW KEYS AND PRESS ENTER ";
        gotoxy(90,20);
        cout<<"ON DESIRED LOCATION";
        gotoxy(90,22);
        cout<<"OR PRESS THE POSITION NUMBER ACC.";
        gotoxy(90,23);
        cout<<"TO YOUR NUMBER KEYPAD";

        pos1:
        repos:
        gotoxy(31+(10*j),17+(5*i));

        ASSINGPOS();

        if(positionno[position_no]!=' ')
        {
            if(position==72 && updown<=3)
            {
                //or it will keep in the same row.. infinte loop
                if(updown==3)
                {
                    position=77;
                    updown++;
                    goto repos;
                }
                UP();
                updown++;
                goto pos1;
            }
            else if(position==75 && leftright<=3)
            {
                //same reason as above
                if(leftright==3)
                {
                    position=80;
                    leftright++;
                    goto repos;
                }
                LEFT();
                leftright++;
                goto pos1;
            }
            else if(position==77 && leftright<=3)
            {
                if(leftright==3)
                {
                    position=80;
                    leftright++;
                    goto repos;
                }
                RIGHT();
                leftright++;
                goto pos1;
            }
            else if(position==80 && updown<=3)
            {
                if(updown==3)
                {
                    position=77;
                    updown++;
                    goto repos;
                }
                DOWN();
                updown++;
                goto pos1;
            }
        }

        updown=0;
        leftright=0;

        position=getch();

        if(position==72)
        {
            UP();
            goto pos1;
        }
        else if(position==75)
        {
            LEFT();
            goto pos1;
        }
        else if(position==77)
        {
            RIGHT();
            goto pos1;
        }
        else if(position==80)
        {
            DOWN();
            goto pos1;
        }
        else if(position==13)
        {
            ASSINGPOS();
            if(positionno[position_no]==' ')
            {
                if(chanceno%2!=0)
                    positionno[position_no]='X';
                else
                    positionno[position_no]='O';
            }
            else
                goto pos1;
        }
        else if(position>48 && position<=57)
        {
            value=position-48;
            ASSINGPOS();
            if(positionno[value]==' ')
            {
                if(chanceno%2!=0)
                    positionno[value]='X';
                else
                    positionno[value]='O';
            }
            else
                goto pos1;
        }
        else
            goto pos1;
    }



    void ShowAll()
    {
        int inc;

        char entry;

        ifstream show;

        Tictactoe t;

        heading();

        cout<<"________________________________________________________________________________________________________________________________________________________________________";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t    SHOWING ALL GAME DATA\n";
        cout<<"________________________________________________________________________________________________________________________________________________________________________";

        show.open("TICTACTOE.DAT",ios::in|ios::binary);
        if(!show)
        {
            cout<<"\n\n\n\t\t FILE CONTAINING GAME RECORDS ABSENT";
            cout<<"\n\n\t\t PRESS ANY KEY TO RETURN...";
            getch();
            return;
        }

        gotoxy(20,10);
        cout<<"GAME CODE";
        gotoxy(40,10);
        cout<<"PLAYER 1 NAME";
        gotoxy(62,10);
        cout<<"PLAYER 2 NAME";
        gotoxy(84,10);
        cout<<"GAMES PLAYED";
        gotoxy(105,10);
        cout<<"WINNER";

        inc=0;

        while(!show.eof())
        {
            show.read((char*)&t,sizeof(Tictactoe));
            if(show.eof())
                break;

            inc+=2;

            gotoxy(24,11+inc);
            cout<<t.gamecode;
            gotoxy(40,11+inc);
            cout<<t.name1;
            gotoxy(62,11+inc);
            cout<<t.name2;
            gotoxy(88,11+inc);
            cout<<t.gameno;
            gotoxy(105,11+inc);
            if(t.winner==1)
                cout<<t.name1;
            else if(t.winner==2)
                cout<<t.name2;
            else
                cout<<"ENDED AS DRAW";
        }

        show.close();

        cout<<"\n\n\n\n\n\n\t\t PRESS ENTER KEY TO CLOSE";
        do
        {
            entry=getch();
        }while(entry!=13);
    }



    void EnterPlayerName()
    {
        int namelength;

        heading();
        cout<<"\n\n\n\t Player 1's name please? : ";
        gets(name1);

        for(namelength=0;namelength<=strlen(name1);namelength++)
            name1[namelength]=toupper(name1[namelength]);

        cout<<"\n\t Player 2's name please? : ";
        gets(name2);

        for(namelength=0;namelength<=strlen(name2);namelength++)
            name2[namelength]=toupper(name2[namelength]);

        cout<<"\n\n\n\t PRESS ENTER KEY TO START THE GAME";
        getch();
    }



    void DEL()
    {
        int code;
        int found=0;

        char entry;

        ifstream del;
        ofstream deltemp;

        Tictactoe t;

        heading();

        del.open("TICTACTOE.DAT",ios::in|ios::binary);
        if(!del)
        {
            cout<<"\n\n\n\t\t FILE CONTAINING GAME RECORDS ABSENT";
            cout<<"\n\n\t\t DELETING FAILED";
            cout<<"\n\n\t\t PRESS ANY KEY TO RETURN...";
            getch();
            del.close();
            return;
        }

        cout<<"\n\n\n\t\t Enter the game code you want to delete : ";
        cin>>code;

        deltemp.open("TICTACTOETEMP.DAT",ios::out|ios::binary);

        while(!del.eof())
        {
            del.read((char*)&t,sizeof(Tictactoe));
            if(del.eof())
                break;

            if(t.gamecode!=code)
            {
                if(found==1)
                    t.gamecode=t.gamecode-1;
                deltemp.write((char*)&t,sizeof(Tictactoe));
            }
            else
            {
                found=1;
            }
        }

        del.close();
        deltemp.close();

        if(found==1)
        {
            remove("TICTACTOE.DAT");
            cin.ignore(10,'\n'); // to clear buffer
            rename("TICTACTOETEMP.DAT","TICTACTOE.DAT");
            cout<<"\n\n\t\t DELETED THE GAME RECORD WITH GAMECODE : "<<code;
            cout<<"\n\n\t\t PRESS ENTER TO RETURN...";
            do
            {
                entry=getch();
            }while(entry!=13);
        }
        else
        {
            cout<<"\n\n\t\t NO GAME EXISTS WITH THAT GAMECODE";
            cout<<"\n\n\t\t DELETING FAILED";
            cin.clear();
            cin.ignore(10,'\n');
            remove("TICTACTOETEMP.DAT");
            cout<<"\n\n\t\t PRESS ENTER TO RETURN...";
            do
            {
                entry=getch();
            }while(entry!=13);
            return;
        }
    }



    void ASSINGPOS()
    {
        if(i==0)
        {
            if(j==0)
            {
                position_no=7;
            }
            else if(j==1)
            {
                position_no=8;
            }
            else
            {
                position_no=9;
            }
        }
        else if(i==1)
        {
            if(j==0)
            {
                position_no=4;
            }
            else if(j==1)
            {
                position_no=5;
            }
            else
            {
                position_no=6;
            }
        }
        else
        {
            if(j==0)
            {
                position_no=1;
            }
            else if(j==1)
            {
                position_no=2;
            }
            else
            {
                position_no=3;
            }
        }
    }



    void UP()
    {
        if(i==0)
        {
            i=2;
        }
        else
        {
            i--;
        }
    }



    void RIGHT()
    {
        if(j==2)
        {
            j=0;
        }
        else
        {
            j++;
        }
    }



    void LEFT()
    {
        if(j==0)
        {
            j=2;
        }
        else
        {
            j--;
        }
    }



    void DOWN()
    {
        if(i==2)
        {
            i=0;
        }
        else
        {
            i++;
        }
    }



    void RESULT()
    {
        heading();

        cout<<"\n";
        cout<<"________________________________________________________________________________________________________________________________________________________________________";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t  RESULT\n";
        cout<<"________________________________________________________________________________________________________________________________________________________________________";

        cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t    Total Matches : "<<gameno<<"\n\n";

        cout<<"\t\t\t\t\t\t\t\t\t    Matches Won by "<<name1<<" : "<<player1win<<"\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t    Matches Won by "<<name2<<" : "<<player2win<<"\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t    Matches Ended as a Draw : "<<gameno-player1win-player2win;

        if(player1win>player2win)
        {
            cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t    HENCE, "<<name1<<" WON\n\n\n";
            winner=1;
        }
        else if(player1win<player2win)
        {
            cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t    HENCE, "<<name2<<" WON\n\n\n";
            winner=2;
        }
        else
            cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t    HENCE, NO ONE WON\n\n\n";
    }



    void INITIALIZE()
    {
        i=0;
        j=0;

        positionno[1]=' ';
        positionno[2]=' ';
        positionno[3]=' ';
        positionno[4]=' ';
        positionno[5]=' ';
        positionno[6]=' ';
        positionno[7]=' ';
        positionno[8]=' ';
        positionno[9]=' ';
    }



    void SearchRecord()
    {
        int code;
        int found=0;

        char entry;

        ifstream sdrcd;

        Tictactoe t;

        heading();

        sdrcd.open("TICTACTOE.DAT",ios::in|ios::binary);
        if(!sdrcd)
        {
            cout<<"\n\n\n\t\t FILE CONTAINING GAME RECORDS ABSENT";
            cout<<"\n\n\t\t SEARCHING FAILED";
            cout<<"\n\n\t\t PRESS ANY KEY TO RETURN...";
            getch();
            sdrcd.close();
            return;
        }

        cout<<"\n\n\n\t\t Enter the game code of the record to be displayed : ";
        cin>>code;

        while(!sdrcd.eof())
        {
            sdrcd.read((char*)&t,sizeof(Tictactoe));
            if(sdrcd.eof())
                break;

            if(t.gamecode==code)
            {
                found=1;
                t.RESULT();
                cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t  PRESS ENTER TO RETURN...";
                do
                {
                    entry=getch();
                }while(entry!=13);
                break;
            }
        }

        sdrcd.close();

        if(found==0)
        {
            cout<<"\n\n\t\t NO GAME EXISTS WITH THAT GAMECODE";
            cout<<"\n\n\t\t SEARCHING FAILED";
            cin.clear();
            cin.ignore(10,'\n');
            cout<<"\n\n\t\t PRESS ENTER TO RETURN...";
            do
            {
                entry=getch();
            }while(entry!=13);
            return;
        }
        cin.ignore(10,'\n'); // to clear buffer
    }



    void PlayGame()
    {
        char playagain;
        char entry;

        int chanceno;
        int check;

        Tictactoe t;

        t.player1win=t.player2win=0;

        t.gameno=1;

        t.EnterPlayerName();

        gameagain:

        t.INITIALIZE();

        chanceno=1;

        do
        {
            t.board();
            t.INPUT(chanceno);

            check=t.Check(chanceno);

            if(check==1)
            {
                if(chanceno%2!=0)
                    t.player1win++;
                else
                    t.player2win++;
            }

            chanceno++;

        }while(check!=1 && chanceno!=10);

        if(check==0)
        {
            heading();
            t.GAMENODISP();

            cout<<"\n\n\n";
            cout<<"\n            ________________________________________________________________________________________________________________________________________________";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                |     |                                                                                                                         |";
            cout<<"\n           |             "<<t.positionno[7]<<"  |  "<<t.positionno[8]<<"  |  "<<t.positionno[9]<<"                                                                                                                      |";
            cout<<"\n           |           _____|_____|_____                                                                                                                    |";
            cout<<"\n           |                |     |                                                                                                                         |";
            cout<<"\n           |             "<<t.positionno[4]<<"  |  "<<t.positionno[5]<<"  |  "<<t.positionno[6]<<"                    DRAW                                                                                              |";
            cout<<"\n           |           _____|_____|_____                                                                                                                    |";
            cout<<"\n           |                |     |                                                                                                                         |";
            cout<<"\n           |             "<<t.positionno[1]<<"  |  "<<t.positionno[2]<<"  |  "<<t.positionno[3]<<"                                                                                                                      |";
            cout<<"\n           |                |     |                                                                                                                         |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |________________________________________________________________________________________________________________________________________________|";
        }

        ii:
        cout<<"\n\n\n\tWANT TO CONTINUE TO NEXT MACTH ? (y/n) ";
        playagain=getch();
        cout<<playagain;
        playagain=tolower(playagain);

        if(playagain!='y' && playagain!='n')
        {
            cout<<"\n\n\tINVALID INPUT\n";
            goto ii;
        }

        if(playagain=='y')
        {
            t.gameno++;
            goto gameagain;
        }
        else
        {
            t.RESULT();

            ofstream save;
            save.open("TICTACTOE.DAT",ios::app|ios::binary);

            save.seekp(0,ios::end);
            t.gamecode=(save.tellp()/sizeof(Tictactoe))+1;

            save.write((char*)&t,sizeof(Tictactoe));

            save.close();

            cout<<"\n\n\t\t\t\t\t\t\t\t\t  RESULT SAVED WITH GAMECODE "<<t.gamecode;
            cout<<"\n\n\t\t\t\t\t\t\t\t\t    PRESS ENTER TO RETURN...";
            do
            {
                entry=getch();
            }while(entry!=13);
        }



    }



    int Check(int chanceno)
    {
        char checkfor;
        int game_finish=0;
        if(chanceno%2!=0)
            checkfor='X';
        else
            checkfor='O';

        heading();
        GAMENODISP();

        if(positionno[7]==checkfor && positionno[8]==checkfor && positionno[9]==checkfor)
        {
            cout<<"\n\n\n\n            ________________________________________________________________________________________________________________________________________________";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                |     |                                                                                                                         |";
            cout<<"\n           |          ---"<<positionno[7]<<"--|--"<<positionno[8]<<"--|--"<<positionno[9]<<"---                                                                                                                   |";
            cout<<"\n           |           _____|_____|_____                                                                                                                    |";
            cout<<"\n           |                |     |                                                                                                                         |";

            NameForResult(chanceno);

            cout<<"\n           |           _____|_____|_____                                                                                                                    |";
            cout<<"\n           |                |     |                                                                                                                         |";
            cout<<"\n           |             "<<positionno[1]<<"  |  "<<positionno[2]<<"  |  "<<positionno[3]<<"                                                                                                                      |";
            cout<<"\n           |                |     |                                                                                                                         |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |________________________________________________________________________________________________________________________________________________|";

            game_finish++;
        }

        else if(positionno[4]==checkfor && positionno[5]==checkfor && positionno[6]==checkfor)
        {
            cout<<"\n\n\n\n            ________________________________________________________________________________________________________________________________________________";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                |     |                                                                                                                         |";
            cout<<"\n           |             "<<positionno[7]<<"  |  "<<positionno[8]<<"  |  "<<positionno[9]<<"                                                                                                                      |";
            cout<<"\n           |           _____|_____|_____                                                                                                                    |";
            cout<<"\n           |                |     |                                                                                                                         |";
            if(chanceno%2!=0)
                cout<<"\n           |          ---"<<positionno[4]<<"--|--"<<positionno[5]<<"--|--"<<positionno[6]<<"---            "<<setw(12)<<right<<name1<<" WINS                                                                                       |";
            else
                cout<<"\n           |          ---"<<positionno[4]<<"--|--"<<positionno[5]<<"--|--"<<positionno[6]<<"---            "<<setw(12)<<right<<name2<<" WINS                                                                                       |";
            cout<<"\n           |           _____|_____|_____                                                                                                                    |";
            cout<<"\n           |                |     |                                                                                                                         |";
            cout<<"\n           |             "<<positionno[1]<<"  |  "<<positionno[2]<<"  |  "<<positionno[3]<<"                                                                                                                      |";
            cout<<"\n           |                |     |                                                                                                                         |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |________________________________________________________________________________________________________________________________________________|";

            game_finish++;
        }

        else if(positionno[1]==checkfor && positionno[2]==checkfor && positionno[3]==checkfor)
        {
            cout<<"\n\n\n\n            ________________________________________________________________________________________________________________________________________________";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                |     |                                                                                                                         |";
            cout<<"\n           |             "<<positionno[7]<<"  |  "<<positionno[8]<<"  |  "<<positionno[9]<<"                                                                                                                      |";
            cout<<"\n           |           _____|_____|_____                                                                                                                    |";
            cout<<"\n           |                |     |                                                                                                                         |";

            NameForResult(chanceno);

            cout<<"\n           |           _____|_____|_____                                                                                                                    |";
            cout<<"\n           |                |     |                                                                                                                         |";
            cout<<"\n           |          ---"<<positionno[1]<<"--|--"<<positionno[2]<<"--|--"<<positionno[3]<<"---                                                                                                                   |";
            cout<<"\n           |                |     |                                                                                                                         |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |________________________________________________________________________________________________________________________________________________|";

            game_finish++;
        }

        else if(positionno[7]==checkfor && positionno[4]==checkfor && positionno[1]==checkfor)
        {
            cout<<"\n\n\n\n            ________________________________________________________________________________________________________________________________________________";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |             |                                                                                                                                  |";
            cout<<"\n           |             |  |     |                                                                                                                         |";
            cout<<"\n           |             "<<positionno[7]<<"  |  "<<positionno[8]<<"  |  "<<positionno[9]<<"                                                                                                                      |";
            cout<<"\n           |           __|__|_____|_____                                                                                                                    |";
            cout<<"\n           |             |  |     |                                                                                                                         |";

            NameForResult(chanceno);

            cout<<"\n           |           __|__|_____|_____                                                                                                                    |";
            cout<<"\n           |             |  |     |                                                                                                                         |";
            cout<<"\n           |             "<<positionno[1]<<"  |  "<<positionno[2]<<"  |  "<<positionno[3]<<"                                                                                                                      |";
            cout<<"\n           |             |  |     |                                                                                                                         |";
            cout<<"\n           |             |                                                                                                                                  |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |________________________________________________________________________________________________________________________________________________|";

            game_finish++;
        }

        else if(positionno[8]==checkfor && positionno[5]==checkfor && positionno[2]==checkfor)
        {
            cout<<"\n\n\n\n            ________________________________________________________________________________________________________________________________________________";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                   |                                                                                                                            |";
            cout<<"\n           |                |  |  |                                                                                                                         |";
            cout<<"\n           |             "<<positionno[7]<<"  |  "<<positionno[8]<<"  |  "<<positionno[9]<<"                                                                                                                      |";
            cout<<"\n           |           _____|__|__|_____                                                                                                                    |";
            cout<<"\n           |                |  |  |                                                                                                                         |";

            NameForResult(chanceno);

            cout<<"\n           |           _____|__|__|_____                                                                                                                    |";
            cout<<"\n           |                |  |  |                                                                                                                         |";
            cout<<"\n           |             "<<positionno[1]<<"  |  "<<positionno[2]<<"  |  "<<positionno[3]<<"                                                                                                                      |";
            cout<<"\n           |                |  |  |                                                                                                                         |";
            cout<<"\n           |                   |                                                                                                                            |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |________________________________________________________________________________________________________________________________________________|";

            game_finish++;
        }

        else if(positionno[9]==checkfor && positionno[6]==checkfor && positionno[3]==checkfor)
        {
            cout<<"\n\n\n\n            ________________________________________________________________________________________________________________________________________________";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                         |                                                                                                                      |";
            cout<<"\n           |                |     |  |                                                                                                                      |";
            cout<<"\n           |             "<<positionno[7]<<"  |  "<<positionno[8]<<"  |  "<<positionno[9]<<"                                                                                                                      |";
            cout<<"\n           |           _____|_____|__|__                                                                                                                    |";
            cout<<"\n           |                |     |  |                                                                                                                      |";

            NameForResult(chanceno);

            cout<<"\n           |           _____|_____|__|__                                                                                                                    |";
            cout<<"\n           |                |     |  |                                                                                                                      |";
            cout<<"\n           |             "<<positionno[1]<<"  |  "<<positionno[2]<<"  |  "<<positionno[3]<<"                                                                                                                      |";
            cout<<"\n           |                |     |  |                                                                                                                      |";
            cout<<"\n           |                         |                                                                                                                      |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |________________________________________________________________________________________________________________________________________________|";

            game_finish++;
        }

        else if(positionno[1]==checkfor && positionno[5]==checkfor && positionno[9]==checkfor)
        {
            cout<<"\n\n\n\n            ________________________________________________________________________________________________________________________________________________";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                |     |   *                                                                                                                     |";
            cout<<"\n           |             "<<positionno[7]<<"  |  "<<positionno[8]<<"  |  "<<positionno[9]<<"                                                                                                                      |";
            cout<<"\n           |           _____|_____|*____                                                                                                                    |";
            cout<<"\n           |                |    *|                                                                                                                         |";

            NameForResult(chanceno);

            cout<<"\n           |           _____|*____|_____                                                                                                                    |";
            cout<<"\n           |               *|     |                                                                                                                         |";
            cout<<"\n           |             "<<positionno[1]<<"  |  "<<positionno[2]<<"  |  "<<positionno[3]<<"                                                                                                                      |";
            cout<<"\n           |            *   |     |                                                                                                                         |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |________________________________________________________________________________________________________________________________________________|";

            game_finish++;
        }

        else if(positionno[3]==checkfor && positionno[5]==checkfor && positionno[7]==checkfor)
        {
            cout<<"\n\n\n\n            ________________________________________________________________________________________________________________________________________________";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |            *   |     |                                                                                                                         |";
            cout<<"\n           |             "<<positionno[7]<<"  |  "<<positionno[8]<<"  |  "<<positionno[9]<<"                                                                                                                      |";
            cout<<"\n           |           ____*|_____|_____                                                                                                                    |";
            cout<<"\n           |                |*    |                                                                                                                         |";

            NameForResult(chanceno);

            cout<<"\n           |           _____|____*|_____                                                                                                                    |";
            cout<<"\n           |                |     |*                                                                                                                        |";
            cout<<"\n           |             "<<positionno[1]<<"  |  "<<positionno[2]<<"  |  "<<positionno[3]<<"                                                                                                                      |";
            cout<<"\n           |                |     |   *                                                                                                                     |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |                                                                                                                                                |";
            cout<<"\n           |________________________________________________________________________________________________________________________________________________|";

            game_finish++;
        }

        return(game_finish);
    }



    void DRIVER()
    {
        char choice;

        int returnmain=0;

        do
        {
            wrongentry:
            heading();
            gotoxy(81,10);
            cout<<"MENU";
            gotoxy(76,13);
            cout<<"1. PLAY GAME";
            gotoxy(76,15);
            cout<<"2. SEARCH A RECORD";
            gotoxy(76,17);
            cout<<"3. SHOW ALL RECORDS DATA";
            gotoxy(76,19);
            cout<<"4. DELETE RECORD";
            gotoxy(76,21);
            cout<<"5. HOW TO PLAY?";
            gotoxy(76,23);
            cout<<"6. ABOUT";
            gotoxy(76,25);
            cout<<"7. EXIT";
            gotoxy(79,30);
            cout<<"CHOICE : ";

            choice=getch();

            if(choice<49 || choice>56)
            {
                goto wrongentry;
            }
            else
            {
                cout<<choice;

                switch(choice)
                {
                    case '1': PlayGame();
                              break;

                    case '2': SearchRecord();
                              break;

                    case '3': ShowAll();
                              break;

                    case '4': DEL();
                              break;

                    case '5': HowToPlay();
                              break;

                    case '6': ABOUT();
                              break;

                    case '7': returnmain=1;
                              exit(0);
                }
            }
        }while(returnmain!=1);
    }



};


int main()
{
    char enter;

    srand(time(0));

    cout<<"\n\n\n\n\n\t\tPLEASE ENTER FULL SCREEN..AND PRESS ENTER THEN";
    do
    {
       enter=getch();
    }while(enter!=13);

    Tictactoe t;
    system("color 0f");
    t.DRIVER();
}
