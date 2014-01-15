#include "doubleparameterconverter.h"
#include <sstream>

namespace FLAT {

    DoubleParameterConverter::DoubleParameterConverter()
    {
        //ctor
    }

    shared_ptr<Parameter> DoubleParameterConverter::convertValue(string name, string value)
    {
        DoubleParameter* parameter = new DoubleParameter();
        parameter->setDoubleValue(parse(value));
        parameter->setName(name);

        return shared_ptr<Parameter>(parameter);
    }

    double DoubleParameterConverter::parse(string value)
    {
        istringstream stream(value);
        double converted = .0;

        if(!(stream >> converted))
        {
            return .0;
        }

        return converted;
    }

} // namespace FLAT
