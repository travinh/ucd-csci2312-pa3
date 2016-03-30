//
// Created by Vinh Van Tran on 3/25/16.
//

// File: Exceptions.h
//
// Created by Ivo Georgiev on 3/7/16.
//
/*
 --------------------------------------------------------------------------------------------
#ifndef CLUSTERING_EXCEPTIONS_H
#define CLUSTERING_EXCEPTIONS_H

#include <iostream>

namespace Clustering {

    class OutOfBoundsEx {
        unsigned int __current;
        int __rhs;
        std::string __name;

    public:
        OutOfBoundsEx(unsigned int c, int r);
        unsigned int getCurrent() const;
        int getRhs() const;
        std::string getName() const;

        friend std::ostream &operator<<(std::ostream &os, const OutOfBoundsEx &ex);
    };



    class DimensionalityMismatchEx {
        unsigned int __current, __rhs;
        std::string __name;

    public:
        DimensionalityMismatchEx(unsigned int c, unsigned int r);
        unsigned int getCurrent() const;
        unsigned int getRhs() const;
        std::string getName() const;

        friend std::ostream &operator<<(std::ostream &os, const DimensionalityMismatchEx &ex);
    };



    class ZeroClustersEx {
        std::string __name;

    public:
        ZeroClustersEx();
        std::string getName() const;

        friend std::ostream &operator<<(std::ostream &os, const ZeroClustersEx &ex);
    };



    class DataFileOpenEx {
        std::string __name, __filename;

    public:
        DataFileOpenEx(std::string filename);
        std::string getFilename() const;
        std::string getName() const;

        friend std::ostream &operator<<(std::ostream &os, const DataFileOpenEx &ex);
    };


    class ZeroDimensionsEx {
        std::string __name;

    public:
        ZeroDimensionsEx();
        std::string getName() const;

        friend std::ostream &operator<<(std::ostream &os, const ZeroDimensionsEx &ex);
    };


    class EmptyClusterEx {
        std::string __name;

    public:
        EmptyClusterEx();
        std::string getName() const;

        friend std::ostream &operator<<(std::ostream &os, const EmptyClusterEx &ex);
    };
}


#endif //CLUSTERING_EXCEPTIONS_H
  --------------------------------------------------------------------------------------------


#include <iostream>

#include "Exceptions.h"

using namespace std;
namespace Clustering{

    OutOfBoundsEx::OutOfBoundsEx(unsigned int c, int r)
    {
        __current=c;
        __rhs=r;
        __name="OutOfBoundsEx";
    }

    unsigned int OutOfBoundsEx::getCurrent() const
    {
        return __current;
    }

    int OutOfBoundsEx::getRhs() const
    {
        return __rhs;
    }

    string OutOfBoundsEx::getName() const
    {
        return __name;
    }

   ostream &operator<<(ostream &os, const OutOfBoundsEx &ex)
   {
        os << ex.getName() <<":"<<ex.getCurrent()<<":"<<ex.getRhs()<<endl;
   }

   DimensionalityMismatchEx::DimensionalityMismatchEx(unsigned int c, unsigned int r)
   {
       __current=c;
       __rhs=r;
       __name="DimensionalityMismatchEx";
   }

   unsigned DimensionalityMismatchEx::getCurrent() const
   {
       return __current;
   }

   unsigned DimensionalityMismatchEx::getRhs() const
   {
       return __rhs;
   }

   string DimensionalityMismatchEx::getName() const
   {
       return __name;
   }

   ostream &operator<<(ostream &os, const DimensionalityMismatchEx &ex)
   {
       os << ex.getName() <<":"<<ex.getCurrent()<<":"<<ex.getRhs()<<endl;
   }

   ZeroClustersEx::ZeroClustersEx()
   {
        __name="ZeroClustersEx";
   }

   string ZeroClustersEx::getName() const
   {
       return __name;
   }

   ostream &operator<<(ostream &os, const ZeroClustersEx &ex)
   {
       os << ex.getName()<<endl;
   }

   // ----------Data File Open
   DataFileOpenEx::DataFileOpenEx(std::string filename)
   {
       __filename = filename;
       __name="DataFileOpenEx";
   }

   string DataFileOpenEx::getName() const
   {
       return __name;
   }

   string DataFileOpenEx::getFilename() const
   {
       return __filename;
   }

   ostream &operator<<(ostream &os, const DataFileOpenEx &ex)
   {
       os << ex.getName() << ":"<<ex.getFilename()<<endl;
   }


    //--------------- zerodimension
   ZeroDimensionsEx::ZeroDimensionsEx()
   {
       __name="ZeroDimensionsEx";
   }

   string ZeroDimensionsEx::getName() const
   {
       return __name;
   }

   ostream &operator<<(ostream &os, const ZeroDimensionsEx &ex)
   {
       os << ex.getName()<<endl;
   }

   EmptyClusterEx::EmptyClusterEx()
   {
       __name="EmptyClusterEx";
   }

   string EmptyClusterEx::getName() const
   {
       return __name;
   }

    ostream &operator<<(std::ostream &os, const EmptyClusterEx &ex)
    {
        os <<ex.getName()<<endl;
    }

}
    */
