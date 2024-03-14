class Canvas
{
private: 
    char** matrix;
    int matrix_width, matrix_height;
    bool Checkpoint(int x, int y);
    void plotLineLow(int x1, int y1, int x2, int y2, char ch);
    void plotLineHigh(int x1, int y1, int x2, int y2, char ch);
public:
    Canvas(int width, int height);
    //void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print(); // shows what was printed
    void Clear(); // clears the canvas
};