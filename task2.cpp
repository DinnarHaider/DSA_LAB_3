#include <iostream>
#include <string>
using namespace std;
class StringPool
{
private:
    string* stringPool;
    int currentSize;
    int maxSize;
public:
    StringPool()
    {
        maxSize = 5;
        currentSize = 0;
        stringPool = new string[maxSize];
    }
    StringPool(const StringPool&) = delete;
    StringPool& operator=(const StringPool&) = delete;
    void addString(const string& text)
    {
        if (currentSize == maxSize)
        {
            cout << "Pool is full.\n";
            return;
        }
        stringPool[currentSize] = text;
       currentSize++;
    }
    void removeString(int index)
    {
        if (index < 0 || index >= currentSize)
        {
            cout << "Invalid index.\n";
            return;
        }

        for (int i = index; i < currentSize - 1; i++)
        {
            stringPool[i] = stringPool[i + 1];
        }
        currentSize--;
        stringPool[currentSize].clear();
    }
    void displayPool() const
    {
        cout << "\nPool status: " << currentSize
             << "/" << maxSize << " strings\n";
        if (currentSize == 0)
        {
            cout << "Pool is empty.\n";
            return;
        }
        for (int i = 0; i < currentSize; i++)
        {
            cout << i << ": " << stringPool[i] << '\n';
        }
    }
    ~StringPool()
    {
    
        delete[] stringPool;
        cout << "Pool memory released.\n";
    }
};

int main()
{
    StringPool pool;

    pool.addString("Apple");
    pool.addString("Mango");
    pool.addString("Orange");
    pool.displayPool();
    cout << "Removing the string at index 1...\n";
    pool.removeString(1);
    pool.displayPool();
    cout << "Adding Banana...\n";
    pool.addString("Banana");
    pool.displayPool();
    return 0;
}
