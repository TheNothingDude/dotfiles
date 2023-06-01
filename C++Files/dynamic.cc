#include <iostream>

int main()
{
    char *pGrades = nullptr;
    int size;
    std::cout<<"How big do you want your array of grades: ";
    std::cin>>size;
    
    pGrades = new char[size];
    
    for(int i = 0; i < size; i++)
    {
        std::cout<<"Grade "<<i +1<<": ";
        std::cin>>pGrades[i];


    }
    for(int i = 0; i < size; i++)
    {
        std::cout<<pGrades[i]<<" ";

    }   
    delete[] pGrades;
    return 0;
}