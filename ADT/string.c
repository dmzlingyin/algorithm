
/*
Author:Lingyin
Date:2019-06-17
ADT String
*/

/***********************************串的抽象数据类型的定义********************************/

//生成一个值等于chars的串T
StrAssign(&T,chars)；

//复制串S到T
StrCopy(&T,S);

//判断串是否为空
StrEmpty(S);

//比较两个串
StrCompare(S,T);

//返回串的长度
StrLength(S);

//将串清空
ClearString(S);

//将两个串拼接成一个串
Concat(&T,S1,S2);

//用Sub 返回串S 的第pos个字符起长度为len的字串
SubString(&Sub,S,pos,len);

//若主串S中存在和串T值相同的字串，则返回它在字串中的第pos个字符字后第一次出现的位置，否则返回0
Index(S,T,pos);

//用v替换主串S中出现的所有与T相等的不重叠的字串
Replace(%S,T,V);

//
/*********************************灰灰考研代码***************************************/

//定长
typedef struct
{
    char str[maxSize + 1];
    int length;

}Str;

//变长
typedef struct{
    char *ch;
    int length;
}Str;

//获取串的长度
int strLength(Str str)
{
    return str.length;
}

//串的清空操作
int clearString(Str str)
{
    if(str.ch)
    {
        free(str.ch);
        str.ch = NULL;
    }
    str.length = 0;
    return 1;
}

//串的赋值操作
int strAssign(Str &str,char *ch)
{
    if(str.ch)
        free(str.ch);

    int length = 0;
    char *c = ch;
    //计算ch的长度
    while(*c)
    {
        ++length;
        ++c;
    }

    //赋值为空串
    if(length == 0)
    {
        str.ch = NULL;
        str.length = 0;
        return 1;
    }
    else
    {
        //申请内存空间
        str.ch = (char *)malloc(sizeof(char) * (length + 1));
        if(str.ch == NULL)
            return 0;
        else
        {
            c = ch;
            for(int i = 0;i < length;i++,c++)
                str.ch[i] = *c;
            str.length = length;
            return 1;
        }
    }
}

int strCompare(Str s1,Str s2)
{
    for(int i = 0;i < s1.length && i < s2.length;i++)
    {
        if(s1.ch[i] != s2.ch[i])
            return s1.ch[i] - s2.ch[i];
    return s1.length - s2.length;
    }

}

//求子串操作
int getSubString(Str &subStr,str str,int pos,int len)
{
    //判断pos和len是否合法
    if(pos < 0 || pos >= str.length || len < 0 || len > str.length - pos)
        return 0;

    //清空字串指针
    if(subStr.ch)
    {
        subStr.ch = NULL;
        subStr.length = 0;
    }

    if(len == 0)
    {
        subStr.ch = NULL;
        subStr.length = 0;
        return 1;
    }
    else
    {
        subStr.ch = (char *)malloc(sizeof(char) * (len + 1));
        if(subStr.ch == NULL)
            return 0;
        else
        {
            int j = pos;
            for(int i = 0;i < len;i++)
            {
                subStr.ch[i] = str.ch[j];
                j++;
            }
            subStr.ch[j] = "\0";//subStr.ch[len + 1] = "\0";
            subStr.length = len;
            return 1;

        }
    }
}

//串连接操作
int concat(Str &str,Str str1,Str str2)
{
    int i,j = 0;
    //清空串
    if(str.ch)
    {
        free(str.ch);
        str.ch = NULL;//避免野指针
    }
    str.ch = (char *)malloc(sizeof(char) * (str1.length + str2.length + 1));
    if(str.ch == NULL)
        return 0;
    for(i;i < str1.length;i++)
        str.ch[i] = str1.ch[i];
    for(j;j < str2.length;j++)
        str.ch[i+j] = str2.ch[j];
    str.ch[i + j] = "\0";
    str.length = str1.length + str2.length;
    return 1;
}


/*********************************BF算法***************************************/

int BruteForce(Str str,Str subStr)
{
    int i,j = 1;
    int k = i;
    while(i <= str.lentgh && j <= subStr.length)
    {
        if(str.ch[i] == subStr.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j = 1;
            i = ++k;
        }
    }

    //匹配成功
    if(j > subStr.length)
        return k;
    else
        return 0;//匹配失败
}

/*********************************KMP算法 START***************************************/

int KMP(char *t,char *p)
{
    int i = 0,j = 0;

    while(i < strlen(t) && j < strlen(p))
    {
        if(j == -1 || t[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if(j >= strlen(p))
        return i - j;
    else
        return -1;
}

/*********************************next数组算法***************************************/

void getNext(char *p,int *next)
{
    next[0] = -1;
    int i = 0,j = -1;
    while(i < strlen(p)-1)
    {
        if(j == -1 || p[i] == p[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
/*********************************KMP算法 END***************************************/
