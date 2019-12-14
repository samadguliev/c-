#include <windows.h>
#include <iostream>
#include "bufstr.hpp"
/*���������� ����������*/
HWND hwndEdit; // �������� ���������� ��� ���� �������������� ������
OPENFILENAME ofn;
/*��������� �� ��������� OPENFILENAME
� ������� ���������� ���������� ��� ������������ �������.
�������� ���������� � ��������� ����� ��� GetOpenFileName � GetSaveFileName */
char szFile[100000]= {0} ;
char szFile_name[10000]= {0};
bool openfs = false;
MyClass files;

/* ��� �������� ������� ������� ����� ������������ ��������� ������� �������� � ������� ���� */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) { 
 	ofn.lpstrFile = szFile; 
	ofn.nMaxFile =sizeof(szFile);
 	ofn.lpstrFileTitle = szFile_name;
 	ofn.nMaxFileTitle = sizeof(szFile_name);
 	ofn.lStructSize = sizeof(ofn);
	ofn.Flags = OFN_EXPLORER|OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST;
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = "��������� ���� (*.txt)\0*.txt\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrDefExt = ("txt");
			   		
	/* ����� (������) ��� ��������� �������, ��� ������ ���� ����� �������� ��� �� */				   		    
	switch(Message) { 
			case WM_SIZE:
		{
			MoveWindow(hwndEdit, 0, 0, LOWORD(lParam), HIWORD(lParam) , TRUE);
			break;
		}
	
	
        case WM_COMMAND:{ 
        	            switch (LOWORD(wParam)) {
            case 101:{ 
					if(GetOpenFileName(&ofn)!=0)
					{
					files.file_load(0, szFile); 
					SetWindowText(hwndEdit,files.get_char()); 
					openfs=true;
					}
		    		   break;
                }
            case 102:{ 
              if(openfs==false) /*�������� ��� �� ������ �� ����� ���� ���� ������� 
					�� ����������� ���������� ���� ��������� ���*/
			  	{
						if(GetSaveFileName(&ofn)!=0)
						{
							char textEditt[10000]; 
							GetWindowText(hwndEdit,textEditt,10000);
							files.set_char(textEditt);
							files.file_save(0, szFile);
							openfs=true;
							MessageBox(hwnd, TEXT("���� ��������!"),TEXT(""), 0);
						}
				} 
					else
					{
						char textEditt[10000];
						GetWindowText(hwndEdit,textEditt,10000 );
						files.set_char(textEditt);
						files.file_save(0, szFile);
						MessageBox(hwnd, TEXT("���� ��������" ),TEXT(""), 0);
					}
					break;
			  }
			  	case 103:/*������ ��������� ���*/
				{
					if(GetSaveFileName(&ofn)!=0)
					{
						char textEditt[10000];
						GetWindowText(hwndEdit,textEditt,10000 );
						files.set_char(textEditt);
						files.file_save(0, szFile);
						MessageBox(hwnd, TEXT("���� ��������"),TEXT("��������� ���"), 0);
					}
					break;
				}
			  			  
              	case 104: /*������� �� "�����"*/
            	{
            		SendMessage(hwnd, WM_CLOSE, 0, 0);//�������� ��������� � �������� �������� ����
            		break;
            	}
            
                case 105:{ 
                  MessageBox(hwnd,"��������� ��������, �������� ������ ����-17� - ������ �.�.","� ���������",MB_OK);
                   break;
                }
            }
        }
	
        default: // ���� �� �������� ������ case �� ����������� default
            return DefWindowProc(hwnd, Message, wParam, lParam);
            }
    return 0;
	
	switch(Message) {  
				/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {            
			PostQuitMessage(0);
			break;
		}
	}
	return 0;
}


/* �������� ������� Win32-�������� � ����������� �����������: ����� ���������� ���������� */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; 
	HWND hwnd; 
	MSG msg; 

	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX); 
	wc.lpfnWndProc	 = WndProc; 
	wc.hInstance	 = hInstance; 
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW); 
	
	/* ���� ���� � �� (�����, ��������� �����) */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW); 
	wc.lpszClassName = "WindowClass"; 
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); 
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); 

	if(!RegisterClassEx(&wc)) { 
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK); 
		return 0; 
	}
	
		hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","��������� ��������",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		640, 
		480, 
		NULL,NULL,hInstance,NULL); 
		hwndEdit = CreateWindowEx(NULL,"Edit","", WS_VISIBLE|WS_CHILD|WS_VSCROLL|ES_MULTILINE,
		NULL, 
		NULL, 
		600, 
		420, 
		hwnd,NULL,hInstance,NULL);
		/* <----------------- �������� ����----------------> */
	HMENU FirstMenu = CreateMenu(); 
    HMENU SecondMenu = CreatePopupMenu();
    AppendMenu(FirstMenu, MF_STRING | MF_POPUP, (UINT_PTR)SecondMenu, "����");
    AppendMenu(SecondMenu, MF_STRING, 101, "�������"); 
    AppendMenu(SecondMenu, MF_STRING, 102, "���������"); 
    AppendMenu(SecondMenu, MF_STRING, 103, "��������� ���");
    AppendMenu(SecondMenu, MF_STRING, 104, "�����");
    AppendMenu(FirstMenu, MF_STRING, 105, "� ���������");
    SetMenu(hwnd, FirstMenu); 
    SetMenu(hwnd, SecondMenu); 
	
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK); // ��������� ������������
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	// ���� ���������
	while(GetMessage(&msg, NULL, 0, 0) > 0) { 
		TranslateMessage(&msg);
		DispatchMessage(&msg); 
	}
	return msg.wParam;
}
