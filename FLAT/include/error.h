#include <string>

#ifndef ERROR_H
#define ERROR_H

using namespace std;

namespace FLAT
{
    class Error
    {
    private:
        int m_id;
        string m_msg;

    public:
        virtual int getId();
        virtual string getMessage();

        virtual void setId(int id);
        virtual void setMessage(string msg);

        Error(void);
        Error(int id, string msg);
        Error(const Error& base);
        ~Error(void);
    };
}


#endif
