#include<stdio.h>

int main(){
    int i,n,tq,time=0;
    
    printf("Enter no.of processes:");
    scanf("%d",&n);
    
    int wt[n], tat[n], bt[n], p[n], rem_bt[n];
    float avg_wt=0, avg_tat=0;
    
    for(i=0;i<n;i++){
        p[i]=i+1;
        printf("Enter burst time for p%d:",p[i]);
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    
    printf("Enter time quantum:");
    scanf("%d",&tq);
    
    while(1){
        int done = 1;
        
        for(i=0;i<n;i++){
            if(rem_bt[i] > 0){
                done = 0;  // still work left
                
                if(rem_bt[i] > tq){
                    time += tq;
                    rem_bt[i] -= tq;
                }
                else{
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        
        if(done == 1){
            break;
        }
    }
    
    for(i=0;i<n;i++){
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    
    avg_wt /= n;
    avg_tat /= n;
    
    printf("\nProcess \t Burst Time \t WT \t TAT\n");
    for(i=0;i<n;i++){
        printf("P%d\t\t %d\t\t %d\t %d\n",p[i],bt[i],wt[i],tat[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f",avg_wt);
    printf("\nAverage Turnaround Time: %.2f",avg_tat);
    
    return 0;
}
