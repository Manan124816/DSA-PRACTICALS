#include<iostream>
#include<stack>
using namespace std;
int prece(char c)
{

    if(c=='^')
    {
        return 3;
    }
        if(c=='*'|| c=='/')
    {
        return 2;
    }
    if(c=='+'||c=='-')
    {
        return 1;
    }
    else{
        return -1;
    }
}
void preTopost(string str)
{
    stack<char> st;
  string result;
  for(int i=0;i<str.length();i++)
  {
      char c=str[i];
      if((str[i]>='a' && str[i]<='z' )||( str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9'))
      {

          result=result+c;
      }
      else if(str[i]=='(')

      {
          st.push(c);
      }
      else if(str[i]==')')
      {

          while(st.top()!='(')
          {

              result=result + st.top();
              st.pop();
          }
          st.pop();
      }
      else{
            while(!st.empty() && prece(str[i])<=prece(st.top()))
            {

                result=result+st.top();
                st.pop();
            }
            st.push(c);

      }
  }
  while(!st.empty())
  {
    result=result+st.top();
    st.pop();
  }
  cout<<result;

}
int main()
{

    string str;
    cout<<"enter here::::";
    getline(cin,str);
    preTopost(str);
}
