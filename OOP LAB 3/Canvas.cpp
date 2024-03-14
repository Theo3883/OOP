#include "Canvas.h"
#include <iostream>
Canvas::Canvas(int width, int height) : matrix(nullptr),matrix_height(height), matrix_width(width)
{
	matrix = new char* [height];
	for (int i = 0; i < height; i++)
	{
		matrix[i] = new char[width + 1];
		memset(matrix[i],' ',width);
		matrix[i][width] = '\0';
	}
}
bool Canvas::Checkpoint(int x, int y)
{
	if (x<0 || x>matrix_width)
		return 0;
	if (y<0 || y>matrix_height)
		return  0;
	return 1;
}
void Canvas::SetPoint(int x, int y, char ch)
{
	if (!Checkpoint(x, y))
		return;
	if (ch == '\0')
		return;
	matrix[x][y] = ch;
}
void Canvas::Print()
{
	for (int i = 0; i < matrix_height; i++)
	{
		std::cout << matrix[i];
		std::cout << '\n';
	}

}
void Canvas::Clear()
{
	for (int i = 0; i < matrix_height; i++)
	{
		memset(matrix[i], ' ', sizeof(matrix_width));
		matrix[i][matrix_width] = '\0';
	}
}
void Canvas::plotLineLow(int x1, int y1, int x2, int y2,char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int xi = 1;
	if (dx < 0) {
		xi = -1;
		dx = -dx;
	}
	int D = (2 * dx) - dy;
	int x = x1;

	for (int y = y1; y <= y2; ++y) {
		SetPoint(x, y, ch);
		if (D > 0) {
			x = x + xi;
			D = D + (2 * (dx - dy));
		}
		else {
			D = D + 2 * dx;
		}
	}
}
void Canvas::plotLineHigh(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int xi = 1;
	if (dx < 0) {
		xi = -1;
		dx = -dx;
	}
	int D = (2 * dx) - dy;
	int x = x1;

	for (int y = y1; y <= y2; ++y) {
		SetPoint(x, y, ch);
		if (D > 0) {
			x = x + xi;
			D = D + (2 * (dx - dy));
		}
		else {
			D = D + 2 * dx;
		}
	}
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	if (!Checkpoint(x1, y1))
		return;
	if (!Checkpoint(x2, y2))
		return;
	if (abs(y2 - y1) < abs(x2 - x1)) {
		if (x1 > x2) {
			plotLineLow(x2, y2, x1, y1, ch);
		}
		else {
			plotLineLow(x1, y1, x2, y2, ch);
		}
	}
	else {
		if (y1 > y2) {
			plotLineHigh(x2, y2, x1, y1, ch);
		}
		else {
			plotLineHigh(x1, y1, x2, y2, ch);
		}
	}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	DrawLine(top, left, top, right, ch);
	DrawLine(bottom, left, bottom, right, ch);
	for (int i = left; i <= right; ++i) {
		SetPoint(i, top, ch);
		SetPoint(i, bottom, ch);
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++) 
		for (int j = left; j <= right; j++) 
			SetPoint(i, j, ch);
}