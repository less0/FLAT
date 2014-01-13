#ifndef DOUBLEPARAMETERCONVERTER_H
#define DOUBLEPARAMETERCONVERTER_H

#include <doubleparameter.h>
#include <parameterconverter.h>

namespace FLAT {

class DoubleParameterConverter : public ParameterConverter
{
    public:
        /** Default constructor */
        DoubleParameterConverter();

        shared_ptr<Parameter> convertValue(string name, string stringRepresentation);
    protected:
    private:
        double parse(string);
};

} // namespace FLAT

#endif // DOUBLEPARAMETERCONVERTER_H
