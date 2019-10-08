#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>


using namespace std;

struct cards
{
    int number;
    string type;
};
cards kartyak[52];
void pokercards ()
{
    string treff, karo, kor, pikk;
    kor=03;
    treff=05;
    karo=04;
    pikk=06;

    string colour;

    int j, i, k;
    for(k=0; k<4; k++)
    {
        j=2;
        if(k==0)
            colour=kor;
        if(k==1)
            colour=treff;
        if(k==2)
            colour=karo;
        if(k==3)
            colour=pikk;
        for(i=k; i<52; i+=4)
        {
            kartyak[i].number=j;
            kartyak[i].type=colour;
            j++;
        }
    }
}


void card(int a, string b)
{
    string vonal, vonal2, sarok1, sarok2, sarok3, sarok4;
    vonal=196;
    vonal2=179;
    sarok1=218;
    sarok2=191;
    sarok3=192;
    sarok4=217;
    string symbol;

    cout<<sarok1<<vonal<<vonal<<vonal<<vonal<<vonal<<vonal<<sarok2<<endl;
    if(a<10)
    {
        for(int i=0; i<7; i++)
        {
            if(i==3)
            {
                cout<<vonal2<<"  "<<a<<b<<"  "<<vonal2<<endl;
            }
            cout<<vonal2<<"      "<<vonal2<<endl;
        }
        cout<<sarok3<<vonal<<vonal<<vonal<<vonal<<vonal<<vonal<<sarok4;
    }


    if(a==10)
        symbol="10";
    if(a==11)
        symbol="J";
    if(a==12)
        symbol="Q";
    if(a==13)
        symbol="K";
    if(a==14)
        symbol="A";

    if(a==10)
    {
        for(int i=0; i<7; i++)
        {
            if(i==3)
            {
                cout<<vonal2<<"  "<<symbol<<b<<" "<<vonal2<<endl;
            }
            cout<<vonal2<<"      "<<vonal2<<endl;
        }
        cout<<sarok3<<vonal<<vonal<<vonal<<vonal<<vonal<<vonal<<sarok4;
        cout<<endl;
    }
    if(a>10)
    {
        for(int i=0; i<7; i++)
        {
            if(i==3)
            {
                cout<<vonal2<<"  "<<symbol<<b<<"  "<<vonal2<<endl;
            }
            cout<<vonal2<<"      "<<vonal2<<endl;
        }
        cout<<sarok3<<vonal<<vonal<<vonal<<vonal<<vonal<<vonal<<sarok4;
        cout<<endl;
    }

}
int probability(int c)
{
    int limit,limit2, prob;
    if(c==16)
    {
        limit=rand()%10;
        if(limit>5)
        {
            limit2=limit-4;
        }
        else limit2=limit+4;
        prob=rand()%10;
        if(prob>=limit && prob<=limit2)
            return 1;
        else return 2;
    }
    if(c==17)
    {
        limit=rand()%10;
        if(limit>6)
        {
            limit2=limit-3;
        }
        else limit2=limit+3;
        prob=rand()%10;
        if(prob>=limit && prob<=limit2)
            return 1;
        else return 2;
    }
    if(c==18)
    {
        limit=rand()%10;
        if(limit>7)
        {
            limit2=limit-2;
        }
        else limit2=limit+2;
        prob=rand()%10;
        if(prob>=limit && prob<=limit2)
            return 1;
        else return 2;
    }
    if(c==19)
    {
        limit=rand()%10;
        if(limit>8)
        {
            limit2=limit-1;
        }
        else limit2=limit+1;
        prob=rand()%10;
        if(prob>=limit && prob<=limit2)
            return 1;
        else return 2;
    }
    if(c==20)
    {
        limit=rand()%10;
        prob=rand()%10;
        if(prob==limit)
            return 1;
        else return 2;
    }
}
void compare(int a, int b)
{
    if(a<21 && b<21)
    {
        if(a>b)
            cout<<"You won!";
        if(a<b)
            cout<<"Computer won!";
        if(a==b)
            cout<<"Draw!";
        cout<<endl<<"Your total is: "<<a<<", and computer's total is: "<<b<<".";
    }
}
bool torf (int a)
{
    if(a==1)
        return true;
    if(a==2)
        return false;
}
int sumcount (int a)
{
    int c=0;
    if(a<11)
    {
        c+=a;
    }
    else if(a==11 || a==12 || a==13)
    {
        c+=10;
    }
    else if(a==14)
    {
        c+=11;
    }
    return c;
}
void blackjack ()
{
ifstream file("input.txt");
string line;
while(getline(file, line))
{
    cout<<line<<endl;
}
}



int main()
{
    pokercards();
    blackjack();

    int counter=0;

    bool getcard=true;
    bool nextplayer;

    int number12;
    int i;

    cout<<"This is a simple version of the game called Blackjack, also known as twenty-one. \n";
    cout<<"The objective of the game is to beat the computer in one of the following ways: \n";
    cout<<" -Get 21 points. \n -Reach a final score higher than the computer without exceeding 21. \n";
    cout<<"You will get your total by adding together the values of the cards. \nFace cards (kings, queens, and jacks) are counted as ten points. An ace is counted as 11 points. \n";
    cout<<"All other cards are counted as the numeric value shown on the card.\n";
    cout<<"Scoring higher than 21 results in a loss.\n\n";

    system("pause");

    cout<<"\nFor a NEW CARD press 1, if you want to finish press 2"<<endl;

    while(getcard==true)
    {
        srand(time(NULL));
        i=rand()%52;
        while(kartyak[i].number==0)
        {
            i=rand()%52;
        }
        card(kartyak[i].number, kartyak[i].type);
        cout<<endl;

        counter+=sumcount(kartyak[i].number);
        kartyak[i].number=0;


        if(counter>21)
        {
            cout<<"You lost!"<<endl;
            getcard=false;
        }
        else if(counter==21)
        {
            cout<<"BLACKJACK!!! You won!"<<endl;
            getcard=false;
        }
        cout<<"Your total is: "<<counter<<"."<<endl;
        if(counter<21)
        {
            cout<<"Continue? (Press 1 for YES, press 2 for NO): ";
            cin>>number12;
            getcard=torf(number12);
        }
    }

    int copy1=counter;

    if(copy1<21)
        nextplayer=true;
    else nextplayer=false;

    if(nextplayer==true)

    {

        cout<<"Computer's turn:"<<endl;

        getcard=true;
        counter=0;

        while(getcard==true)
        {
            system("pause");
            srand(time(NULL));
            i=rand()%52;

            while(kartyak[i].number==0)
            {
                i=rand()%52;
            }

            card(kartyak[i].number, kartyak[i].type);
            cout<<endl;

            counter+=sumcount(kartyak[i].number);
            kartyak[i].number=0;


            //if(counter<copy1){
            if(counter>21)
            {
                cout<<"Computer lost, you won"<<endl;
                getcard=false;
            }
            else if(counter==21)
            {
                cout<<"BLACKJACK!!! Computer won, you lost"<<endl;
                getcard=false;
            }
            cout<<"Computer's total is: "<<counter<<"."<<endl;

            if(counter<21)
            {
                if(counter>copy1)
                    getcard=false;
                else
                {
                    if(counter<16)
                    {
                        number12=1;
                    }

                    if(counter>15)
                    {
                        number12=probability(counter);
                    }

                    getcard=torf(number12);
                }
            }
        }
        int copy2=counter;

        compare(copy1,copy2);
    }

    return 0;
}
