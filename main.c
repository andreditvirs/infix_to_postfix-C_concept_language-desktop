#define SIZE 50
#include <ctype.h>


char s[SIZE];
int top=0;

push(char elem)
{
    top++;
    s[top]=elem;
}

char pop(){
    return(s[top--]);

}

int pr(char elem)
{
    switch(elem)
    {
    case '(' : return 1;
    case '+' : case '-' : return 2;
    case '*' : case '/' : return 3;
    }
}

main()
{
    char infix[50],postfix[50],ch,elem;
    int i=0,k=0;
    printf("\n\nMembaca Infix : ");
    scanf("%s",infix);
    while(infix[i] != '\0')
    {
        ch=infix[i];
        if(ch=='('){push(ch);}
        else if(isalnum(ch)){postfix[k]=ch;k++;}
        else if(ch==')'){while(s[top]!='('){postfix[k]=pop();k++;}elem=pop();}
        else{while(pr(s[top])>=pr(ch)){postfix[k]=pop();k++;}push(ch);}
        i++;
    }

    while(s[top]!='\0'){postfix[k++]=pop();}
        postfix[k]='\0';
        printf("\nJadi %s menjadi %s",infix,postfix);


}
