/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <stdlib.h> 
#include <stdio.h> 
#include <locale.h> 

using namespace std;

int main()
{
    setlocale (LC_ALL, "Russian");
    
    char again;
     do {
     	
	    int arLen;
	    printf("Введите количество элементов массива: "); 
	    cin>>arLen;
	    
	    int array[arLen];
	    
	    for ( int i = 0; i < arLen; i++ ) {
	        printf("%d Элемент массива : ", i+1);
	        cin>>array[i];
	    }
	    
	    printf("\n Массив:");
	    for ( int i = 0; i < arLen; i++ ) {
	        printf("[%d]", array[i]);
	    }
	    
	    for ( int i = 0; i < arLen-1; i++ ) {
	        for ( int j = 0 ; j < arLen - 1; j++ ) {
	            if(array[j] > array[j+1]) {           
	              int tmp = array[j];
	              array[j] = array[j+1] ;
	              array[j+1] = tmp; 
	          }
	        }
	    }
	    
	    printf("\n Массив по возрастанию: ");
	    for ( int i = 0; i < arLen; i++ ) {
	        printf("[%d]", array[i]);
	    }
	    
	    
	    printf("\n Массив по убыванию: ");
	    for ( int i = arLen-1; i >= 0; i-- ) {
	        printf("[%d]", array[i]);
	    }
	    
	    printf("\n");
    
        cout<<"Continue?(Y/N)";
    	cin>>again;
	} while (again == 'y' || again == 'Y');
    system("pause");
    return 0;
}
