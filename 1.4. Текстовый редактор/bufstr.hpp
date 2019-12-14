#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class MyClass //Класс MyClass
{
	private:
		string str; //объект класса string с уровнем инкапсуляции private для хранения строки символов;
	public:
		MyClass();
		char* get_char() {
			return (char* ) str.c_str(); 
		};//метод получения хранимой строки в виде c-строки;
		
		//конструктор на основе заданной строки типа string;
		MyClass(string qstr) { 
			str=qstr;
		};
		
		MyClass(char* qch) { //конструктор на основе заданной c-строки;
			str=qch;
		};
		
		MyClass(const MyClass &other) { //копирующий конструктор;
			str=other.str;
		};
		MyClass(int null, char* filename) { //конструктор на основе имени файла, заданного c-строкой;
			string i;
			char j;
			ifstream f(filename);
			while(!f.eof())
			{
				j=f.get();
				if(f.eof())break;
				i+=j;
			}
			f.close();
			str=i;	
		} ;
		string get_string(){ //метод получения хранимой строки в виде объекта string;
			return str;
		};
		void set_string(string wstr) { //метод установки хранимой строки из заданной c-строки;
			str=wstr;
		};
		void set_char(char* wch) { //метод установки хранимой строки из объекта string;
			str=wch;
		};
		void file_load(int null, char* filename) { //метод загрузки хранимой строки из файла;
			string i;
			string j;
			ifstream f(filename);
			while(!f.eof()) // если достигнит конца файла будет 1, истринно пока 0
			{
				j=f.get(); //Возврат 1 символа как значение типа char
				if(f.eof())break;
				i+=j;
			}
			f.close();
			str=i;
		}; 
		void file_save(int null, char* filename) { //метод сохранения хранимой строки в файл;
			ofstream f(filename);
			int i = 0;
			while(str[i])
			{
				f.put(str[i]);
				i++;
			}
			f.close();
		};
};
MyClass::MyClass() 
{
}


