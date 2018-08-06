#include<stdio.h>
#include<string.h>
int main(){
	char str[110];
	while(scanf("%s",str)!=EOF){
		int flag=0;
		int n=strlen(str);
		int numa=0,num=0;
		if(str[0]=='@'||str[0]=='.'||str[n-1]=='@'||str[n-1]=='.'){
			printf("NO\n");  flag=1;
		}
		else {
			for(int i=0;i<n-1;i++){
				if(str[i]=='@'&&str[i+1]=='.'||str[i]=='.'&&str[i+1]=='@'){
					printf("NO\n");  flag=1;
				}
	 	    }
	 	    for(int i=0;i<n;i++){
	 	    	if(str[i]=='@'){
	 	    		numa++;
	 	    	}
	 	    }
	 	    if(numa!=1){
	 	    	printf("NO\n");  flag=1;
	 	    }
	 	    else{
	 	    	int j;
	 	    	for(int i=0;i<n;i++){
	 	    		if(str[i]=='@'){
	 	    			 j=i;
	 	    		}
	 	    	}
	 	    	for(int i=j;i<n;i++){
	 	    		if(str[i]=='.'){
	 	    			num++;
	 	    		}
	 	    	}
	 	    	if(num==0){
	 	    		printf("NO\n"); flag=1;
	 	    	}
	 	    }
		}
	    if(flag==0)	printf("YES\n");

	}return 0;
}
