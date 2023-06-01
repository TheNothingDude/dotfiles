#include <iostream>
struct city
{
    std::string name;
    bool rain;
    int population;
};



int main()
{
    city city1;
    city1.name = "New York";
    city1.population = 100000;
    city1.rain = true;
    
    std::cout<<city1.name;
    return 0;
}