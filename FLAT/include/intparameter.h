#ifndef FLAT_INTPARAMETER_H
#define FLAT_INTPARAMETER_H

#include <parameter.h>

namespace FLAT {

class IntParameter : public FLAT::Parameter
{
    public:
        /** Default constructor */
        IntParameter();

        IntParameter(string name, int value)
        {
            m_name = name;
            m_value = value;
        }

        /*! \brief Gets the integer value assigned to the parameter
        */
        int getIntValue()
        {
            return m_value;
        }

        /*! \brief Gets a pointer to a copy of the value assigned to the
        * parameter
        */
        const void* getValue()
        {
            int* pValue = new int;

            *pValue = m_value;

            return (void*)pValue;
        }
    protected:
    private:
        int m_value;
};

} // namespace FLAT

#endif // FLAT_INTPARAMETER_H
