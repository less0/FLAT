#include "error.h"

#ifndef ERRORDEPLOYER_H
#define ERRORDEPLOYER_H

#include <memory>

namespace FLAT
{
    class ErrorDeployer
    {
    public:
        virtual ~ErrorDeployer() = 0;
        virtual shared_ptr<Error> getLastError() = 0;
    };
}


#endif
