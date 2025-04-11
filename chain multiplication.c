#include<stdio.h>
#define limit 999
int m[10][10],s[10][10],dim[10],n,d;
void matrix(){
	int i,j,k,l,q;
	n=d-1;
	for(i=1;i<=n;i++){
		m[i][i]=0;
}
for(l=2;l<=n;l++){
	for(i=1;i<=n-l+1;i++){
		j=i+l-1;
		m[i][j]=limit;
		for(k=i;k<=j-1;k++){
			q=m[i][k]+m[k+1][j]+(dim[i-1]*dim[j]*dim[k]);
			if(q<m[i][j]){
				m[i][j]=q;
				s[i][j]=k;
			}
		}
	}
}
printf("m table\n");
for(i=1;i<=n;i++){
	for(j=1;j<=n;j++){
		if(i<=j)
		printf("%d\t",m[i][j]);
		else
		printf("\t");
	}
	printf("\n");
}
printf("s table\n");
for(i=1;i<=n-1;i++){
	for(j=2;j<=n;j++){
		if(i<j)
		printf("%d\t",s[i][j]);
		else
		printf("\t");
	}
	printf("\n");
}
printf("value of minimumcost=%d\n",m[1][n]);
}
void parenthesis(int i,int j){
	if(i==j)
	printf("A%d",i);
	else{
		printf("(");
		parenthesis(i,s[i][j]);
		parenthesis(s[i][j]+1,j);
		printf(")");
	}
}
int main(){
	int i;
	printf("enter number of dimensions");
	scanf("%d",&d);
	printf("enter value of dimensions");
	for(i=0;i<d;i++){
		scanf("%d",&dim[i]);
	} 
	matrix();
	parenthesis(1,d-1); 
}
