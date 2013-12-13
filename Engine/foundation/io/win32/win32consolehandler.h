/****************************************************************************
Copyright (c) 2006, Radon Labs GmbH
Copyright (c) 2011-2013,WebJet Business Division,CYOU
 
http://www.genesis-3d.com.cn

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#pragma once
#ifndef WIN32_WIN32CONSOLEHANDLER_H
#define WIN32_WIN32CONSOLEHANDLER_H
//------------------------------------------------------------------------------
/**
    @class Win32::Win32ConsoleHandler
    
    The default console handler for Win32, puts normal messages to
    the debug output channel, and error messages into a message box.
    Does not provide any input.

*/
#include "io/consolehandler.h"

//------------------------------------------------------------------------------
namespace Win32
{
class Win32ConsoleHandler : public IO::ConsoleHandler
{
    __DeclareClass(Win32ConsoleHandler);
public:
    /// constructor
    Win32ConsoleHandler();
    
    /// called by console to output data
    virtual void Print(const Util::String& s);
    /// called by console with serious error
    virtual void Error(const Util::String& s);
    /// called by console to output warning
    virtual void Warning(const Util::String& s);
    /// called by console to display confirmation message box
    virtual void Confirm(const Util::String& s);
    /// called by console to output debug string
    virtual void DebugOut(const Util::String& s);
    /// return true if input is available
    virtual bool HasInput();
    /// read available input
    virtual Util::String GetInput();

private:
    HANDLE stdoutHandle;
    HANDLE stdinHandle;
    HANDLE stderrHandle;
};

}; // namespace Win32
//------------------------------------------------------------------------------
#endif