#include <iostream>

int getdigit(const int number)
{
    return number % 10 + (number / 10 % 10);


}
int sumodd(const std::string card)
{
    int sum = 0;
    for(int i = card.size() - 1; i >= 0; i -= 2)
    {
        sum += card[i] - '0'; 


    }
    return sum;

}



int sumeven(const std::string card)
{
    int sum = 0;
    for(int i = card.size() - 2; i >= 0; i -= 2)
    {
        sum += getdigit((card[i] - '0') *2); 


    }
    return sum;

}


int main()
{
    std::string card;
    std::cout<<"Enter a card ";
    std::cin>>card;

    int result = sumeven(card) + sumodd(card);

    if(result % 10 == 0)
    {
        std::cout<<"It is good";

    }
    else
    {

        std::cout<<"It is bad";
    }
    
    return 0;
}