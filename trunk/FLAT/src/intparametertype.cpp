#include "intparametertype.h"
#include "intparameterconverter.h"

namespace FLAT {

    IntParameterType::IntParameterType()
    {
        //ctor
    }

    shared_ptr<ParameterConverter> IntParameterType::getConverter()
    {
        return shared_ptr<ParameterConverter>(new IntParameterConverter());
    }

} // namespace FLAT
