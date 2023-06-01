#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
class Member
{
    public:
        int skill;
        int speed;
        std::string name;
        int score;
        int elo;
    
    void win()
    {



    }
    void lose()
    {



    }


};

int main()
{
    Member member1;
    Member member2;
    Member member3;
    Member member4;
    Member member5;
    Member member6;
    Member member7;
    Member member8;
    Member member9;
    Member member10;
    Member member11;
    Member member12;
    Member member13;
    Member member14;
    Member member15;
    
    
    
    srand(time(NULL));
    int speed;
    int elo;
    int skill;
    int randspeed;
    
            for(int i = 1; i <= 14; i++)
            {
                randspeed = (rand() % 5) +1;
                switch (randspeed) 
                {
                    case 1 :
                        speed = 3;
                        break;
                    case 2:
                        speed = 4;
                        break;
                    case 3 :
                        speed = 5;
                        break;
                    case 4:
                        speed = 6;
                        break;
                    case 5:
                        speed = 7;
                        break;
                }   
                
                switch (i) 
                {
                    case 1:
                        member1.speed = speed;
                        break;
                    case 2:
                        member2.speed = speed;
                        break;
                    case 3:
                        member3.speed = speed;
                        break;
                    case 4:
                        member4.speed = speed;
                        break;
                    case 5:
                        member5.speed = speed;
                        break;
                    case 6:
                        member7.speed = speed;
                        break;
                    case 7:
                        member7.speed = speed;
                        break;
                    case 8:
                        member8.speed = speed;
                        break;
                    case 9:
                        member9.speed = speed;
                        break;
                    case 10:
                        member10.speed = speed;
                        break;
                    case 11:
                        member11.speed = speed;
                        break;
                    case 12:
                        member12.speed = speed;
                        break;
                    case 13:
                        member13.speed = speed;
                        break;
                    case 14:
                        member14.speed = speed;
                        break;
                    

                }
            }
    
    for(int i = 1; i <= 14; i++)    
    {   elo = (rand() % 1000) +2000;
        if(elo >= 2000 && elo <= 2300)
        {
            skill = 3;


        }
        else if(elo >= 2300 && elo <= 2500)
        {
            skill = 4;

        }
        else if(elo >= 2500 && elo <= 2700)
        {
            skill = 5;

        }
        else if(elo >= 2700 && elo <= 2900)
        {
            skill = 6;

        }
        else if(elo >= 2900 && elo <= 3000)
        {
            skill = 7;

        }  
        switch (i) 
        {
            case 1:
                member1.skill = skill;
                member1.elo = elo;
                break;
            case 2:
                member2.skill = skill;
                member2.elo = elo;
                break;
            case 3:
                member3.skill = skill;
                member3.elo = elo;
                break;
            case 4:
                member4.skill = skill;
                member4.elo = elo;
                break;
            case 5:
                member5.skill = skill;
                member5.elo = elo;
                break;
            case 6:
                member7.skill = skill;
                member6.elo = elo;
                break;
             case 7:
                member7.skill = skill;
                member7.elo = elo;
                break;
            case 8:
                member8.skill = skill;
                member8.elo = elo;
                break;
            case 9:
                member9.skill = skill;
                member9.elo = elo;
                break;
            case 10:
                member10.skill = skill;
                member10.elo = elo;
                break;
            case 11:
                member11.skill = skill;
                member11.elo = elo;
                break;
            case 12:
                member12.skill = skill;
                member12.elo = elo;
                break;
            case 13:
                member13.skill = skill;
                member13.elo = elo;
                break;
            case 14:
                member14.skill = skill;
                member14.elo = elo;
                break;
            

        }


    }
    
    std::cout<<member1.speed<<'\n';
    std::cout<<member1.skill<<'\n';
    std::cout<<member1.elo;
    return 0;
}