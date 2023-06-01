#include <iostream>

int main()
{
    std::string questions[] = {"What happened in 1991: ","What is the predesessor of c++: ", "What happened in 1945: "};
    std::string options[][3] = {{"A. WW1 ended", "B. WW2 ended", "C. Ussr collapesed"}, {"A. C", "B. C--", "C. B++"}, {"A.WW1 ended" , "B. The war in europe ended", "C. WW2 ended"}};
    char answers[] = {'C', 'A', 'C'}; 
    char userinput[3];
    int score = 0;
    for(int i = 0; i < 3; i++)
    {
        std::cout<<questions[i]<<'\n';
        for(int j = 0; j < 3; j++)
        {
            std::cout<<options[i][j]<<'\n';


        }
        std::cout<<"Answer: ";
        std::cin>>userinput[i];

    }
    if(userinput[0] == answers[0])
    {
        std::cout<<"Correct"<<'\n';
        score++;

    }
    else if(userinput[0] != 'C')
    {
        std::cout<<"Wrong"<<'\n';


    }
    if(userinput[1] == answers[1])
    {
        std::cout<<"Correct"<<'\n';
        score++;

    }
    else
    {
        std::cout<<"Wrong"<<'\n';


    }
    if(userinput[2] == answers[2])
    {
        std::cout<<"Correct"<<'\n';
        score++;

    }
    else
    {
        std::cout<<"Wrong"<<'\n';


    }
    std::cout<<'\n'<<"Correct: "<<score / ((double)sizeof(questions)/(double)sizeof(questions[0])) *100<< "%";
    return 0;
}