#include <bits/stdc++.h>
#include <windows.h>
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

void updateSnake(char arr[][10] , int &snakex , int &snakey , int &prevx , int &prevy) {
    if(abs(snakey - prevy)) {
        arr[snakey][snakex] = ' ' ;
        //means we have to change snakes location...
        //assuming snake can move only in Y for now  
        //if distance in Y is less , move closer in y direction...
        
        if(abs(snakey - prevy)!=0) {
        
        if(snakey > prevy) {
            snakey-- ;
            arr[snakey][snakex] = '~' ;
        }
        else {
            snakey++ ;
            arr[snakey][snakex] = '~' ;
        }
        
        if(arr[prevy][prevx]=='~') {
            cout << "You are Dead" << endl ;
            return ;
        }
    }
    }
    
        //distance in X is short 
    //move snake horizontally 
  else {
     arr[snakey][snakex] = ' ' ;
    if (snakex > prevx) {
        snakex--;
    } else {
        snakex++;
    }

    if (prevx == snakex && prevy == snakey) {
        cout << "You are Dead" << endl;
        return;
    } else {
        arr[snakey][snakex] = '~';
    }
}

}

int main()
{
    char arr[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(i==0 || i==9) {
                arr[i][j]='-' ;
            }
            
            else if(j==0 || j==9) {
                arr[i][j] = '|' ;
            }
            else {
                arr[i][j]= ' ' ;
            }
        }
    }

    int prevx = 1, prevy = 1;
    arr[prevy][prevx] = '>';

    int snakex = 6, snakey = 1;
    arr[snakey][snakex] = '~';

    // display(arr) ;
    
    while (true)
    {
        int goalx = 7 , goaly = 7 ;
        arr[goaly][goalx] = '@' ;
        char ch;
        cin >> ch;

        if (ch == 'S' || ch == 's')
        {
            arr[prevy][prevx] = ' ';
            if (prevy < 8)
            {
                prevy++;
                
                if(prevx == goalx && prevy==goaly) {
                    cout << "You WIN" << endl ;
                    break ;
                }
                
                if (prevx == snakex && prevy == snakey)
                {
                    cout << "You are dead";
                    break;
                }
                else {
                    arr[prevy][prevx] = 'v';
                    updateSnake(arr ,snakex , snakey , prevx , prevy) ;
                    // updateSnake(arr, snakex, snakey, prevx, prevy, goalx, goaly);

                }
            }
            
        }

        else if (ch == 'W' || ch == 'w')
        {
            arr[prevy][prevx] = ' ';
            if (prevy > 1)
            {
                prevy--;
                if(prevx == goalx && prevy==goaly) {
                    cout << "You WIN" << endl ;
                    break ;
                }
                if (prevx == snakex && prevy == snakey)
                {
                    cout << "You are dead";
                    break;
                }
                else {
                    arr[prevy][prevx] = '^';
                    updateSnake(arr ,snakex , snakey , prevx , prevy) ;
                    // updateSnake(arr, snakex, snakey, prevx, prevy, goalx, goaly);

                }
            }
        }

        else if (ch == 'A' || ch == 'a')
        {
            arr[prevy][prevx] = ' ';
            if (prevx > 1)
            {
                prevx--;
                if(prevx == goalx && prevy==goaly) {
                    cout << "You WIN" << endl ;
                    break ;
                }
                if (prevx == snakex && prevy == snakey)
                {
                    cout << "You are dead";
                    break;
                }
                else {
                    arr[prevy][prevx] = '<';
                    updateSnake(arr ,snakex , snakey , prevx , prevy) ;
                    // updateSnake(arr, snakex, snakey, prevx, prevy, goalx, goaly);

                }
                
            }
        }

        else if (ch == 'D' || ch == 'd')
        {
            arr[prevy][prevx] = ' ';
            if (prevx < 8)
            {
                prevx++;
                if(prevx == goalx && prevy==goaly) {
                    cout << "You WIN" << endl ;
                    break ;
                }
                if (prevx == snakex && prevy == snakey)
                {
                    cout << "You are dead";
                    break;
                }
                else {
                     arr[prevy][prevx] = '>';
                    updateSnake(arr ,snakex , snakey , prevx , prevy) ;
                    // updateSnake(arr, snakex, snakey, prevx, prevy, goalx, goaly);

                }
               
            }
        }

        else if (ch == 'E' || ch == 'e')
        {
            cout << "exited" << endl;
            break;
        }

        display(arr);
    }
}

