#include<iostream>
#include<stack>
#include<stdexcept>
using  std::stack;
using  std::cout;
using  std::endl;
using  std::runtime_error;
//using namespace std::cout;
class my_stack
{
public:
    stack<int> stackData;
    stack<int> stackMin;

    void push(int newNum)
    {
        if (stackMin.empty())
        {
            stackMin.push(newNum);
        }
        else if(newNum<= this->getMin())
        {
            this->stackMin.push(newNum);
        }
        this->stackData.push(newNum);
    }

    int getMin()
    {
        if(this->stackMin.empty())
        {
            throw runtime_error("your Min stack is empty");
        }
        return stackMin.top();
    }

};

int main(int argc, char *argv[])
{
    my_stack stack_1;
    stack_1.push(1);
    stack_1.push(4);
    //stack_1.stackData.push(1);
    std::cout<< stack_1.getMin()<<std::endl;
}
