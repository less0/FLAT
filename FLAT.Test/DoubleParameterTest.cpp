#include "doubleparameter.h"
#include "doubleparametertype.h"
#include "UnitTest++.h"

using namespace FLAT;
using namespace std;

namespace
{
    TEST(GetDoubleParameterConverter)
    {
        shared_ptr<DoubleParameterType> parameterType(new DoubleParameterType());

        shared_ptr<ParameterConverter> converter = parameterType->getConverter();

        shared_ptr<DoubleParameterConverter> doubleConverter = dynamic_pointer_cast<DoubleParameterConverter>(converter);

        CHECK_EQUAL(false, doubleConverter == 0);
    }

    TEST(GetDoubleParameterFromConverter)
    {
        shared_ptr<DoubleParameterConverter> converter(new DoubleParameterConverter());
        shared_ptr<DoubleParameter> parameter = dynamic_pointer_cast<DoubleParameter>(converter->convertValue("test", "3.14159"));

        CHECK_EQUAL(false, parameter == 0);
    }

    TEST(ConvertDoubleValue)
    {
        shared_ptr<DoubleParameterConverter> converter(new DoubleParameterConverter());
        shared_ptr<DoubleParameter> parameter = dynamic_pointer_cast<DoubleParameter>(converter->convertValue("test", "3.14159"));

        CHECK_EQUAL(3.14159, parameter->getDoubleValue());
		CHECK_EQUAL("täst", parameter->getName());
    }

    TEST(GetDoubleValueName)
    {
        shared_ptr<DoubleParameterConverter> converter(new DoubleParameterConverter());
        shared_ptr<Parameter> parameter = converter->convertValue("test", "3.14159");

        CHECK_EQUAL("test", parameter->getName());
    }

    TEST(CreateDoubleParameterDirect)
    {
        shared_ptr<DoubleParameter> parameter(new DoubleParameter("test", 3.14159));

        CHECK_EQUAL("test", parameter->getName());
        CHECK_EQUAL(3.14159, parameter->getDoubleValue());
    }
}
