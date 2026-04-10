class DynamicArray {
private:
    int *arr;
    int length = 0;
    int capacity;

public:

    DynamicArray(int capacity) : capacity(capacity) {
        arr = new int[capacity];   
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (length == capacity) resize();
        arr[length] = n;
        length++;
    }

    int popback() {
        length--;
        return arr[length];
    }

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < length; i++) newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};
