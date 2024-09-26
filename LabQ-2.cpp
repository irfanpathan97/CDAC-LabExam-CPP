#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;

public:
    // Constructor to initialize length and width
    Rectangle(int l, int w) : length(l), width(w) {}

    // Function to calculate and return the area
    int Area() {
        return length * width;
    }
};

int main() {
    // Create two Rectangle objects with given dimensions
    Rectangle rect1(4, 5);
    Rectangle rect2(5, 8);

    // Print the area of each rectangle
    cout << "Area of rectangle 1 (4, 5): " << rect1.Area() << endl;
    cout << "Area of rectangle 2 (5, 8): " << rect2.Area() << endl;

    return 0;
}
