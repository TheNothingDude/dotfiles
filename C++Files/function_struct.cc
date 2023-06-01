#include <codecvt>
#include <iostream>
#include <string>

struct animals
{
    std::string name;
    int age;
    std::string origin;



};



void printAnimal(animals animal1)
{
    std::cout<<animal1.name<<'\n';
    std::cout<<animal1.age<<'\n';
    std::cout<<animal1.origin<<'\n';


}
void changeOrigin(animals &animal,std::string origin)
{
    animal.origin = origin;


}

int main()
{

    animals goat;
    goat.name = "János";
    goat.age = 5; 
    goat.origin = "USA"; 

    changeOrigin(goat, "Uk");
    printAnimal(goat);
    return 0;
}