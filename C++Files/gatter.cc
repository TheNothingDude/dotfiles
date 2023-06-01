#include <codecvt>
#include <iostream>
#include <string>

class stove
{
    private:
        int temp = 0;
    public:
    void setTemp(int temp)
    {
        
        if(temp < 0)
        {
            this->temp = 0;


        }
        else if (temp >= 10) {
        
            this->temp = 10;
            
        
        }
        else 
        {
            this->temp=temp;
        
        }
       
    }
    int getTemp()
    {
        return temp;
    }

};


int main()
{
    std::string name;
    int size = name.length();
    stove stove1;
    stove1.setTemp(100);
    std::cout<<stove1.getTemp();
    return 0;
}