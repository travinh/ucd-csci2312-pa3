
// Created by Vinh Van Tran on 3/25/16.
//


/*
 namespace Clustering {

    class Point {
        unsigned int __id;
        unsigned int __dim;        // number of dimensions of the point
        double *__values; // values of the point's dimensions

        static unsigned int __idGen; // id generator

    public:
        static const char POINT_VALUE_DELIM;

        static void rewindIdGen();

        Point(unsigned int);
        Point(unsigned int, double *);

        // Big three: cpy ctor, overloaded operator=, dtor
        Point(const Point &);
        Point &operator=(const Point &);
        ~Point();

        // Accessors & mutators
        int getId() const;
        unsigned int getDims() const;
        void setValue(unsigned int, double);
        double getValue(unsigned int) const;

        // Functions
        double distanceTo(const Point &) const;

        // Overloaded operators

        // Members
        Point &operator*=(double); // p *= 6; p.operator*=(6);
        Point &operator/=(double);
        const Point operator*(double) const; // prevent (p1 * 2) = p2;
        const Point operator/(double) const; // p3 = p2 / 2;

        double &operator[](unsigned int index);
        const double &operator[](unsigned int index) const;

        // Friends
        friend Point &operator+=(Point &, const Point &);
        friend Point &operator-=(Point &, const Point &);
        friend const Point operator+(const Point &, const Point &);
        friend const Point operator-(const Point &, const Point &);

        friend bool operator==(const Point &, const Point &);
        friend bool operator!=(const Point &, const Point &);

        friend bool operator<(const Point &, const Point &);
        friend bool operator>(const Point &, const Point &);
        friend bool operator<=(const Point &, const Point &);
        friend bool operator>=(const Point &, const Point &);

        friend std::ostream &operator<<(std::ostream &os, const Point &p);
        friend std::istream &operator>>(std::istream &is, Point &p);
    };

}
#endif //CLUSTERING_POINT_H

 */


#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <string>

#include "Point.h"
#include "Exceptions.h"

using namespace std;
namespace Clustering{

    unsigned int Point::__idGen=0;
    const char Point::POINT_VALUE_DELIM = ',';

    void Point::rewindIdGen()
    {
        __idGen--;
    }

    Point::Point(unsigned int dim)
    {
        if (dim ==0)
            throw ZeroDimensionsEx();

        __id = __idGen++;
        __dim = dim;
        __values = new double[__dim];

        for(int i=0; i < __dim; i++)
        {
            __values[i]=0;
        }
    }

    Point::Point(unsigned int dim, double *values)
    {
        __id = __idGen++;
        __dim = dim;
        __values = values;
    }

    Point::Point(const Point &p)
    {
        __id = p.getId();
        __dim = p.getDims();
        __values = new double [__dim];

        for (int i = 0 ; i < __dim; i++)
        {
            __values[i]=p.getValue(i);
        }
    }

    Point& Point::operator=(const Point &p)
    {  if (p.getDims() != this->getDims())
            throw DimensionalityMismatchEx(this->getDims(),p.getDims());

        if (this != &p)
        {
            __dim = p.getDims();
            __id = p.getId();

            //delete the values if it is not empty
            if (__values != NULL)
            {
                delete __values;
            }

            //create a new empty values
            __values = new double [__dim];

            for (int i = 0; i < __dim; i++)
            {
                __values[i] = p.getValue(i);
            }
        }

        return *this;
    }

    Point::~Point()
    {
        delete [] __values;
    }

    //--------------------

    int Point::getId() const
    {
        return __id;
    }

    unsigned int Point::getDims() const
    {
        return __dim;
    }

    void Point::setValue(unsigned int i, double values)
    {    if( i >= __dim)
            throw OutOfBoundsEx(__dim,i );
        __values[i] = values;
    }

    double Point::getValue(unsigned int i) const
    {  if (i >=__dim)
            throw OutOfBoundsEx(__dim, i);
        return __values[i];
    }
    //--------------------

    double Point::distanceTo(const Point &p) const {

        if(p.getDims() != this->getDims())
           throw DimensionalityMismatchEx(this->getDims(),p.getDims());

        //condition: this.dim = p.dim, if not return 0
        if (__dim != p.getDims()) {
            return 0;
        }

        double sum = 0;

        for (int i = 0; i < __dim; i++) {
            sum += pow(this->getValue(i) - p.getValue(i), 2);
        }
        return sqrt(sum);
    }

    //----------------------
    //Overloading

    Point& Point::operator*=(double  num)
    {
        for(int i =0; i < __dim; i++)
        {
            __values[i] *= num;
        }
        return *this;
    }

