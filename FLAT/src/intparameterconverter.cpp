#include "intparameterconverter.h"
#include "intparameter.h"
#include <sstream>

using namespace std;

namespace FLAT {

IntParameterConverter::IntParameterConverter()
{
    //ctor
}

    shared_ptr<Parameter> IntParameterConverter::convertValue(string name, string valueRepresentation)
    {
        stringstream str(valueRepresentation);
        int value = 0;

        if(!(str >> value))
        {
            return shared_ptr<Parameter>(0);
        }

        return shared_ptr<Parameter>(new IntParameter(name, value));
    }

} // namespace FLAT
