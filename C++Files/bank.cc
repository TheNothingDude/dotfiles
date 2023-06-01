#include <iostream>

int whithdraw(int balance)
{
    int tempbalance;
    int money;
    std::cout<<"Money: $";
    std::cin>>money;
    
    tempbalance = balance - money;
    
    if(tempbalance < 0)
    {
        std::cout<<"You dont have enough money for that\n";
        std::cout<<"You balance is "<<"$"<<balance;
        return balance;
        

    }
    else
    {

        balance = tempbalance;
        std::cout<<"You balance is "<<"$"<<balance<<'\n';
        return balance;
         
    }
   
}
int deposit(int balance)
{
    int money;
    std::cout<<"Money: $";
    std::cin>>money;
    balance = balance + money;
    std::cout<<"Your balance is "<<"$"<<balance<<'\n';
    return balance;

}
void check(int balance)
{
    std::cout<<"$"<<balance;


}


int main()
{
    int balance = 0;
    std::string chioce;
    
    bool exit = false;
    while (exit != true)
    {
        std::cout<<"What do you want to do (deposit, check, withdraw, exit): ";
        std::cin>>chioce;
        
        if(chioce == "deposit")
        {
                balance = deposit(balance);


        }
        else if(chioce == "whithdraw")
        {
                balance = whithdraw(balance);



        }
        else if(chioce == "check")
        {
            check(balance);
    
        }
        else if(chioce == "exit")
        {
            exit = true;



        }
    
    
    }
    


    
    return 0;
}