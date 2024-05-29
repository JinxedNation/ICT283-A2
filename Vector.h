#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <vector>

    /**
     * @class   Vector
     * @brief   A templated Dynamic array
     * @brief   Used to create a dynamic templated array so it can utilize any data type and grow and shrink on demand.
     *
     * @author  William Halling
     * @date    May 2024
     * @version 0.4
     * @note    Updated and converted previous Dynamic Array Vector to a templated std::vector
     */

template <class T>
class Vector
{
    public:
            /**
             * @brief Vector()
             * Vector Constructor
             */
        Vector();


            /**
             * @brief Vector()
             * Parameterized constructor that contains na integer for the size
             *
             *
             * @param int numItems - size of the vector
             */
        Vector(int numItems);


            /**
             * @brief Copy Constructor
             * Creates a new vector Deep copies the elements of this vector into a new Vector
             *
             *
             * @param newRecords const
             */
        Vector(const Vector& newRecords);


            /**
             * @brief Destructor
             * Used to delete the Vector and free up resources
             */
        ~Vector();


            /**
             * @brief Assignment operator for the vector
             * Used to perform deep copy allowing us to keep all data from pointers.
             *
             *
             * @param  Vector  of oldRecords
             * @return const Vector<T>
             */
        const Vector<T>& operator=(const Vector<T>& oldRecords);



            /**
             * @brief operator[]
             * Used to grant access to the vector at a given number
             *
             *
             * @param  int recordNumber
             * @return T&
             */
        T& operator[](int recordNumber);


            /**
             * @brief const operator[]
             * Used to grant access to the vector at a given number
             *
             *
             * @param  int recordNumber
             * @return const T&
             */
        const T& operator[](int recordNumber) const;


            /**
             * @brief size
             * Used to get the size of the vector
             *
             *
             * @return int m_NumRecords of the vector
             */
        int size() const;


            /**
             * @brief  push_back
             * @brief  used to push an item onto the vector
             * @param  const T newRecord
             */
        void push_back(const T& newRecord);


    private:

        std::vector<T> m_Records; ///m_Records - a pointer to the templated array
};


template <class T>
Vector<T>::Vector() {}



template<class T>
Vector<T>::Vector(int numItems) : m_Records(numItems)
{}


template <class T>
Vector<T>::Vector(const Vector<T>& newData) : m_Records(newData.m_Records)
{}


template<class T>
Vector<T>::~Vector(){}


template<class T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& oldRecords)
{
    if (this != &oldRecords)
    {
        m_Records = oldRecords.m_Records;
    }
    return *this;
}


template<class T>
T& Vector<T>::operator[](int itemNumber)
{
    if(itemNumber < 0 || itemNumber >= m_Records.size())
    {
        throw std::out_of_range("Value is out of range");
    }
    return m_Records[itemNumber];
}


template<class T>
const T& Vector<T>::operator[](int itemNumber) const
{
    if(itemNumber < 0 || itemNumber >= m_Records.size())
    {
        throw std::out_of_range("Value is is out of range");
    }

    return m_Records[itemNumber];
}


template<class T>
int Vector<T>::size() const
{
    return static_cast<int>(m_Records.size());
}


template<class T>
void Vector<T>::push_back(const T& newRecord)
{
    m_Records.push_back(newRecord);
}


#endif // VECTOR_H
