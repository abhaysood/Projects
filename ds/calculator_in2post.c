    #include<stdio.h>
    #include<string.h>
    #define MAX 100
    char stack[MAX];
    char top=-1;
    void push(char val)
    {
            top++;
            stack[top]=val;
    }
    char pop()
    {
            char temp;
            temp=stack[top];
            top--;
            return temp;
    }
    int check_symbol(char symbol)
    {
    int a;
    a=toascii(symbol);
    if(a=='+'||a=='-'||a=='*'||symbol=='/')
    return 1;
    else
    return 0;//means a variable has been read
    }
    int prec(char symbol)
    {
    int p;
    int c;
    c=symbol;
            if(c=='+'||c=='-')
            p=2;
            else if(c=='*'||c=='/')
            p=3;    
    	return p;
    }
    void convert(char infix[],char postfix[])
    {
            int count;
            int count1=0;
            stack[++top]='#';
            char x;
            char symbol;
            for(count=0;count<strlen(infix);count++)
            {
           
                    symbol=infix[count];
                    if(check_symbol(symbol)==0)//variable read
                    {
                            postfix[count1]=symbol;
                            count1++;
                    }
                    else
                    {
                          //  if(symbol=='(')
                           // {
                           // push(symbol);
                           // }
                           // else if(symbol==')')
                           // {      
                            //                while(stack[top]!='(')
                             //               {
                              //              postfix[count1]=pop();
                                //            count1++;
                                  //          }
                                    //        x=pop();//discard pop (
                           // }      
                            //else
                            //{
                                    if(prec(symbol)>prec(stack[top]))
                                    push(symbol);
                                    else
                                            {
                                                    while(prec(symbol)<=prec(stack[top]))
                                                    {
                                                    postfix[count1]=pop();
                                                    count1++;
                                                    }
                                            push(symbol);
                                            }
                            //}
                    }      
            }
            while(stack[top]!='#')
            {
            postfix[count1]=pop();
            count1++;
            }
            postfix[count1]='\0';//null terminate string.
    }
     
int cal(char postfix[])
    {
    char symbol;
    int count=0;
    int m,n;
    int z;
    int eval;
    for(count=0;postfix[count]!='\0';count++)
    {
            symbol=postfix[count];
     
            if(check_symbol(symbol)==0)
            {
            push(symbol);
            }
            else
            {
                    if(postfix[count]=='+'||postfix[count]=='-'||postfix[count]=='*'||postfix[count]=='/')
                    {
                    m=pop()-'0';
                   
                    n=pop()-'0';
                   
                            switch(symbol)
                            {
                            case '+':
                            eval=n+m;
                            push(eval+'0');
                            break;
                            case '-':
                            eval=n-m;
                            push(eval+'0');
     
                            break;
                            case '*':
                            eval=n*m;
                            push(eval+'0');
     
                            break;
                            case '/':
                            eval=n/m;
                            push(eval+'0');
                            break;
                            }
                    }
            }
    }
    z=pop()-'0';
    return z;
    }
     
    int main()
    {
    top=-1;
    char infix[MAX];
    char postfix[MAX];
    int result;
    printf("ENTER A VALID INFIX OPERATION:\n");
    gets(infix);
    convert(infix,postfix);
    printf("THE POSTFIX EXPRESSION:\n");
    puts(postfix);
    result=cal(postfix);
    printf("THE RESULT:\n");
    printf("%d\n",result);
    return 0;
    }

