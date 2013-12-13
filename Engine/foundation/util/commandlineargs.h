#pragma once
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

#include "util/array.h"
#include "util/string.h"

//------------------------------------------------------------------------------
namespace Util
{
class CommandLineArgs
{
public:
    /// default constructor
    CommandLineArgs();
    /// construct from Win32-style command string
    CommandLineArgs(const String& cmdLine);
    /// construct from posix style command string
    CommandLineArgs(int argc, const char** argv);
    /// get the command name
    const String& GetCmdName() const;
    /// return true if arg exists
    bool HasArg(const String& arg) const;
    /// get string value
    const String& GetString(const String& name, const String& defaultValue = "") const;
    /// get int value
    int GetInt(const String& name, int defaultValue = 0) const;
    /// get float value
    float GetFloat(const String& name, float defaultValue = 0.0f) const;
    /// get bool value (key=value)
    bool GetBool(const String& name, bool defaultValue=false) const;
    /// get bool flag (args only needs to exist to trigger as true)
    bool GetBoolFlag(const String& name) const;
    #if !__OSX__
    /// get float4 value 
    Math::float4 GetFloat4(const String& name, const Math::float4& defaultValue = Math::float4()) const;
    /// get matrix44 value
    Math::matrix44 GetMatrix44(const String& name, const Math::matrix44& defaultValue = Math::matrix44()) const;
    #endif
    
    /// get number of arguments (exluding command name)
    SizeT GetNumArgs() const;
    /// get string argument at index
    const String& GetStringAtIndex(IndexT index) const;
    /// get int value at index
    int GetIntAtIndex(IndexT index) const;
    /// get float value at index
    float GetFloatAtIndex(IndexT index) const;
    /// get bool value at index
    bool GetBoolAtIndex(IndexT index) const;
    #if !__OSX__
    /// get float4 value at index
    Math::float4 GetFloat4AtIndex(IndexT index) const;
    /// get matrix44 value at index
    Math::matrix44 GetMatrix44AtIndex(IndexT index) const;
    #endif
    /// append other command string
    void AppendCommandString(const CommandLineArgs& otherArgs);

private:
    /// put out an error
    void Error(const String& argName) const;
    /// find index of argument, fails hard with error msg if not found
    int FindArgIndex(const String& argName) const;

    Array<String> args;
};

} // namespace Util
//------------------------------------------------------------------------------
