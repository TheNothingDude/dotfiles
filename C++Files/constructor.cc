#include <iostream>
#include <string>

class school
{
    public:
        std::string name;
        int rating;
        std::string princible;
        int floors;
    school(std::string x, int z, std::string y, int f)
    {
        name = x;
        rating = z;
        floors = f;
        princible = y;


    }



};




int main()
{
    school school1("Bajza", 10, "Spongebob", 2 );
    std::cout<<school1.name<<'\n';
    std::cout<<school1.princible;
    
    return  0;
}