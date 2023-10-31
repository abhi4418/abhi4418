#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

void display(char arr[10][10])
{
    system("cls");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
// snaky-prevY compare with x axis
//  sub value 0 automatically dusre vale ko
//! old function
/* void updateSnake(char arr[][10] , int &snakeX , int &snakeY , int &prevX , int &prevY) {
    if(abs(snakeY - prevY)) {
        arr[snakeY][snakeX] = ' ' ;
        //means we have to change snakes location...
        //assuming snake can move only in Y for now
        //if distance in Y is less , move closer in y direction...

        if(abs(snakeY - prevY)!=0) {

        if(snakeY > prevY) {
            snakeY-- ;
            arr[snakeY][snakeX] = '~' ;
        }
        else {
            snakeY++ ;
            arr[snakeY][snakeX] = '~' ;
        }

        if(arr[prevY][prevX]=='~') {
            cout << "You are Dead" << endl ;
            return ;
        }
    }
    }

        //distance in X is short
    //move snake horizontally
  else {
     arr[snakeY][snakeX] = ' ' ;
    if (snakeX > prevX) {
        snakeX--;
        arr[snakeY][snakeX] = '~' ;
    } else {
        snakeX++;
        arr[snakeY][snakeX] = '~' ;
    }

    if (prevX == snakeX && prevY == snakeY) {
        cout << "You are Dead" << endl;
        return;
    }
}
}*/
//! new function
void updateSnake(char arr[][10], int &snakeX, int &snakeY, int &prevX, int &prevY)
{
    int comp = (abs(snakeX - prevX) < abs(snakeY - prevY)) ? 1 : 0;
    cout << "~" << snakeX << " " << snakeY << "." << comp << endl;
    // getch();
    // if (snakeX == prevX)
    //     comp = 1;
    // if (snakeY == prevY)
    //     comp = 0;
    if (comp)
    {
        arr[snakeY][snakeX] = ' ';
        // means we have to change snakes location...
        // assuming snake can move only in Y for now
        // if distance in Y is less , move closer in y direction...

        if (abs(snakeY - prevY) != 0)
        {

            if (snakeY > prevY)
            {
                snakeY--;
                arr[snakeY][snakeX] = '~';
            }
            else
            {
                snakeY++;
                arr[snakeY][snakeX] = '~';
            }
        }
        else
        {
            // cout << "you are dead";
            return;
        }
    }

    // distance in X is short
    // move snake horizontally
    else
    {
        arr[snakeY][snakeX] = ' ';
        if (snakeX > prevX)
        {
            snakeX--;
            arr[snakeY][snakeX] = '~';
        }
        else
        {
            snakeX++;
            arr[snakeY][snakeX] = '~';
        }
    }
    if (prevX == snakeX && prevY == snakeY)
    {
        // cout << "You are dead" << endl;
        return;
    }
}
int main()
{
    char arr[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == 0 || i == 9)
            {
                arr[i][j] = '-';
            }

            else if (j == 0 || j == 9)
            {
                arr[i][j] = '|';
            }
            else
            {
                arr[i][j] = ' ';
            }
        }
    }

    int prevX = 1, prevY = 1;
    arr[prevY][prevX] = '>';

    int snakeX = 6, snakeY = 1;
    arr[snakeY][snakeX] = '~';

    // display(arr) ;

    while (true)
    {
        // cout << prevY << " " << prevX << endl;
        int goalx = 7, goaly = 7;
        arr[goaly][goalx] = '@';
        char ch;
        cin >> ch;

        if (ch == 'S' || ch == 's')
        {
            if (prevY < 8)
            {
                arr[prevY][prevX] = ' ';
                prevY++;

                if (prevX == goalx && prevY == goaly)
                {
                    cout << "You WIN" << endl;
                    break;
                }

                if (prevX == snakeX && prevY == snakeY)
                {
                    cout << "You are dead";
                    break;
                }
                else
                {
                    arr[prevY][prevX] = 'v';
                    updateSnake(arr, snakeX, snakeY, prevX, prevY);
                    // updateSnake(arr, snakeX, snakeY, prevX, prevY, goalx, goaly);
                }
            }
            else
                updateSnake(arr, snakeX, snakeY, prevX, prevY);
            if (prevX == snakeX && prevY == snakeY)
            {
                cout << "You are Dead";
                return 0;
            }
        }

        else if (ch == 'W' || ch == 'w')
        {
            if (prevY > 1)
            {
                arr[prevY][prevX] = ' ';
                prevY--;
                if (prevX == goalx && prevY == goaly)
                {
                    cout << "You WIN" << endl;
                    break;
                }
                if (prevX == snakeX && prevY == snakeY)
                {
                    cout << "u are dead";
                    break;
                }
                else
                {
                    arr[prevY][prevX] = '^';
                    updateSnake(arr, snakeX, snakeY, prevX, prevY);
                    // updateSnake(arr, snakeX, snakeY, prevX, prevY, goalx, goaly);
                }
            }
            else
                updateSnake(arr, snakeX, snakeY, prevX, prevY);
            if (prevX == snakeX && prevY == snakeY)
            {
                cout << "You are Dead";
                return 0;
            }
        }

        else if (ch == 'A' || ch == 'a')
        {
            if (prevX > 1)
            {
                arr[prevY][prevX] = ' ';
                prevX--;
                if (prevX == goalx && prevY == goaly)
                {
                    cout << "You WIN" << endl;
                    break;
                }
                if (prevX == snakeX && prevY == snakeY)
                {
                    cout << "You are dead";
                    break;
                }
                else
                {
                    arr[prevY][prevX] = '<';
                    updateSnake(arr, snakeX, snakeY, prevX, prevY);
                    // updateSnake(arr, snakeX, snakeY, prevX, prevY, goalx, goaly);
                }
            }
            else
                updateSnake(arr, snakeX, snakeY, prevX, prevY);
            if (prevX == snakeX && prevY == snakeY)
            {
                cout << "You are Dead";
                return 0;
            }
        }

        else if (ch == 'D' || ch == 'd')
        {
            if (prevX < 8)
            {
                arr[prevY][prevX] = ' ';
                prevX++;
                if (prevX == goalx && prevY == goaly)
                {
                    cout << "You WIN" << endl;
                    break;
                }
                if (prevX == snakeX && prevY == snakeY)
                {
                    cout << "You are dead";
                    break;
                }
                else
                {
                    arr[prevY][prevX] = '>';
                    updateSnake(arr, snakeX, snakeY, prevX, prevY);
                    // updateSnake(arr, snakeX, snakeY, prevX, prevY, goalx, goaly);
                }
            }
            else
                updateSnake(arr, snakeX, snakeY, prevX, prevY);
            if (prevX == snakeX && prevY == snakeY)
            {
                cout << "You are Dead";
                return 0;
            }
        }

        else if (ch == 'E' || ch == 'e')
        {
            cout << "exited" << endl;
            break;
        }
        display(arr);
        cout << ">" << prevY << " " << prevX << endl;
    }
}
/*
this
code
is
written
by
Abhimanyu
Kumar
Jha
And
Abhishek
Gupta*/
