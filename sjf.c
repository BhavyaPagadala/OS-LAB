#include<stdio.h>
int main(){
	int i,j,n,temp;
	printf("Enter no.of processes:");
	scanf("%d",&n);
	int wt[n],tat[n],bt[n],p[n];
	float avg_wt=0,avg_tat=0;
	for(i=0;i<n;i++){
		p[i]=i+1;
		printf("Enter brust time for p%d:",p[i]);
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(bt[i]>bt[j]){
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	wt[0]=0;
	for(i=1;i<n;i++){
		wt[i]=bt[i-1]+wt[i-1];
		avg_wt+=wt[i];
	}
	for(i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
		avg_tat+=tat[i];
	}
	avg_wt/=n;
	avg_tat/=n;
	printf("\nprocess \t Burst Time \t WT \t TAT \n");
	for(i=0;i<n;i++){
		printf("p%d\t \t %d \t \t %d \t %d \n",p[i],bt[i],wt[i],tat[i]);
	}
	printf("\nAverage Waiting time:%.2f",avg_wt);
	printf("\nAverage Turn Around time:%.2f",avg_tat);
	return 0;
}
