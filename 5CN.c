#include <stdio.h>
#include <string.h>

#define N strlen(g)

char t[50], cs[50], g[20];
int a, e, c, b;

void xor1()
{
    for(c = 1; c < N; c++)
        cs[c] = (cs[c] == g[c]) ? '0' : '1';
}

void crc()
{
    for(e = 0; e < N; e++)
        cs[e] = t[e];

    do
    {
        if(cs[0] == '1')
            xor1();

        for(c = 0; c < N - 1; c++)
            cs[c] = cs[c + 1];

        cs[c] = t[e++];
    }
    while(e <= a + N - 1);

    cs[N - 1] = '\0';
}

int main()
{
    int flag = 0;

    do
    {
        printf("\n1.crc12");
        printf("\n2.crc16");
        printf("\n3.crc ccit");
        printf("\n4.exit");

        printf("\n\nEnter your option:");
        scanf("%d", &b);

        switch(b)
        {
            case 1:
                strcpy(g, "1100000001111");
                break;

            case 2:
                strcpy(g, "11000000000000101");
                break;

            case 3:
                strcpy(g, "10001000000100001");
                break;

            case 4:
                return 0;
        }

        printf("\nEnter data:");
        scanf("%s", t);

        printf("\n-----------------------");
        printf("\nGenerating polynomial:%s", g);

        a = strlen(t);

        for(e = a; e < a + N - 1; e++)
            t[e] = '0';

        t[e] = '\0';
        printf("\n-----------------------");
        printf("\nModified data is:%s%s", t, g);

        printf("\n-----------------------");

        crc();

        printf("\nChecksum is:%s", cs);

        for(e = a; e < a + N - 1; e++)
            t[e] = cs[e - a];

        t[e] = '\0';

        printf("\n-----------------------");
        printf("\nFinal codeword is:%s%s", t, g);

        printf("\n-----------------------");

        printf("\nTest error detection 0(yes) 1(no):");
        scanf("%d", &e);

        if(e == 0)
        {
            int pos;

            do
            {
                printf("\nEnter the position where error is to be inserted:");
                scanf("%d", &pos);
            }
            while(pos <= 0 || pos > a + N - 1);

            t[pos - 1] = (t[pos - 1] == '0') ? '1' : '0';

            printf("\n-----------------------");
            printf("\nErroneous data:%s", t);
        }

        crc();

        for(e = 0; (e < N - 1) && (cs[e] != '1'); e++);

        if(e < N - 1)
            printf("\nError detected");
        else
            printf("\nNo error detected");

        printf("\n-----------------------");

    } while(flag != 1);

    return 0;
}