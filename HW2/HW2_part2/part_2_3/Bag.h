#ifndef BAG_H
#define BAG_H
#include <iostream>

using namespace std;

template<class T>
class Bag {
protected:
    T *array;
    int top, capacity, size;
public:
    Bag(int);
    virtual ~Bag();
    virtual int Size() const;
    virtual int Capacity() const;
    virtual bool IsEmpty() const;
    virtual T& Element() const;
    virtual void Push(const T&);
    virtual void Pop();
    virtual void Print() const;
    virtual void ChangeSize1D();
    virtual void ShowProperties();
};

/* class Bag method */
/*----------------------------------------------*/


/* initialize the bag object */
template<class T>
Bag<T>::Bag(int bagCapacity):capacity(bagCapacity) {
    if(bagCapacity < 1)
        throw "Capacity must be > 0";
    array = new T[capacity];
    top = -1;
    size = 0;
}

template<class T>
Bag<T>::~Bag() {
    delete[] array;
}


/*size*/
/*********************************
 * @brief                        *
 *   returns the size of the bag *
 * @tparam T                     *
 * @return int                   *
 *********************************/
template<class T>
int Bag<T>::Size() const {
    return size;
}

/*capacity*/
/***************************************
 * @brief                              *
 *     returns the capacity of the bag *
 * @tparam T                           *
 * @return int                         *
 ***************************************/
template<class T>
int Bag<T>::Capacity() const {
    return capacity;
}


/* isEmpty*/
/************************************************
 * @brief                                       *
 *     returns whether the bag is empty or not  *
 * @tparam T                                    *
 * @return true                                 *
 * @return false                                *
 ************************************************/

template<class T>
bool Bag<T>::IsEmpty() const {
    return (Size() == 0);
}

/*Element*/
/*******************************************************
 * @brief                                              *
 *  returns the top element of the bag                 *
 *  this can be design by taking any element of the bag*
 * @tparam T                                           *
 * @return T&                                          *
 *******************************************************/
template<class T>
T& Bag<T>::Element() const {
    if(IsEmpty())
        throw "Bag is empty";
    return array[top];
}

/*Push*/
/*************************************************
 * @brief                                        *
 *  This pushes an element into the bag          *
 *  If the bag is becoming full, resize the bag  *
 * @tparam T                                     *
 * @param x                                      *
 *************************************************/
template<class T>
void Bag<T>::Push(const T& x) {
    if(size == capacity) {
        ChangeSize1D();
        capacity *= 2;
    }
    array[++top] = x;
    size++;
}

/*Pop*/
/****************************************************************
 * @brief                                                       *
 * This pops the element out of the bag if the bag is not empty *
 * @tparam T                                                    *
 ****************************************************************/

template<class T>
void Bag<T>::Pop() {
    if (IsEmpty())
        throw "Bag is empty";
    array[top--].~T();
    size--;
}


/*Print*/
/****************************************************
 * @brief                                           *
 *  This prints out the bag element sequentially    *
 *                                                  *
 * @tparam T                                        *
 ****************************************************/
template<class T>
void Bag<T>::Print() const{
    for(int i = 0; i < size; i++)
        cout << "[" << array[i] << "]";
    cout << endl;
}

/*ChangeSize1D*/
/**********************************************************
 * @brief                                                 *
 * This functions resizes the bag in to double the size   *
 * @tparam T                                              *
 **********************************************************/
template<class T>
void Bag<T>::ChangeSize1D() {
    int newSize = 2* Capacity();
    T* newArr = new T[newSize];
    for(int i = 0; i < size; i++)
        newArr[i] = array[i];
    delete[] array;
    array = newArr;
}


/*ShowProperties*/
/*********************************************
 * @brief This shows property of the bag     *
 * By using Size() to show size              *
 * Capacity() to show capacity               *
 * Print() to show all elements sequentially *
 *                                           *
 * @tparam T                                 *
 *********************************************/
template<class T>
void Bag<T>::ShowProperties() {
    cout << "\nShowing properties: " << endl;
    cout << "-------------------------------------" << endl;
    cout << "Size: " << Size() << endl;
    cout << "Capacity: " << Capacity() << endl;
    cout << "items: " << endl;
    Print();
    cout << "-------------------------------------" << endl;
}






#endif