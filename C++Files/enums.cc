#include <iostream>

enum Month {January, February, Marc,April,May,June,July,August,};




int main()
{
    Month thismonth = February;
    switch (thismonth) 
    {
    case January:
        std::cout<<"It is January";
        break;
    case February:
        std::cout<<"It is February";
        break;
    case Marc:
        std::cout<<"It is March";
        break;
    case April:
        std::cout<<"It is April";
        break;
    case May:
        std::cout<<"It is May";
        break;
    case June:
        std::cout<<"It is June";
        break;
    case July:
        std::cout<<"It is July";
        break; 
    case August:
        std::cout<<"It is August";
        break;
      break;
    }
    return 0;
}