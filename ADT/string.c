
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
