#ifndef FLAT_INTPARAMETERCONVERTER_H
#define FLAT_INTPARAMETERCONVERTER_H

#include <parameterconverter.h>

namespace FLAT {

class IntParameterConverter : public FLAT::ParameterConverter
{
    public:
        /** Default constructor */
        IntParameterConverter();

        shared_ptr<Parameter> convertValue(string name, string valueRepresentation);
    protected:
    private:
};

} // namespace FLAT

#endif // FLAT_INTPARAMETERCONVERTER_H
