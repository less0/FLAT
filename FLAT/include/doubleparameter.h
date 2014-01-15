#ifndef DOUBLEPARAMETER_H
#define DOUBLEPARAMETER_H

#include <string>
#include <memory>
#include <parameter.h>

using namespace std;

namespace FLAT
{
    class DoubleParameter : public Parameter
    {
        public:
            /** Default constructor */
            DoubleParameter();

            DoubleParameter(string name, double value)
            {
                m_value = value;
                m_name = name;
            }
            /** Default destructor */
            virtual ~DoubleParameter();
            /** Copy constructor
             *  \param other Object to copy from
             */
            DoubleParameter(const DoubleParameter& other);
            /** Assignment operator
             *  \param other Object to assign from
             *  \return A reference to this
             */
            DoubleParameter& operator=(const DoubleParameter& other);

            /** \brief Gets the value of the parameter as a double */
            double getDoubleValue()
            {
                return m_value;
            }

            /** \brief Sets the value of the parameter
            */
            void setDoubleValue(double value)
            {
                m_value = value;
            }

            const void* getValue()
            {
                double* temp_value = new double;
                *temp_value = m_value;

                return (void*)temp_value;
            }
        protected:
        private:
            double m_value;
    };
}

#endif // DOUBLEPARAMETER_H
