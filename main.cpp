#include <iostream>
#include <stdexcept> //need this header for handling exceptions
using namespace std;
// Step 1: Class Definition
template <typename T>
class MyVector {
private:
    T* data;     // Pointer to dynamically allocated array to store elements
    int length;  // Number of elements in the array

public:
    // Constructor
    MyVector();

    // Destructor to free allocated memory
    ~MyVector();

    // Member function prototypes
    void addElement(T element);
    T at(int index) const;
    int size() const;
    T sum() const;
    T max() const;
    T min() const;
    MyVector<T> slice(int begin, int end) const;
};

// Step 2: Constructor and Destructor
template <typename T>
MyVector<T>::MyVector() : data(nullptr), length(0) {}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] data;
}

// Step 3: Adding Elements to the Vector
template <typename T>
void MyVector<T>::addElement(T element) {
    T* newData = new T[length + 1];
    for (int i = 0; i < length; ++i) {
        newData[i] = data[i];
    }
    newData[length] = element;
    delete[] data;
    data = newData;
    ++length;
}

// Step 4: Accessing Elements at a Specific Index
template <typename T>
T MyVector<T>::at(int index) const {
    if (index < 0 || index >= length) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

// Step 5: Getting the Size of the Array
template <typename T>
int MyVector<T>::size() const {
    return length;
}

// Step 6: Calculating the Sum of All Elements
template <typename T>
T MyVector<T>::sum() const {
    T total = 0;
    for (int i = 0; i < length; ++i) {
        total += data[i];
    }
    return total;
}

// Step 7: Finding the Maximum and Minimum Elements
template <typename T>
T MyVector<T>::max() const {
    if (length == 0) throw std::runtime_error("Array is empty");
    T maxValue = data[0];
    for (int i = 1; i < length; ++i) {
        if (data[i] > maxValue) maxValue = data[i];
    }
    return maxValue;
}

template <typename T>
T MyVector<T>::min() const {
    if (length == 0) throw std::runtime_error("Array is empty");
    T minValue = data[0];
    for (int i = 1; i < length; ++i) {
        if (data[i] < minValue) minValue = data[i];
    }
    return minValue;
}

// Step 8: Implementing the Slice Function
template <typename T>
MyVector<T> MyVector<T>::slice(int begin, int end) const {
    if (begin < 0 || end >= length || begin > end) {
        throw std::out_of_range("Invalid slice indices");
    }
    MyVector<T> slicedArray;
    for (int i = begin; i <= end; ++i) {
        slicedArray.addElement(data[i]);
    }
    return slicedArray;
}

// Step 9: Testing the Class in Main
int main() {
    // Create a MyVector of integers
    MyVector<int> vec;
    vec.addElement(0);
    vec.addElement(2);
    vec.addElement(4);
    vec.addElement(6);
    vec.addElement(12);

    // Test accessing elements
    cout << "Element at index 2: " << vec.at(2) << endl;

    // Test sum, max, and min functions
    cout << "Sum: " << vec.sum() << endl;
    cout << "Max: " << vec.max() << endl;
    cout << "Min: " << vec.min() << endl;

    // Test the slice function
    MyVector<int> slicedVec = vec.slice(1, 3);
    cout << "Sliced elements: ";
    for (int i = 0; i < slicedVec.size(); ++i) {
        cout << slicedVec.at(i) << " ";
    }
    cout << endl;

    return 0;
}