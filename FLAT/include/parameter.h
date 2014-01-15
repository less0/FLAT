#ifndef PARAMETER_H
#define PARAMETER_H

#include <string>

using namespace std;

namespace FLAT
{
    /*! \brief Abstract base class that represents a parameter that can be passed
    * to Parametrizable objects.
    *
    */
    class Parameter
    {
        public:
            /*! \brief Returns a void pointer to the value if the parameter
             *
             * This method **does not** return a pointer to the actual variable
             * but to a copy of it. The copy is not destroyed automatically, if
             * this function is used to obtain the value of the parameter the
             * user is resposible for deleting the variable
             */
            virtual const void * getValue() = 0;

            string getName()
            {
                return m_name;
            }

            void setName(string name)
            {
                m_name = name;
            }
        protected:
            string m_name;
        private:

    };
}

#endif // PARAMETER_H
