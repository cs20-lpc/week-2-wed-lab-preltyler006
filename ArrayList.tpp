// ArrayList.tpp
#pragma once
#include <stdexcept>
#include <ostream>

// ====== Constructors / Destructor / Assignment ======

template <typename T>
ArrayList<T>::ArrayList(int i)
    : buffer(nullptr), maxSize(i)
{
    if (maxSize <= 0) maxSize = 100;
    this->length = 0;
    buffer = new T[maxSize];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rightObj) {
    if (this != &rightObj) {
        // Free old storage (clear() does not delete buffer by design)
        delete[] buffer;
        buffer = nullptr;
        this->length = 0;
        maxSize = 0;

        copy(rightObj); // deep copy (allocates new buffer)
    }
    return *this;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] buffer;
    buffer = nullptr;
    this->length = 0;
    maxSize = 0;
}

// ====== Core Operations ======

template <typename T>
void ArrayList<T>::append(const T& elem) {
    if (isFull()) {
        throw std::overflow_error("append failed: list is full");
    }
    buffer[this->length] = elem;
    ++this->length;
}

template <typename T>
void ArrayList<T>::clear() {
    // Logically empty the list; keep capacity and allocation.
    // (Optional) zero out: for (int i=0;i<this->length;++i) buffer[i] = T();
    this->length = 0;
}

template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& copyObj) {
    maxSize      = copyObj.maxSize;
    this->length = copyObj.length;
    buffer       = new T[maxSize];

    for (int i = 0; i < this->length; ++i) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
T ArrayList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw std::out_of_range("getElement failed: invalid index");
    }
    return buffer[position];
}

template <typename T>
int ArrayList<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayList<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
void ArrayList<T>::insert(int position, const T& elem) {
    if (isFull()) {
        throw std::overflow_error("insert failed: list is full");
    }
    // Valid insert positions are 0..length (inclusive at end)
    if (position < 0 || position > this->length) {
        throw std::out_of_range("insert failed: invalid index");
    }

    // Shift right to make space
    for (int i = this->length; i > position; --i) {
        buffer[i] = buffer[i - 1];
    }
    buffer[position] = elem;
    ++this->length;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayList<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
void ArrayList<T>::remove(int position) {
    if (this->length == 0) {
        throw std::underflow_error("remove failed: list is empty");
    }
    if (position < 0 || position >= this->length) {
        throw std::out_of_range("remove failed: invalid index");
    }

    // Shift left to fill the gap
    for (int i = position; i < this->length - 1; ++i) {
        buffer[i] = buffer[i + 1];
    }
    // Optional: clear the last (now-unused) slot
    buffer[this->length - 1] = T();

    --this->length;
}

template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw std::out_of_range("replace failed: invalid index");
    }
    buffer[position] = elem;
}

// ====== Printing ======

template <typename T>
std::ostream& operator<<(std::ostream& outStream, const ArrayList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    } else {
        for (int i = 0; i < myObj.length; ++i) {
            outStream << myObj.buffer[i] << ' ';
        }
        outStream << '\n';
    }
    return outStream;
}