#include "Exceptions.h"

namespace Clustering {

    // Out of bounds
    OutOfBoundsEx::OutOfBoundsEx(unsigned int c, int r) {
        __current = c;
        __rhs = r;
        __name = "OutOfBoundsEx";
    }
    unsigned int OutOfBoundsEx::getCurrent() const {
        return __current;
    }
    int OutOfBoundsEx::getRhs() const {
        return __rhs;
    }
    std::string OutOfBoundsEx::getName() const {
        return __name;
    }

    std::ostream &operator<<(std::ostream &os, const OutOfBoundsEx &ex) {
        os << ex.__name << ": " << ex.__current << " : " << ex.__rhs << std::endl;
    }


    // Dimensionality mismatch
    DimensionalityMismatchEx::DimensionalityMismatchEx(unsigned int c, unsigned int r) {
        __current = c;
        __rhs = r;
        __name = "DimensionalityMismatchEx";
    }
    unsigned int DimensionalityMismatchEx::getCurrent() const {
        return __current;
    }
    unsigned int DimensionalityMismatchEx::getRhs() const {
        return __rhs;
    }
    std::string DimensionalityMismatchEx::getName() const {
        return __name;
    }

    std::ostream &operator<<(std::ostream &os, const DimensionalityMismatchEx &ex) {
        os << ex.__name << ": " << ex.__current << " : " << ex.__rhs << std::endl;
    }

    // Zero clusters
    ZeroClustersEx::ZeroClustersEx() {
        __name = "ZeroClustersEx";
    }
    std::string ZeroClustersEx::getName() const {
        return __name;
    }

    std::ostream &operator<<(std::ostream &os, const ZeroClustersEx &ex) {
        os << ex.__name << std::endl;
    }

    // Data file open
    DataFileOpenEx::DataFileOpenEx(std::string filename) {
        __filename = filename;
        __name = "DataFileOpenEx";
    }
    std::string DataFileOpenEx::getFilename() const {
        return __filename;
    }
    std::string DataFileOpenEx::getName() const {
        return __name;
    }

    std::ostream &operator<<(std::ostream &os, const DataFileOpenEx &ex) {
        os << ex.__name << ": " << ex.__filename << std::endl;
    }

    // Zero Dimensions
    ZeroDimensionsEx::ZeroDimensionsEx() {
        __name = "ZeroDimensionsEx";
    }
    std::string ZeroDimensionsEx::getName() const {
        return __name;
    }

    std::ostream &operator<<(std::ostream &os, const ZeroDimensionsEx &ex) {
        os << ex.__name;
    }

    // Empty Cluster
    EmptyClusterEx::EmptyClusterEx() {
        __name = "EmptyClusterEx";
    }
    std::string EmptyClusterEx::getName() const {
        return __name;
    }

    std::ostream &operator<<(std::ostream &os, const EmptyClusterEx &ex) {
        os << ex.__name << std::endl;
    }
}
