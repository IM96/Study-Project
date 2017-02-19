#include <stdio.h>
#define MAX 100

void convert(char prefix[], char postfix[]);
int find(char str[]);
char* substr(char src[], int offset, int len, char dest[]);

int main(){
    char prefix[MAX];
    char postfix[MAX];
    char coba[100]="*+ABC";
//    printf("enter the prefix string\n");
//    scanf(" %s", prefix);
    convert(coba, postfix);
    printf("%s\n", postfix);

    return 0;
}

//algo ::
//1.If the prefix string is a single variable, it is its own postfix equivalent
//2.Let op be the first operator of the prefix string
//3.Find the first operand, opnd1 of the string.Convert it to postfix and call it post1.
//4.Find the second operand, opnd2, of the string.Convert it to postfix and cal it post2.
//5.Concatenate post1, post2, and op.
void convert(char prefix[], char postfix[])
{
    char opnd1[MAX];
    char opnd2[MAX];
    char post1[MAX];
    char post2[MAX];
    char temp[MAX];
    char op[2];
    int length;
    int i,j,m,n;

    //prefix string is single variable
    if((length=strlen(prefix))==1){
        if(isalpha(prefix[0])){
            postfix[0]=prefix[0];
            postfix[1]='\0';
            return;
        }

        printf("illegal prefix string\n");
        exit(1);
    }

    //prefix string is longer
    op[0]=prefix[0];
    op[1]='\0';
    substr(prefix,1,length-1,temp);
    m=find(temp);
    substr(prefix, m+1, length-m-1, temp);
    n=find(temp);

    if((op[0]!='+' && op[0]!='-' && op[0]!='*' && op[0]!='/') || (m==0) || (n==0) || (m+n+1!=length)){
        printf("illegal prefix string\n");
        exit(1);
    }
    substr(prefix, 1, m, opnd1);
    substr(prefix, m+1, n, opnd2);

    convert(opnd1, post1);
    convert(opnd2, post2);
    strcat(post1, post2);
    strcat(post1, op);

    substr(post1, 0, length, postfix);
}

int find(char str[])
{
    char temp[MAX];
    int length;
    int i,j,m,n;

    if((length=strlen(str))==0) return 0;

    //first character is a letter
    if(isalpha(str[0])!=0)      return 1;

    //otherwise find the first operand
    if(strlen(str)<2)    return 0;

    substr(str, 1, length-1, temp);
    m=find(temp);

    //no valid prefi operand or no second operand
    if(m==0 || strlen(str)==m)  return 0;

    substr(str, m+1, length-m-1, temp);
    n=find(temp);

    if(n==0)    return 0;

    return (m+n+1);
}

char* substr(char src[], int offset, int len, char dest[])
{
    int i;
    for(i = 0; i < len && src[offset + i] != '\0'; i++){
        dest[i] = src[i + offset];
    }
    dest[i] = '\0';

    return dest;
}

