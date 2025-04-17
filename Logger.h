#pragma once
#include <iostream>
#include <windows.h>

class Logger {
public:
	void log(const std::string& message, const int code = 7) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		// Set color based on code (0–15)
		switch (code) {
		case 0:  SetConsoleTextAttribute(hConsole, 0);  break; // Black
		case 1:  SetConsoleTextAttribute(hConsole, 1);  break; // Blue
		case 2:  SetConsoleTextAttribute(hConsole, 2);  break; // Green
		case 3:  SetConsoleTextAttribute(hConsole, 3);  break; // Aqua/Cyan
		case 4:  SetConsoleTextAttribute(hConsole, 4);  break; // Red
		case 5:  SetConsoleTextAttribute(hConsole, 5);  break; // Magenta
		case 6:  SetConsoleTextAttribute(hConsole, 6);  break; // Yellow
		case 7:  SetConsoleTextAttribute(hConsole, 7);  break; // Light Gray
		case 8:  SetConsoleTextAttribute(hConsole, 8);  break; // Dark Gray
		case 9:  SetConsoleTextAttribute(hConsole, 9);  break; // Light Blue
		case 10: SetConsoleTextAttribute(hConsole, 10); break; // Light Green
		case 11: SetConsoleTextAttribute(hConsole, 11); break; // Light Cyan
		case 12: SetConsoleTextAttribute(hConsole, 12); break; // Light Red
		case 13: SetConsoleTextAttribute(hConsole, 13); break; // Light Magenta
		case 14: SetConsoleTextAttribute(hConsole, 14); break; // Light Yellow
		case 15: SetConsoleTextAttribute(hConsole, 15); break; // White
		default: SetConsoleTextAttribute(hConsole, 7);  break; // Fallback to Light Gray
		}

		std::cout << "[LOG]: " << message << std::endl;
	}
};