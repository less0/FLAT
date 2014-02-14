#include "exception.h"

using namespace FLAT;

Exception::Exception()
{
    //ctor
}

Exception::~Exception()
{
    //dtor
}

Exception::Exception(const Exception& other)
{
    //copy ctor
    this->m_message = other.m_message;
    this->m_stackTrace = other.m_stackTrace;
}

Exception& Exception::operator=(const Exception& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
