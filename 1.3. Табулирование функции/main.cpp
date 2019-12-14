#define _USE_MATH_DEFINES
#include<iostream>
#include <locale.h>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std;
int main( )
{
    setlocale (LC_ALL, "Russian");
    
    char again;
    
    do {
    	
    	double x, x1, x2, step;
    cout<<"Укажите начало диапазона табулирования, конец диапазона табулирования x = [x1;x2] :\n";
    cout<<"Введите начало: ";
    
    cin>>x1;
    
    cout<<"Введите конец: ";
    
    cin>>x2;

    int i;
    
    cout<<"Введите шаг табулирования: ";            
    
    cin>>step; 
    int stepsQuantity = floor((x2-x1)/step);
	double values[stepsQuantity];
    cout<<endl;
    
    for(x = x1, i = 0; x <= x2; x+=step, i++)
    {
          double threeAndTwo = 3.2;
          values[i] = ((x-powl(threeAndTwo, 2*x)) / (powl(x, 2) + log(powl(x, 2) + 1))) * (x - powl(M_E, -x));
          cout<<setprecision(12)
              <<x<<": "
              <<values[i];
          cout<<endl;
          
          
    }
    cout<<endl;
    
    double valuesMax = values[0];
    double valuesMin = values[0];
    for (i = 0; i < stepsQuantity; i++) {
        if (values[i] > valuesMax) {
           valuesMax = values[i];           
        }
        if (values[i] < valuesMin) {
           valuesMin = values[i];           
        }    
    }
    
    cout<<"Минимальное значение табулирования: "<<valuesMin<<endl<<"Максимальное значение табулирования: "<<valuesMax;
    
    cout<<endl;
    	
    	cout<<"Continue?(Y/N)";
    	cin>>again;
	} while (again == 'y' || again == 'Y');
    
    system("pause");
    return 0;
}
