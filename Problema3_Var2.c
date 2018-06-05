#include <stdio.h>
#include <stdlib.h>
typedef struct task{
     int id,start,finish;

};

struct task vector[1001];

int n;
int i,j;
int p,nr_activities,solution[1001];
void solutie(int k, int t){
    if(k <= n){
        if(vector[k].start >= t){
            nr_activities++;
            solution[nr_activities] = k;
            solutie(k+1,vector[k].finish);
        }
        else
            solutie(k+1,t);

    }

}
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
    solution[1]=1;

    nr_activities=1;

    solutie(2,vector[1].finish);

    printf("The number of activities that can be programmed is:");
    printf("%d\n",nr_activities);

    for(i = 1;i <= nr_activities;i++){
        printf("And their ids, starting and finish time are:");
        printf("%d %d %d\n",vector[solution[i]].id, vector[solution[i]].start,vector[solution[i]].finish);
    }
    return 0;
}
