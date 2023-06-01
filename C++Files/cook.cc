#include <iostream>

int oventime(int x,int time)
{
    return time - x;


}
int prepare(int layer )
{
    return layer *2;


}
int total(int time,int oven,int layer)
{
    int returnTime = prepare(layer) + oventime(oven,time);
    return returnTime;
    
}

int main()
{
    int time = 50;
    int finaltime =  total(time, 20, 3);
    std::cout<<finaltime;
    return 0;
}