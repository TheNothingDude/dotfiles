#include <iostream>

int main()
{
    int year;
    std::cout<<"Year: ";
    std::cin>>year;
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            
            if(year % 400 ==0)
            {

                std::cout<<"It is a leap";

            }
            else 
            {
                std::cout<<"Not a leap";

            }  
            
            
        }
     
        else
        {

            std::cout<<"It is a leap";
        }
        
        
    
    
    }
    
    
    
    
    
    
    return 0;
}