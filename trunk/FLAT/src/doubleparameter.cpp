#include "doubleparameter.h"

using namespace FLAT;

DoubleParameter::DoubleParameter()
{
    m_name = "";
    m_value = .0;
}

DoubleParameter::~DoubleParameter()
{
    //dtor
}

DoubleParameter::DoubleParameter(const DoubleParameter& other)
{
    //copy ctor
    this->m_name = other.m_name;
    this->m_value = other.m_value;
}

DoubleParameter& DoubleParameter::operator=(const DoubleParameter& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->m_name = rhs.m_name;
    this->m_value = rhs.m_value;

    //assignment operator
    return *this;
}
