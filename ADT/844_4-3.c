/*
Date:2019-11-30
*/
//page4 01

bool correct(char exp[],bool tag)
{
    int len = strlen(exp);
    int i;
    InitStack(S);
    for(i=0;i<len;i++)
    {
        if((exp[i] == "(") || (exp[i]=="[") || (exp[i]=="{"))
            Push(S,exp[i]);
        if((exp[i] == ")") || (exp[i]=="]") || (exp[i]=="}"))
        {
            rec = convert(get_Top(S));
            if(exp[i] != rec)
                return false;
            else
                Pop(S);
        }

    }
    if(StackEmpty(S))
        return true;
    else
        return false;e
}

//02  tag = 0;表示出队. tag = 1;表示入队.


tag = 0;
SeQueue Q;
InitQueue(Q);
int EnQueue(SeQueue Q,int x)
{
    if(Q.rear == Q.front && tag==1)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1)%maxsize;
    return true;
}

int DeQueue(SeQueue Q,int x)
{
    if(Q.rear == Q.front && tag==0)
        return false;

    x = Q.data[Q.front];
    Q.front = (Q.front + 1)%maxsize;
    return true;
}

//03
int Palindrome_Test()
{
    InitStack(S);
    InitQueue(Q);

    while((c = getchar()) != "@")
    {
        Push(S,c);
        EnQueue(Q,c);
    }

    while(!StackEmpty(S))
    {
        Pop(S,a);
        DeQueue(Q,b);
        if(a != b)
            return false;
    }

    return true;
}

