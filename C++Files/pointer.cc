#include <iostream>

int main()
{
    std::string name = "Áron";
    std::string *pName = &name;
    std::string pizzas[5] = {"Pizza1","Pizza2","Pizza3","Pizza4","Pizza5"};
    std::string *pPizzas = pizzas;
    std::cout<<*pName<<'\n';
    std::cout<<pPizzas;
    
    return 0;
}