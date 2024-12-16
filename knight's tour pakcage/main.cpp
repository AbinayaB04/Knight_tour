#include <bits/stdc++.h>
#include <iostream>

///global declaration of the size of chess board
#define N 9

using namespace std;
int main();
/// definition of the functions used in knight tour problem

///this function checks for the i,j are valid
int isValid(int knight[N][N], int rl, int ud,int n)
{
    if (rl >= 0 && rl < n && ud < n && ud >= 0 && knight[rl][ud] == -1)
        return 1;
    else
        return 0;
}

///this function displays the knight's tour in matrix form positioning (0-(n-1))
void displayKnight(int knight[N][N],int n)
{
    int i=0,j=0;
    cout<<"\n\n\n\t\t\t\t\tTHE KNIGHT'S TOUR IN MATRIX FORM IN CHESS BOARD\n\n\n";
    for(i=0;i<n;i++)
    {
        cout<<"\n\t\t\t\t\t\t";
        for(j=0;j<n;j++)
        {
            cout<<" "<<setw(2)<<knight[i][j]<<" ";
        }
    }
    cout<<"\n\n\n";

}

///this function is a recursive function to solve knight's tour
int knightTour(int knight[N][N],int rl,int ud,int movrl[],int movud[],int moves,int n)
{
    int i,x,y;
    if(moves==n*n)
        return 1;

    for(i=0;i<8;i++)
    {
        x=rl+movrl[i];
        y=ud+movud[i];

        if(isValid(knight,x,y,n))
        {
            knight[x][y]=moves;

            if((knightTour(knight,x,y,movrl,movud,moves+1,n))==1)
                return 1;
            else
                knight[x][y]=-1;

        }

    }
    return 0;
}

///this function is for backtracking,and gives solution if tour gets completed
int tourWay(int n)
{
    int knight[N][N];

    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            knight[i][j]=-1;
        }
    }
    int movrl[8]={2,1,-1,-2,-2,-1,1,2};
    int movud[8]={1,2,2,1,-1,-2,-2,-1};

    knight[0][0]=0;

    if(knightTour(knight,0,0,movrl,movud,1,n)==0)
    {
        cout<<"\n\n\n\t\t\t\t    THERE IS NO SOLUTION FOR THE "<<n<<"X"<<n<<" OF CHESS BOARD!!!!!\n\n\n\n";
        return 0;

    }
    else
    {
        displayKnight(knight,n);
    }
    return 1;
}
///the main function code
void input()
{
    int n;
    cout<<"\n\n\t\t\t\t\t\t*****KNIGHT'S TOUR*****";
    cout<<"\n\n\n\t\t\t\t\tTHE SIZE OF CHESS BOARD BETWEEN 1 TO 8";
    cout<<"\n\n\n\t\t\t\t\t   ENTER THE SIZE OF CHESS BOARD:";
    cin>>n;
    cout<<"\n";
    if(n>=1 && n<=8)
        tourWay(n);
    else
    {
        cout<<"\n\t\t\t\t\tENTER THE VALID SIZE OF CHESS BOARD:";
        input();

    }
    main();

}
int main()
{
    int c;
    cout<<"\n\t\t\t\t\t\tCHOICES!!!!!!\n\n\t\t\t\t\t   1.ENTER 1 TO SEE KNIGHT'S TOUR\n\n\t\t\t\t\t   2.ENTER 0 TO EXIT\n\n";
    cout<<"\n\t\t\t\t\t   ENTER YOUR CHOICE :";
    cin>>c;
    if(c==1)
        input();
    else
        exit(1);
    return 0;
}