    Point& Point::operator/=(double num)
    {
        for (int i=0; i < __dim; i++)
        {
            __values[i] /= num;
        }
        return *this;
    }

    const Point Point::operator*(double num) const
    {
        Point p1(*this);
        p1*= num;

        return p1;
    }

    const Point Point::operator/(double num) const
    {
        Point p1(*this);
        p1/= num;

        return p1;
    }

    double& Point::operator[](unsigned int index)
    {  if (index >= __dim)
            throw OutOfBoundsEx(__dim, index);
        return __values[index];
    }

    const double& Point::operator[](unsigned int index) const
    {
        return __values[index];
    }

    //--------------------------
    //Friend

    Point& operator+=(Point &p1, const Point &p2)
    {   if(p1.getDims() != p2.getDims())
           throw DimensionalityMismatchEx(p1.getDims(),p2.getDims());

        if (p1.getDims() == p2.getDims()) {
            for (int i = 0; i < p1.getDims(); i++)
                p1.__values[i] += p2.getValue(i);
        }
        return p1;
    }

    Point& operator-=(Point &p1, const Point &p2)
    {   if(p1.getDims() != p2.getDims())
           throw DimensionalityMismatchEx(p1.getDims(),p2.getDims());

        if (p1.getDims() == p2.getDims()) {
            for (int i = 0; i < p1.getDims(); i++)
                p1.__values[i] -= p2.getValue(i);
        }
        return p1;
    }

    const Point operator+(const Point &p1, const Point &p2)
    {
        Point p(p1);

        p += p2;

        return p;

    }

    const Point operator-(const Point &p1, const Point &p2)
    {
        Point p(p1);

        p-=p2;

        return p;
    }

    bool operator==(const Point &p1, const Point &p2)
    {
        if(p1.getDims() != p2.getDims())
           throw DimensionalityMismatchEx(p1.getDims(),p2.getDims());

        if (p1.getId() != p2.getId())
            return false;
        else {
            for (int i = 0; i < p1.getDims(); i++) {
                if (p1.getValue(i) != p2.getValue(i))
                    return false;
            }
            return true;
        }
    }

    bool operator!=(const Point &p1, const Point &p2)
    {
        return !(p1 == p2);
    }


     bool operator<(const Point &lhs, const Point &rhs)
    {   if(lhs.getDims() != rhs.getDims())
           throw DimensionalityMismatchEx(lhs.getDims(),rhs.getDims());

        bool less = false;
        for (int count = 0; count < lhs.__dim; count++)
        {
            if (lhs.__values[count] < rhs.__values[count])
                return true;
            if(lhs.__values[count] > rhs.__values[count])
                return false;
        }
        return less;
    }

    bool operator>(const Point &p1, const Point &p2) {
        if (p2<p1)
            return true;
        return false;
        //return !(p1 <= p2);
    }


    bool operator<=(const Point &p1, const Point &p2) {
        bool answer;
        answer= (p1>p2);

        return !answer;
    }

    bool operator>=(const Point &p1, const Point &p2) {
        bool answer;
        answer = p1 < p2;

        return (!answer);
    }

    ostream &operator<<(ostream &os, const Point &p1) {
        int i;
        for (i = 0; i < p1.__dim-1; i++) {
            os << p1.__values[i] <<", ";
            //if (i != (p1.getDims() - 1))
             //  cout << ", ";
        }
            os<< p1.__values[i];
            os <<endl;

        return os;
    }


    istream &operator>>(istream &is, Point &p) {

        string str;


        getline(is, str);
        unsigned int size = (unsigned int)count(str.begin(), str.end(), p.POINT_VALUE_DELIM) + 1;

        stringstream ss(str);


        if (p.getDims() != size) {
            throw DimensionalityMismatchEx(p.__dim, size);
        }

        int index = 0;  // current dimension index of point

        while (!ss.eof()) {
            string svalue;
            getline(ss, svalue, ',');

           stringstream streamvalue(svalue);

            streamvalue >> p.__values[index];

            ++index;
        }

        return is;
    }

}

/*
 Cluster(const cluster &cluster)
 _dimen(clus._dimen)
 _size(0)
__ points(nullptr)
 __id(__idgen++)
 centroid(__dimens,*this)
 {if cluster.__point!=null)
 {asserT(cluster._size(
 _cpy(cluster._ponit)s)
 }
 assert(_size==clus.__size)
 centroild.compute()

 //Compute function
 if(_c._pointnull)
 assert(_c._size==0);
 toInfinity();
 return;

 Lnode curr
 */
