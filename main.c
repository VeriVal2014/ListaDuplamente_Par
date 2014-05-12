#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int option=1, num=0;

	do{
		scanf("%d", &option);
	
		switch (option){
		
		case 0: break;
		case 1: scanf("%d", &num);
			insertFront(num);
			break;
		case 2: scanf("%d", &num);
			insertBack(num);
			break;
		
		case 3: scanf("%d", &num);
			deleteNum(num);
			break;
		case 4: show();
			break;
		case 5: showInv();
			break;
		default: printf("Opcao invalida\n\n");
			option=0;
			break;
		
		}
	}while(option!=0);
	
	return 1; 
}
