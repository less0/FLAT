#include "doubleparametertype.h"

using namespace FLAT;

DoubleParameterType::DoubleParameterType()
{
    m_converter = shared_ptr<ParameterConverter>(new DoubleParameterConverter());
}

DoubleParameterType::~DoubleParameterType()
{
    //dtor
}

shared_ptr<ParameterConverter> DoubleParameterType::getConverter()
{
    return m_converter;
}
