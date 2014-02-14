#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

using namespace std;

namespace FLAT
{
    class Exception
    {
        public:
            /** Default constructor */
            Exception();

            Exception(string message)
            {
                m_message = message;
            }
            /** Default destructor */
            virtual ~Exception();
            /** Copy constructor
             *  \param other Object to copy from
             */
            Exception(const Exception& other);
            /** Assignment operator
             *  \param other Object to assign from
             *  \return A reference to this
             */
            Exception& operator=(const Exception& other);
        protected:
            string m_message;
            string m_stackTrace;
        private:
    };
}

#endif // EXCEPTION_H
