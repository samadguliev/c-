#include <cstdlib>
#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char *argv[])
{
    setlocale (LC_ALL, "Russian");
    
    char again;
    do {
    
	    int rows, cols;
	    
	    cout<<"¬ведите количество строк: ";
	    cin>>rows;
	    
	    cout<<"¬ведите количество столбцов: ";
	    cin>>cols;
	    
	    double array[rows][cols];
	    
	    for( int i = 0; i < rows; i++ ) {
	         for( int j = 0; j < cols; j++ ) {
	              cout<<"¬ведите "<<i+1<<" элемент "<<j+1<<" строки: "; 
	              cin>>array[i][j];
	         }         
	    }
	    
	    cout<<endl;
	    
	    cout<<"¬веденный массив: ";
	    for( int i = 0; i < rows; i++ ) {
	         cout<<endl;
	         for( int j = 0; j < cols; j++ ) {
	              cout<<"["<<array[i][j]<<"]";
	         } 
	    }
	    
	    cout<<endl;
	    
	    double maxValues[rows];
	    for( int i = 0; i < rows; i++ ) {
	         double rowMaxVal = array[i][0];
	         for( int j = 0; j < cols; j++ ) {
	              if (array[i][j] > rowMaxVal) {
	                 rowMaxVal = array[i][j];
	              }
	         }
	         maxValues[i] = rowMaxVal;   
	    }
	
	
	    cout<<endl;
	    
	    double c = 0;
	    for( int i = 0; i < rows; i++ ) {
	         c += maxValues[i];
	    }
	    cout<<endl;
	    cout<<"—умма максимальных чисел каждой строки: "<<c;
	    cout<<endl;
	
		cout<<"Continue?(Y/N)";
    	cin>>again;
	} while (again == 'y' || again == 'Y');
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
