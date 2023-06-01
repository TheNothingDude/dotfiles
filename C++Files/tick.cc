#include <iostream>
#include <ctime>

void drawboard(char *spaces)
{
    std::cout<<'\n';
    std::cout<<"     |     |     "<<'\n';
    std::cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<< "  |  " <<spaces[2]<< "  "<<'\n';
    std::cout<<"_____|_____|_____"<<'\n';
    std::cout<<"     |     |     "<<'\n';
    std::cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<< "  |  " <<spaces[5]<< "  "<<'\n';
    std::cout<<"_____|_____|_____"<<'\n';
    std::cout<<"     |     |     "<<'\n';
    std::cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<< "  |  " <<spaces[8]<< "  "<<'\n';
    std::cout<<'\n';
}
void playermove(char *spaces, char player)
{
    int number;
    do{
        std::cout<<"Enter a spot(1-9): ";
        std::cin>>number;
        number = number - 1;
        if(spaces[number] == ' ')
        {
            spaces[number] = player;
            break;

        }


    }while(!number > 0 || !number < 8);


}
void comp(char *spaces, char comp)
{
    srand(time(NULL));
    int number;
    while(true)
    {
        number = rand() % 9;
        if(spaces[number] == ' ')
        {
            spaces[number] = comp;
            break;
        }


    }

}
bool checkwin(char *spaces, char player,char comp)
{
    if(spaces[0] == spaces[1] && spaces[1] == spaces[2] && spaces[0] != ' ')
    {
        if(spaces[0] == player)
        {
            std::cout<<"you won"<<'\n';


        }
        else
        {
            std::cout<<"You lost"<<'\n';


        }

        
    }
    else if(spaces[3] == spaces[4] && spaces[4] == spaces[5] && spaces[3] != ' ')
    {
        if(spaces[3] == player)
        {
            std::cout<<"you won"<<'\n';


        }
        else
        {
            std::cout<<"You lost"<<'\n';


        }

        
    }
    else if(spaces[6] == spaces[7] && spaces[7] == spaces[8] && spaces[6] != ' ')
    {
        if(spaces[6] == player)
        {
            std::cout<<"you won"<<'\n';


        }
        else
        {
            std::cout<<"You lost"<<'\n';


        }

        
    }
    else if(spaces[6] == spaces[4] && spaces[4] == spaces[2] && spaces[6] != ' ')
    {
        if(spaces[6] == player)
        {
            std::cout<<"you won"<<'\n';


        }
        else
        {
            std::cout<<"You lost"<<'\n';


        }

        
    }
    else if(spaces[8] == spaces[4] && spaces[4] == spaces[0] && spaces[8] != ' ')
    {
        if(spaces[8] == player)
        {
            std::cout<<"you won"<<'\n';


        }
        else
        {
            std::cout<<"You lost"<<'\n';


        }

        
    }
    else if(spaces[0] == spaces[3] && spaces[3] == spaces[6] && spaces[0] != ' ')
    {
        if(spaces[0] == player)
        {
            std::cout<<"you won"<<'\n';


        }
        else
        {
            std::cout<<"You lost"<<'\n';


        }

        
    }
    else if(spaces[1] == spaces[4] && spaces[4] == spaces[7] && spaces[1] != ' ')
    {
        if(spaces[1] == player)
        {
            std::cout<<"you won"<<'\n';


        }
        else
        {
            std::cout<<"You lost"<<'\n';


        }

        
    }
    else if(spaces[2] == spaces[5] && spaces[5] == spaces[8] && spaces[2] != ' ')
    {
        if(spaces[2] == player)
        {
            std::cout<<"you won"<<'\n';


        }
        else
        {
            std::cout<<"You lost"<<'\n';


        }

        
    }
    else
    {

        return false;
    }
    return true;
}
bool checktie(char *spaces)
{
    for(int i = 0; i < 9; i++)
    {
        if(spaces[i] == ' ')
        {
            return false;


        }

    }
    std::cout<<"It is a draw"<<'\n';
    return true;



}



int main()
{
    char spaces[9] = {' ', ' ',' ', ' ',' ', ' ',' ', ' ',' '};
    char player = 'x';
    char computer = 'O';
    bool running = true;

    drawboard(spaces);
    while(running == true)
    {
        playermove(spaces, player);
        drawboard(spaces);
        if(checkwin(spaces, player,computer) == true)
        {
            running = false;
            break;

        }
        else if(checktie(spaces) == true)
        {
            running = false;
            break;


        }
        comp(spaces, computer);
        if(checkwin(spaces, player,computer) == true)
        {
            running = false;
            break;

        }
        else if(checktie(spaces) == true)
        {
            running = false;
            break;


        }
        drawboard(spaces);
        
    }
    return 0;
}