#ifndef PARAMETERIZABLE_H
#define PARAMETERIZABLE_H

#include <string>

using namespace std;

namespace FLAT
{
    ///\brief Interface for objects than can take generisized parameters
    ///\todo Change interface
    class Parameterizable
    {
        public:
            virtual void setParameter(int parameterNumber, const void* data) = 0;
            virtual void setParameter(string parameterName, const void* data) = 0;

            virtual int getNumParameters() = 0;
            virtual string getParameterName(int parameterNumber) = 0;
            virtual string getParameterType(int parameterNumber) = 0;
            virtual string getParameterType(string parameterName) = 0;
            virtual const void* getParameter(int parameterNumber) = 0;
            virtual const void* getParameter(string parameterName) = 0;
        protected:
        private:
    };
}


#endif // PARAMETERIZABLE_H
