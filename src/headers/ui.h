#ifndef UI_H
#define UI_H
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

int getWidth();
int getHeight();
void clearScreen();
void printCenteredText(const char *text);
void printMatr(int r, int c, int mat[r][c], int px, int py);
void inputMatric(int r, int c, int mat[r][c]);
void updateMenu(char arr[][100], int size, int pos);
int selectMenu(char arr[][100], int size);
#endif
