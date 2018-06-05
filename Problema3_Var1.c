#include <stdio.h>
#include <stdlib.h>
typedef struct task{
     int id,start,finish;

};
struct task vector[1001];
int n;
int i,j;
int p,nr_activities,solution[1001];
int main()
{
    printf("The number of activities is:");
    scanf("%d",&n);

    for(i = 1;i <= n;i++){
        vector[i].id = i;
        printf("The starting time of the tasks are:")
        scanf("%d",&vector[i].start);
        printf("The finish time of the tasks are:");
        scanf("%d",&vector[i].finish);

    }

    for(i = 1;i < n;i++)
        for(j = i+1;j <= n;j++)
            if(vector[i].finish > vector[j].finish){
                 struct task aux = vector[i];
                  vector[i] = vector[j];
                  vector[j] = aux;
  }

    nr_activities=1;
    p=vector[1].finish;
    solution[1]=1;

    for(i = 2;i <= n;i++)
       if(vector[i].start >= p){
          nr_activities++;
          p = vector[i].finish;
          solution[nr_activities] = i;
  }
    printf("The number of activities that can be programmed is:");
    printf("%d\n",nr_activities);

    for(i = 1;i <= nr_activities;i++){
        printf("And their ids, starting and finish time are:");
        printf("%d %d %d\n",vector[solution[i]].id, vector[solution[i]].start,vector[solution[i]].finish);
    }
    return 0;
}
