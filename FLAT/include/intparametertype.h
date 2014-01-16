#ifndef FLAT_INTPARAMETERTYPE_H
#define FLAT_INTPARAMETERTYPE_H

#include <parametertype.h>

namespace FLAT {

class IntParameterType : public FLAT::ParameterType
{
    public:
        /** Default constructor */
        IntParameterType();
        shared_ptr<ParameterConverter> getConverter();
    protected:
    private:
};

} // namespace FLAT

#endif // FLAT_INTPARAMETERTYPE_H
