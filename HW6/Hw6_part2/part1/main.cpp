#include <iostream>
using namespace std;

template <class T> void copy(T *ai, T *af, T *b);
template <class T> void ShowList(T *a, const int n);
template <class T> void ShowList(T *a, int *link, const int n);
template <class T> void InsertionSort(T *a, const int n);
template <class T> void Insert(const T& e, T *a, int i);
template <class T> void QuickSort(T *a, const int left, const int right);
template <class T> void iterMergeSort(T* a, const int n);
template <class T> void MergePass(T* initList, T* resultList, const int n, const int s);
template <class T> void Merge(T *initList, T *mergedList, const int l, const int m, const int n);
template <class T> int recurMergeSort(T *a, int *link, const int left, const int right);
template <class T> int ListMerge(T *a, int *link, const int start1, const int start2);
template <class T> void HeapSort(T *a, const int n);
template <class T> void Adjust(T *a, const int root, const int n);

int main() {

    char char_input[21] = {0, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z'};

    // nets 2022 roster jersey number
    int int_input[21] = {0, 21, 1, 33, 30, 9, 4, 30, 7, 14, 
    2, 12, 11, 8, 20, 10, 24, 99, 94, 93};

    float float_input[21] = {0, 0.21, 0.01, 0.33, 0.30, 0.09, 0.04, 0.30, 0.07, 0.14,
    0.02, 0.12, 0.11, 0.08, 0.20, 0.10, 0.24, 0.99, 0.94, 0.93};

    string string_input[21] = {"0", "Digital", "Signal", "Processing", "Data" ,"Structures", "Algorithms", "Microelectronics",
    "Integrated", "Circuit", "Computer", "Architechture", "Advanced", "Engineering", "Mathematics", "System", "Design", "Linear", 
    "Algebra", "Probabilities", "Statistics"};

    cout << "The input of 4 different type:" << endl;
    cout << "Char Input: ";
    ShowList(char_input, 20);
    cout << "Int Input: ";
    ShowList(int_input, 20);
    cout << "Float Input: ";
    ShowList(float_input, 20);
    cout << "String Input: ";
    ShowList(string_input, 20);

    int link_list[4][21] = {0};
    
    char char_output1[21];
    char char_output2[21];
    char char_output3[21];
    char char_output4[21];
    char char_output5[21];
    
    int int_output1[21];
    int int_output2[21];
    int int_output3[21];
    int int_output4[21];
    int int_output5[21];

    float float_output1[21];
    float float_output2[21];
    float float_output3[21];
    float float_output4[21];
    float float_output5[21];

    string string_output1[21];
    string string_output2[21];
    string string_output3[21];
    string string_output4[21];
    string string_output5[21];

    cout << "\nAfter InsertionSort:\n";
    copy(char_input + 1, char_input + 20, char_output1 + 1);
    copy(int_input + 1, int_input + 20, int_output1 + 1);
    copy(float_input + 1, float_input + 20, float_output1+ 1);
    copy(string_input + 1, string_input + 20, string_output1 + 1);
    InsertionSort(char_output1, 20);
    InsertionSort(int_output1, 20);
    InsertionSort(float_output1, 20);
    InsertionSort(string_output1, 20);
    cout << "Char Output1:  "; ShowList(char_output1, 20);
    cout << "Integer Output1: "; ShowList(int_output1, 20);
    cout << "Float Output1: "; ShowList(float_output1, 20);
    cout << "String Output1: "; ShowList(string_output1, 20);

    cout << "\nAfter QuickSort:\n";
    copy(char_input + 1, char_input + 20, char_output2 + 1);
    copy(int_input + 1, int_input + 20, int_output2 + 1);
    copy(float_input + 1, float_input + 20, float_output2 + 1);
    copy(string_input + 1, string_input + 20, string_output2 + 1);
    QuickSort(char_output2, 1, 20);
    QuickSort(int_output2, 1, 20);
    QuickSort(float_output2, 1, 20);
    QuickSort(string_output2, 1, 20);
    cout << "Char Output2:  "; ShowList(char_output2, 20);
    cout << "Integer Output2: "; ShowList(int_output2, 20);
    cout << "Float Output2: "; ShowList(float_output2, 20);
    cout << "String Output2: "; ShowList(string_output2, 20);

    cout << "\nAfter iterative MergeSort:\n";
    copy(char_input + 1, char_input + 20, char_output3 + 1);
    copy(int_input + 1, int_input + 20, int_output3 + 1);
    copy(float_input + 1, float_input + 20, float_output3+ 1);
    copy(string_input + 1, string_input + 20, string_output3 + 1);
    iterMergeSort(char_output3, 20);
    iterMergeSort(int_output3, 20);
    iterMergeSort(float_output3, 20);
    iterMergeSort(string_output3, 20);
    cout << "Char Output3:  "; ShowList(char_output3, 20);
    cout << "Integer Output3: "; ShowList(int_output3, 20);
    cout << "Float Output3: "; ShowList(float_output3, 20);
    cout << "String Output3: : "; ShowList(string_output3, 20);

    cout << "\nAfter recursive MergeSort:\n";
    copy(char_input + 1, char_input + 20, char_output4 + 1);
    copy(int_input + 1, int_input + 20, int_output4 + 1);
    copy(float_input + 1, float_input + 20, float_output4+ 1);
    copy(string_input + 1, string_input + 20, string_output4 + 1);
    recurMergeSort(char_output4, link_list[0], 1, 20);
    recurMergeSort(int_output4, link_list[1], 1, 20);
    recurMergeSort(float_output4, link_list[2], 1, 20);
    recurMergeSort(string_output4, link_list[3], 1, 20);
    cout << "Char Output4:  "; ShowList(char_output4, link_list[0], 20);
    cout << "Integer Output4: "; ShowList(int_output4, link_list[1], 20);
    cout << "Float Output4: "; ShowList(float_output4, link_list[2], 20);
    cout << "String Output4: "; ShowList(string_output4, link_list[3], 20);

    cout << "\nAfter HeapSort:\n";
    copy(char_input + 1, char_input + 20, char_output5 + 1);
    copy(int_input + 1, int_input + 20, int_output5 + 1);
    copy(float_input + 1, float_input + 20, float_output5+ 1);
    copy(string_input + 1, string_input + 20, string_output5 + 1);
    HeapSort(char_output5, 20);
    HeapSort(int_output5, 20);
    HeapSort(float_output5, 20);
    HeapSort(string_output5, 20);
    cout << "Char Output5:  "; ShowList(char_output5, 20);
    cout << "Integer Output5: "; ShowList(int_output5, 20);
    cout << "Float Output5: "; ShowList(float_output5, 20);
    cout << "String Output5 : "; ShowList(string_output5, 20);

    return 0;


}


template <class T> 
void copy(T *ai, T *af, T *b)
{
    for (int i = 0; ai + i <= af; i++)
        *(b + i) = *(ai + i);
}

template <class T>
void ShowList(T* a, const int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}

template <class T>
void ShowList(T* a, int *link, const int n)
{
    int i = link[0];
    while (i != 0) {
        cout << a[i] << " ";
        i = link[i];
    }
    cout << endl;
}

template <class T> 
void InsertionSort(T *a, const int n)
{
    for (int j = 2; j <= n; j++) {
        T temp = a[j];
        Insert(temp, a, j - 1);
    }
}

template <class T> 
void Insert(const T& e, T *a, int i)
{
    a[0] = e;
    while (e < a[i]) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = e;
}

template <class T>
void QuickSort(T *a, const int left, const int right)
{
    if (left < right) {
        int i = left;
        int j = right + 1;
        T pivot = a[left];

        do {
            do i++; while (a[i] < pivot);
            do j--; while (a[j] > pivot);
            if (i < j) swap(a[i], a[j]);
        } while (i < j);
        swap(a[left], a[j]);

        QuickSort(a, left, j - 1);
        QuickSort(a, j + 1, right);
    }
}

template <class T> 
void iterMergeSort(T* a, const int n)
{
    T* tempList = new T[n + 1];

    for (int l = 1; l < n; l *= 2) {
        MergePass(a, tempList, n, l);
        l *= 2;
        MergePass(tempList, a, n, l);
    }
    delete []tempList;
}

template <class T> 
void MergePass(T* initList, T* resultList, const int n, const int s)
{
    int i;
    for (i = 1; i <= n - 2 * s + 1; i += 2 * s) 
        Merge(initList, resultList, i, i + s - 1, i + 2 * s - 1);
    
    if ((i + s - 1) < n) Merge(initList, resultList, i, i + s - 1, n);
    else copy(initList + i, initList + n, resultList + i);
}

template <class T> 
void Merge(T *initList, T *mergedList, const int l, const int m, const int n)
{
    int i1, i2, iResult;
    for (i1 = l, i2 = m + 1, iResult = l;
        i1 <= m && i2 <= n;
        iResult++) {
        if (initList[i1] <= initList[i2]) {
            mergedList[iResult] = initList[i1];
            i1++;
        }
        else {
            mergedList[iResult] = initList[i2];
            i2++;
        }
    }

    copy(initList + i1, initList + m, mergedList + iResult);
    copy(initList + i2, initList + n, mergedList + iResult);
}

template <class T>
int recurMergeSort(T *a, int *link, const int left, const int right)
{
    if (left >= right) return left;

    int mid = (left + right) / 2;
    return ListMerge(a, link, recurMergeSort(a, link, left, mid), recurMergeSort(a, link, mid + 1, right));
}

template <class T>
int ListMerge(T *a, int *link, const int start1, const int start2)
{
    int i1, i2, iResult = 0;
    for (i1 = start1, i2 = start2; i1 && i2;) {
        if (a[i1] <= a[i2]) {
            link[iResult] = i1;
            iResult = i1;
            i1 = link[i1];
        }
        else {
            link[iResult] = i2;
            iResult = i2;
            i2 = link[i2];
        }
    }

    if (i1 == 0) link[iResult] = i2;
    else link[iResult] = i1;

    return link[0];
}

template <class T>
void HeapSort(T *a, const int n)
{
    for (int i = n / 2; i >= 1; i--)   // construct initial heap
        Adjust(a, i, n);
    
    for (int i = n - 1; i >= 1; i--) { // start heap sort
        swap(a[1], a[i + 1]);
        Adjust(a, 1, i);
    }
}

template <class T>
void Adjust(T *a, const int root, const int n)
{
    T e = a[root];
    int j;
    for (j = 2 * root; j <= n; j *= 2) {
        if (j + 1 <= n && a[j] < a[j + 1]) j++;
        if (e >= a[j]) break;
        a[j / 2] = a[j];
    }
    a[j / 2] = e;
}