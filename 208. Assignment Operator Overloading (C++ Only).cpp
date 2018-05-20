/**
Implement an assignment operator overloading method.

Make sure that:

The new data can be copied correctly
The old data can be deleted / free correctly.
We can assign like A = B = C

Clarification
This problem is for C++ only as Java and Python don't have overloading for assignment operator.

Example
If we assign like A = B, the data in A should be deleted, and A can have a copy of data from B.
If we assign like A = B = C, both A and B should have a copy of data from C.
 */
/**
对类的运算符重载。注意格式
*/

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        if (pData) {
            m_pData = new char[strlen(pData) + 1];
            strcpy(m_pData, pData);
        } else {
            m_pData = NULL;
        }
    }
    ~Solution(){
    }
    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        if (this == &object) {
            return *this;
        }

        if (object.m_pData) {
            char *temp = m_pData;
            m_pData = new char[strlen(object.m_pData)+1];
            strcpy(m_pData, object.m_pData);
            if(temp) delete[] temp;
        }
        else {
            m_pData = NULL;
        }
        return *this;
    }
};