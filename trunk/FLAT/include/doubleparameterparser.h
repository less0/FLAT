#ifndef DOUBLEPARAMETERPARSER_H
#define DOUBLEPARAMETERPARSER_H

#include <parameterparser.h>


class DoubleParameterParser : public FLAT::ParameterParser
{
    public:
        /** Default constructor */
        DoubleParameterParser();
        /** Copy constructor
         *  \param other Object to copy from
         */
        DoubleParameterParser(const DoubleParameterParser& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        DoubleParameterParser& operator=(const DoubleParameterParser& other);

        Parameter
    protected:
    private:
};

#endif // DOUBLEPARAMETERPARSER_H
