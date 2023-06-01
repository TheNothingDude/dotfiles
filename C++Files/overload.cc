#include <iostream>
#include <string>

class hamburger
{
    public:
        std::string meat;
        std::string meat2;
    hamburger(std::string x)
    {
        meat = x;


    }
    hamburger(std::string x,std::string y)
    {
        meat = x;
        meat2 = y;


    }


};


int main()
{
    hamburger burger1("Beef");
    hamburger burger2("Beef","turkey");
    
    std::cout<<burger2.meat;
    return 0;
}