#include <stdio.h>
#include <string.h>

int stack[10000];
int top = -1;

void push(int data)
{
    stack[++top] = data;
}

int empty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int pop()
{
    if (empty())
    {
        return -1;
    }
    return stack[top--];
}

int size()
{
    return top + 1;
}

int top2()
{
    if (empty())
    {
        return -1;
    }
    return stack[top];
}

int main()
{
    int value;
    char input[10];

    scanf("%d", &value);

    for (int i = 0; i < value; i++)
    {
        scanf("%s", input);

        if (strcmp(input, "push") == 0)
        {
            int data;
            scanf("%d", &data);
            push(data);
        }
        else if (strcmp(input, "pop") == 0)
        {
            printf("%d\n", pop());
        }
        else if (strcmp(input, "size") == 0)
        {
            printf("%d\n", size());
        }
        else if (strcmp(input, "empty") == 0)
        {
            printf("%d\n", empty());
        }
        else if (strcmp(input, "top") == 0)
        {
            printf("%d\n", top2());
        }
    }

    return 0;
}
