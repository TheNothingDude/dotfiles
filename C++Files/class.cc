#include <iostream>
#include <string>

class city
{
    public:
        int population;
        std::string name;
        bool sunny;
        std::string country;
        std::string mayor;
        void build()
        {
            std::cout<<"You build a house";

        }

        void loan()
        {
            std::cout<<"You get a loan";

        }


};





int main()
{
    city city1;
    city1.name = "London";
    city1.mayor = "Boris Jonshon";
    city1.population = 20000000;
    city1.sunny = true;
    
    std::cout<<"The city's name is "<<city1.name<<'\n';
    std::cout<<"The mayor is "<<city1.mayor<<'\n';
    city1.build();
    return 0;
}