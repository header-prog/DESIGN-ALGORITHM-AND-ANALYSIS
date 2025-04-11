#include<stdio.h>
#define max 30
#define INF 999
int n,cost[max][max],d[max][max],p[max][max];
void floyd(){
	int i,j,k;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					p[i][j]=k;
				}
			}
		}
	}
	printf("D matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d\t",d[i][j]);
		}
		printf("\n");
	}
	printf("\nP matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int i,j;
	printf("Enter number of vertex:");
	scanf("%d",&n);
	printf("Enter the cost matrix:");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(i!=j && cost[i][j]==0){
				cost[i][j]=INF;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			d[i][j]=cost[i][j]; 
			if(i==j){
				p[i][j]=-1;
			}
			else{
			p[i][j]=i;
		}
		}
	}
	floyd();
	return 0;
}
