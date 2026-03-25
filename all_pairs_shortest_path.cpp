#include<stdio.h>

#define INF 9999
#define MAX 10

int main(){
	int n,i,j,k;
	int dist[MAX][MAX];
	
	printf("Enter the no.of vertices :");
	scanf("%d",&n);
	
	printf("\nEnter the adjacency matrix:\n");
	printf("Enter %d for INF if there is no direct edges\n\n",INF);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("Enter the value of [%d][%d] :",i+1,j+1);
			scanf("%d",&dist[i][j]);
		}
		printf("\n");
	}
	
	// Floyd-Warshall ALgorithm
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	printf("\nShortest path matrix:\n\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist[i][j]==INF){
				printf("INF\t");
			}
			else{
			printf("%d\t",dist[i][j]);
		}
		}
		printf("\n");
	}
	return 0;
	
}
