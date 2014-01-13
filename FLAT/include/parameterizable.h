#ifndef PARAMETERIZABLE_H
#define PARAMETERIZABLE_H

#include <string>
#include <memory>
#include "parameter.h"
#include "parametertype.h"

using namespace std;

namespace FLAT
{
    /*! \brief Interface for objects than can take generic parameters
     *
     * Classes like terrain generators, erosion algorithms and like are not
     * very useful with static properties. Dynamiic properties allow to match
     * details of the strategies to the needs one has. Anyway, a static
     * interface for parameters is not always applicable either, for some
     * algorithms take other parameters than others. Therefor, this class
     * provides an unified interface for parameterizable objects.
     *
     * \sa Parameter ParameterType ParameterConverter
     */
    class Parameterizable
    {
        public:
            virtual void setParameter(shared_ptr<Parameter> data) = 0;
            virtual void setParameter(string parameterName, shared_ptr<Parameter> data) = delete;

            virtual int getNumParameters() = 0;
            virtual string getParameterName(int parameterNumber) = 0;
            virtual shared_ptr<ParameterType> getParameterType(int parameterNumber) = 0;
            virtual shared_ptr<ParameterType> getParameterType(string parameterName) = 0;
            /*! \brief Returns a pointer to a copy of the respective parameter
            */
            virtual shared_ptr<Parameter> getParameter(int parameterNumber) = 0;
            /*! \brief Returns a pointer to a copy of the respective parameter
            */
            virtual shared_ptr<Parameter> getParameter(string parameterName) = 0;
        protected:
        private:
    };
}


#endif // PARAMETERIZABLE_H
