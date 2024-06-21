#include <iostream>
#include <random>
using namespace std;

int main()
{
    random_device rd;
    int g_no, hint,count=0;

    // Choose a random number generator
    mt19937 gen(rd());

    // Define the range
    uniform_int_distribution<> dis(1, 100);

    // Generate a random number in the range [1, 100]
    int random_number = dis(gen);

    cout<<"Guess the number between 1 and 100 \n...";
    cin>>g_no;
    while(g_no!=random_number)
    {
        cout<<"Sorry, Wrong Guess!!"<<endl;
        if(g_no>random_number)
            cout<<"Hint: The actual number is smaller!"<<endl;
        else
            cout<<"Hint: The actual number is larger!"<<endl;
        cin>>g_no;
        ++count;
        if(count==10)
            break;
    }
    if(g_no==random_number)
    {
        cout<<"Hurray!!! You guessed the number, YOU WIN!!"<<endl;
        cout<<"You took "<<count<<" steps to guess the number"<<endl; 
    }
    else
        cout<<"Game Over!!! YOU LOSE!!"<<endl;
    return 0;   
}