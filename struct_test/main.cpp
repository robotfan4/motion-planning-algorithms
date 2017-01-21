////#include <iostream>

////using namespace std;

////int main(int argc, char *argv[])
////{
////    cout << "Hello World!" << endl;
////    return 0;
////}


//#include <stdio.h>

//struct x1 //x1为结构标签
//{
//    int a;
//    int b;
//};
//typedef struct
//{
//    int c;
//    int d;
//}tx;    //tx为类型定义

//typedef struct node
//{
//    char item;
//    struct node *next;    //结构体中定义指向自己的指针
//}NODEPTR;

///*
//typedef struct node
//{
//    char *item;
//    NODEPTR next;    //不可以,不能在typedef类型之前使用它
//}*NODEPTR;
//*/


//int main(int argc, char *argv[])
//{
//    struct x1 s1;    //不能用结构标签自动生成类型定义名: x1 s1
//    tx s2;
//    NODEPTR node1;
//    NODEPTR node2;
//    node1.next = &node2;

//    s1.a = 1;
//    s1.b = 2;
//    s2.c = 3;
//    s2.d = 4;
//    node1.item = 'x';
//    node2.item = 'y';
//    printf("s1.a:%d, s1.b:%d \n",s1.a,s1.b);
//    printf("s2.c:%d, s2.d:%d \n",s2.c,s2.d);
//    printf("%c, %c \n",node1.item, node2.item);

//}


// define a struct containing a pointer which points to itself.

#include <stdio.h>
#include <string.h>
//struct node
//{
//    int x;
//    int y;
//    struct node* next;

//};

//int main(int argc, char* argv[])
//{

//    node node1, node2;
//    node1.x =0;
//    node1.y =1;
//    node1.next = &node2;
//    node2.x=1;
//    printf("node1: %d\n", node1.x);
//    printf("node2: %d\n",node1.next->x);
//    // for usual 32bit int value, the index is  ?
//    int index;
//    for (int value =0;value<1000;value++)
//    {
//            index = (value * 2654435769) >> 28;
//            printf("node1: %d\n", index);


//    }



//}


#define HASHSIZE 32


//待存入表格数据

char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do",
        "double", "else", "enum", "extern", "float", "for", "goto",
        "if",
        "int", "long", "register", "return", "short", "signed", "sizeof",
        "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
        "while"
};

char keybuf[HASHSIZE][10];
static char val_flag[HASHSIZE];//标致已占用存储单元


void ClearFlag()
{
    int i;

    for (i = 0;i < HASHSIZE;i++)
    {
        val_flag[i] = (HASHSIZE+1);//清标致位

    }
}

//哈希函数，从数据中抽出某个成员用于哈希值的计算

unsigned int hash(char *s)
{
    unsigned int hashval;
    int i = 0;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    hashval = hashval % HASHSIZE; //计算下标


    while ((val_flag[hashval] != (HASHSIZE+1)) && (i<32))
    {
        i++;
        hashval = (hashval + i)%HASHSIZE;    //冲突处理，存储单元(下标)偏移

    }
    if (i<HASHSIZE)
    {
        printf("\n元素下标(%d): 冲突次数： %d -- ",hashval,i);
        val_flag[hashval] = hashval; //表示该单元被占用

        return hashval;
    }
    return -1;
}

int main(void)
{
  int i, size, pos;

  size = sizeof(keywords) / sizeof(keywords[0]);//计算关键字数量


  //将数据存入哈希表

  ClearFlag();
  for(i = 0;i < size; i++)
     strcpy(keybuf[hash(keywords[i])],keywords[i]);

  //根据数据结构中某个成员作为索引值，查找对应数据

  ClearFlag();
  for(i = 0; i < size; i++)
  {
    pos = hash(keywords[i]);
    printf("%-10s: %-3d\n", keybuf[pos], pos);
  }

  return 0;
}


