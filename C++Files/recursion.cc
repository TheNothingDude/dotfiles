#include <iostream>
int factorial2(int number)
{
    int result = 1;
    for(int i = 1; i <= number; i++)
    {
        result = result * i;
        
    }
    return result;

}

int factorial(int number)
{
    if(number > 1)
    {
        return number * factorial(number - 1);

    }
    else
    {
        return 1;
    }

}



int main()
{
    std::cout<<factorial2(10);
    
    
    
    
    
    return 0;
}