#include <iostream>

using namespace std;

class in_to_post
{
    public:
        int top;
        string output="                              ";
        int size = 20;
        char arr [20];


    bool is_full()
    {
        if(top==size-1)
        {
            return true;
        }
        return false;
    }

    bool is_empty()
    {
        if (top==-1)
        {
            return true;
        }
        return false;
    }

    void push(char data)
    {
        if (is_full())
        {
            cout<<"is full"<<endl;
            return;
        }
        cout<<"pusihing "<<data<<endl;   
        top++;
        arr[top]=data;
        return;
    }

    char pop()
    {
        if (is_empty())
        {
            cout<<"EMPTY"<<endl;
            return 'f';
        }
        else
        {
            char data = arr[top];
            top--;
            cout<<"popping "<<data<<endl;   
            return data;
        }
        
    }

    bool is_operator(char s)
    {
        if (s=='*'||s=='/' ||s=='+'||s=='-'||s=='^'||s=='$'||s==')'|| s=='(')
        {
            return true;
        }
        return false;
    }

    int precedence(char s)
    {
        if (s=='*'||s=='/')
        {
            return 2;
        }
        else if(s=='+'||s=='-')
        {
            return 1;
        }
        else if(s=='^'||s=='$')
        {
            return 3;
        }
        else
        {
            return -1;
        }
    }


    string convert (string imput)
    {
        top=-1;
        int j=0;
        for (int i = 0; i < imput.length();)
        {
            if (!is_operator(imput[i]))
            {
                output[j]=imput[i];
                i++;
                j++;
            }
            else
            {
                if (imput[i]=='(')
                {
                    push(imput[i]);
                    i++;
                }
                else if(imput[i]==')')
                {
                    //keep on popping till (
                    while (true)
                    {
                        char temp=arr[top];
                        if (temp=='(')
                        {
                            pop();
                            break;
                        }
                        
                        output[j]=pop();
                        j++;
                    }
                    i++;
                    
                }
                else if(precedence(imput[i])>precedence(arr[top]))
                {
                    push(imput[i]);
                    i++;
                }
                else if (precedence(imput[i])<=precedence(arr[top]))
                {

                    output[j]=pop();
                    j++;
                    push(imput[i]);
                    i++;
                }            
                
            }    
        }

        //empty out
        while (!is_empty())
        {
            output[j]=pop();
            j++;
        }
        
        return output;
    }


};

int main(int argc, char const *argv[])
{
    in_to_post e1;
    string i;
    getline(cin,i);
    cout<<e1.convert(i)<<endl;
    return 0;
}
