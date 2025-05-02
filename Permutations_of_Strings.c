#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
    char *temp_arr1=NULL,*temp_arr2=NULL;
	char** copy_arr=NULL;
	static int fact=1,itr_i=0,itr_j=0;
	static char flag =0;
	int i=0;
	if (flag==0){
	for(int i=1;i<=n;i++){
		fact*=i;
	}
	for(int i=0;i<n;i++){
		strcpy(copy_arr[i],s[i]);
		for(int j=i+1;j<n;j++){
		if(strcmp(s[i],s[j])==0){
			fact/=2;
		}
		}
	}
	fact--;
	flag=1;
	}
    if(fact>0){
for(;itr_i<n;itr_i++){
	temp_arr1=copy_arr[itr_i];
	temp_arr2=copy_arr[0];
	copy_arr[0]=temp_arr1;
	copy_arr[itr_i]=temp_arr2;
	for (int j=0;j<n-1;j++)
	{
		
	}
	
}
	fact--;
    return 1;
    }
    else{
	return 0;
	}
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}