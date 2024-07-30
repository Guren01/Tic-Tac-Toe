#include <iostream>
#include <cmath>
#include <array>
#include <string.h>

using namespace std ;
const int MAX = 9 ;
using tableau = array<char,MAX> ;

void saisie(tableau &tab)
{
    for(int i=0 ; i<MAX ; i++)
    {
        tab[i] = '0' + (i + 1) ;
    }
}

int chekWin( tableau & tab)
{
    for(int i = 0 ; i<MAX ; i+=3)
    {
        if(tab[i] == tab[i+1] && tab[i+1]==tab[i+2])
        {
            return 1 ;
        }
    }
    for(int j = 0 ; j<MAX ; j++)
    {
        if(tab[j] == tab[j+3] && tab[j+3]== tab[j+3+3] )
        {
            return 1 ;
        }
    }
    if(tab[0]== tab[4]&& tab[4]== tab[8])
    {
        return 1 ;
    }
    else if(tab[2] == tab[4] && tab[4] == tab [6])
    {
        return 1;
    }
    for (int k = 0; k < MAX; k++) 
    {
        if (tab[k] == '0' + (k + 1)) 
        {
            return -1; 
        }
    }
    return 0 ;
}

void board(tableau  tab)
{
    system("cls");
    cout << "\n\n Tic Toe Game \n\n";
    cout << "Player 1(X) - Player 2(O)" << endl << endl ;
    cout << endl ;
    cout << "     \t|     \t|     \n" ;
    cout << " " << tab[0] << "  \t|  " << tab[1] << "  \t|  " << tab[2] << endl ;
    cout << "_______\t|_______|_____ " << endl ;
    cout << "     \t|     \t|      " << endl ;
    cout << " " << tab[3] << "  \t|  " << tab[4] << "  \t|  " << tab[5] << endl ;
    cout << "_______\t|_______|_____" << endl ;
    cout << "     \t|     \t|      " << endl ;
    cout << " " << tab[6] << "  \t|  " << tab[7] << "  \t|  " << tab[8] << endl ;
    cout << "     \t|     \t|     " ;
}
int main()
{
    tableau tab ;
    saisie(tab);
    int player = 1 , win , choice ;
    char mark ;
    do
    {
        board(tab) ;
        player = (player%2)?1:2 ;
        cout << "Player " << player << ", enter the number: ";
        cin >> choice ;
        mark = (player == 1)?'X':'O';
        bool invalid = true ;
        for(int i=0 ; i<MAX ; i++)
        {
            if(choice == i+1 && tab[i] == '0'+(i+1))
            {
                tab[i] = mark ;
                invalid = false ;
            }
        }
        if(invalid)
        {
            cout <<"Move invalid!! " ;
            player-- ;
            cin.ignore() ;
            cin.get();
        }
        win = chekWin(tab);
        player++;
    }
    while(win==-1);
    board(tab);
    if(win== 1)
    {
        cout << "\aCONGRATULATION! PLAYER  " << --player << " WINS!";
    }
    else
    {
        cout << win <<"\aGAME DRAW! ";
    }
    cin.ignore();
    cin.get();
    return 0 ;
}
