#include<stdio.h>
int test(int up,int down)
{
    //res is negtive
    int flag = up^down>0;
    // int x = 6;
    // int k = -103+(1<<x);
    // printf("tt:%d\n",k>>x);
    switch (flag)
    {
    case 0:
        if(up>0){
            ++down;
            while(up!=1&&down!=-1){
                ++flag;
                up >>= 1;
                down >>= 1;
            }
            if(up==1&&down==-1)return 1;
            if(up==1)return 0;
            else return -(1<<flag)*up;
        }
        break;
    case 1:

    default:
        break;
    }
    printf("flag is %d\n",flag);
}
int main(){
    printf("%d\n",test(100,-100));
    return 0;
}