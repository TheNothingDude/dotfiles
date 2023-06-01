#include <iostream>

int main()
{
    std::string foods[] = {"Hamburger", "Pizza", "Pasta"};
    for(std::string food :  foods)
    {
        std::cout<<food<<'\n';

    }
    return 0;
}