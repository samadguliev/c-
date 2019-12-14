#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class MyClass //����� MyClass
{
	private:
		string str; //������ ������ string � ������� ������������ private ��� �������� ������ ��������;
	public:
		MyClass();
		char* get_char() {
			return (char* ) str.c_str(); 
		};//����� ��������� �������� ������ � ���� c-������;
		
		//����������� �� ������ �������� ������ ���� string;
		MyClass(string qstr) { 
			str=qstr;
		};
		
		MyClass(char* qch) { //����������� �� ������ �������� c-������;
			str=qch;
		};
		
		MyClass(const MyClass &other) { //���������� �����������;
			str=other.str;
		};
		MyClass(int null, char* filename) { //����������� �� ������ ����� �����, ��������� c-�������;
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
		string get_string(){ //����� ��������� �������� ������ � ���� ������� string;
			return str;
		};
		void set_string(string wstr) { //����� ��������� �������� ������ �� �������� c-������;
			str=wstr;
		};
		void set_char(char* wch) { //����� ��������� �������� ������ �� ������� string;
			str=wch;
		};
		void file_load(int null, char* filename) { //����� �������� �������� ������ �� �����;
			string i;
			string j;
			ifstream f(filename);
			while(!f.eof()) // ���� ��������� ����� ����� ����� 1, �������� ���� 0
			{
				j=f.get(); //������� 1 ������� ��� �������� ���� char
				if(f.eof())break;
				i+=j;
			}
			f.close();
			str=i;
		}; 
		void file_save(int null, char* filename) { //����� ���������� �������� ������ � ����;
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


