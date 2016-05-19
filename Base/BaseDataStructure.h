
#ifndef BASE_DATA_STRUCTURES_H
#define BASE_DATA_STRUCTURES_H

#include "DSErrors.h"

template <class T>
class BaseDataStructure
{
public:
    BaseDataStructure()
    {
        clearError();
    }

    bool isError()
    {
        return _error != None;
    }

    DSError getError()
    {
        return _error;
    }

    void clearError()
    {
        _error = None;
    }

    const char *getErrorMessage()
    {
        return _errorMsgs[_error];
    }

    virtual size_t size() = 0;

protected:
    void raiseError(DSError e)
    {
        _error = e;
    }

private:
    DSError _error;

    static const char *_errorMsgs[];
};

template <class T>
const char *BaseDataStructure<T>::_errorMsgs[] = {"None", "No memory", "Is full", "Is Empty",
   "Invalid Index", "Invalid Argument", "Unknown", ""};

#endif
