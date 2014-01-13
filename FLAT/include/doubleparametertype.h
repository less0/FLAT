#ifndef DOUBLEPARAMETERTYPE_H
#define DOUBLEPARAMETERTYPE_H

#include <doubleparameterconverter.h>
#include <parametertype.h>

namespace FLAT
{
    class DoubleParameterType : public ParameterType
    {
        public:
            /** Default constructor */
            DoubleParameterType();
            /** Default destructor */
            virtual ~DoubleParameterType();

            shared_ptr<ParameterConverter> getConverter();

        protected:
        private:
            shared_ptr<ParameterConverter> m_converter;
    };
}

#endif // DOUBLEPARAMETERTYPE_H
