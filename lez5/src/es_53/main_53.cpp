template <typename T>
class SimpleArray {
public:
    // Costruttore
    SimpleArray (const int & elementsNum) { 
        elementsNum_p = elementsNum;
        elements_p = new T[elementsNum_p];
    }
    // Distruttore
    ~SimpleArray () {
        delete elements_p;
    }
    T & element (const int& i)  {
        if(i >= elementsNum_p) {
            return -1;
        }
        return elementsNum_p[i];
    }
    // Overloading di operator[]
    T & operator[] (const int& i) {
        if(i >= elementsNum_p) {
            return -1;
        }
        return elementsNum_p[i];
    }

private:
    
    int elementsNum_p;
    T * elements_p;
};


