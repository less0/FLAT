#include "UnitTest++.h"
#include "intparameter.h"
#include "intparametertype.h"
#include "intparameterconverter.h"
#include "doubleparameterconverter.h"

using namespace FLAT;
using namespace std;

namespace
{
    TEST(TestGetIntParameterConverter)
    {
        shared_ptr<IntParameterType> parameterType(new IntParameterType());
        shared_ptr<IntParameterConverter> parameterConverter(dynamic_pointer_cast<IntParameterConverter>(parameterType->getConverter()));

        CHECK_EQUAL(false, parameterConverter == 0);
    }

    TEST(TestInvalidDoublePointerCast)
    {
        shared_ptr<IntParameterType> parameterType(new IntParameterType());
        shared_ptr<DoubleParameterConverter> parameterConverter(dynamic_pointer_cast<DoubleParameterConverter>(parameterType->getConverter()));

        CHECK_EQUAL(true, parameterConverter == 0);
    }

    TEST(GetIntParameter)
    {
        shared_ptr<IntParameterConverter> parameterConverter(new IntParameterConverter());
        shared_ptr<IntParameter> parameter(dynamic_pointer_cast<IntParameter>(parameterConverter->convertValue("FooBar", "42")));

        CHECK_EQUAL(false, parameter == 0);
    }

    TEST(ConvertIntValue)
    {
        shared_ptr<IntParameterConverter> parameterConverter(new IntParameterConverter());
        shared_ptr<IntParameter> parameter(dynamic_pointer_cast<IntParameter>(parameterConverter->convertValue("Foo", "23")));

        CHECK_EQUAL(23, parameter->getIntValue());
    }

    TEST(ConvertIntName)
    {
        shared_ptr<IntParameterConverter> parameterConverter(new IntParameterConverter());
        shared_ptr<IntParameter> parameter(dynamic_pointer_cast<IntParameter>(parameterConverter->convertValue("Bar", "28")));

        CHECK_EQUAL(false, parameter == 0);
        CHECK_EQUAL("Bar", parameter->getName());
    }

    TEST(CreateParameterDirect)
    {
        shared_ptr<IntParameter> parameter(new IntParameter("BarFoo", 312));

        CHECK_EQUAL(312, parameter->getIntValue());
        CHECK_EQUAL("BarFoo", parameter->getName());

    }

    TEST(GetValuePointer)
    {
        shared_ptr<IntParameter> parameter(new IntParameter("BarBar", 6485));

        CHECK_EQUAL(6485, *(int*)parameter->getValue());
    }
}
