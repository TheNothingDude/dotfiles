#include <iostream>
#include <string>

class Team
{
    public:
        int point;
        std::string name;
        int strength = 5;


};
class Member : public Team
{
    public:
    void leave()
    {
        std::cout<<name<<" left the team";


    }




};



int main()
{

    Member member1;
    member1.name = "Magnus";

    std::cout<<member1.name<<'\n';
    member1.leave();
    
    
    
    
    return 0;
}