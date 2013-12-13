/****************************************************************************
Copyright (c) 2007,RadonLabs GmbH
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
#ifndef MATH_FLOAT2_H
#define MATH_FLOAT2_H
//------------------------------------------------------------------------------
/**
    @class Math::float2

    A 2-component float vector class.

*/
#include "core/types.h"
#include "math/scalar.h"

//------------------------------------------------------------------------------
namespace Math
{
class float2
{
public:
    /// default constructor, NOTE: does NOT setup components!
    float2();
    /// construct from values
    float2(scalar x, scalar y);
    /// copy constructor
    float2(const float2& rhs);
    /// assignment operator
    void operator=(const float2& rhs);
    /// flip sign
    float2 operator-() const;
    /// inplace add
    void operator+=(const float2& rhs);
    /// inplace sub
    void operator-=(const float2& rhs);
    /// inplace scalar multiply
    void operator*=(scalar s);
    /// add 2 vectors
    float2 operator+(const float2& rhs) const;
    /// subtract 2 vectors
    float2 operator-(const float2& rhs) const;
    /// multiply with scalar
    float2 operator*(scalar s) const;
    /// equality operator
    bool operator==(const float2& rhs) const;
    /// inequality operator
    bool operator!=(const float2& rhs) const;
    /// set content
    void set(scalar x, scalar y);
    /// read/write access to x component
    scalar& x();
    /// read/write access to y component
    scalar& y();
    /// read-only access to x component
    scalar x() const;
    /// read-only access to y component
    scalar y() const;

    /// return length of vector
    scalar length() const;
    /// return squared length of vector
    scalar lengthsq() const;
    /// return compononent-wise absolute
    float2 abs() const;    
    /// return true if any components are non-zero
    bool any() const;
    /// return true if all components are non-zero
    bool all() const;
    /// return vector made up of largest components of 2 vectors
    static float2 maximize(const float2& v0, const float2& v1);
    /// return vector made up of smallest components of 2 vectors
    static float2 minimize(const float2& v0, const float2& v1);
    /// return normalized version of vector
    static float2 normalize(const float2& v);
    /// set less-then components to non-zero 
    static float2 lt(const float2& v0, const float2& v1);
    /// set less-or-equal components to non-zero
    static float2 le(const float2& v0, const float2& v1);
    /// set greater-then components to non-zero
    static float2 gt(const float2& v0, const float2& v1);
    /// set greater-or-equal components to non-zero
    static float2 ge(const float2& v0, const float2& v1);

    /// convert to anything
    template<typename T> T as() const;

protected:
    scalar X;
    scalar Y;
};

//------------------------------------------------------------------------------
/**
*/
inline
float2::float2() : X(0.0f),Y(0.0f)
{
    //  empty
}

//------------------------------------------------------------------------------
/**
*/
inline 
float2::float2(scalar x, scalar y) :
    X(x), Y(y)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
inline
float2::float2(const float2& rhs) :
    X(rhs.X), Y(rhs.Y)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
inline void
float2::operator=(const float2& rhs)
{
    this->X = rhs.X;
    this->Y = rhs.Y;
}

//------------------------------------------------------------------------------
/**
*/
inline bool
float2::operator==(const float2& rhs) const
{
    return (this->X == rhs.X) && (this->Y == rhs.Y);
}

//------------------------------------------------------------------------------
/**
*/
inline bool
float2::operator!=(const float2& rhs) const
{
    return (this->X != rhs.X) || (this->Y != rhs.Y);
}

//------------------------------------------------------------------------------
/**
*/
inline float2
float2::operator-() const
{
    return float2(-this->X, -this->Y);
}

//------------------------------------------------------------------------------
/**
*/
inline float2
float2::operator*(scalar t) const
{
    return float2(this->X * t, this->Y * t);
}

//------------------------------------------------------------------------------
/**
*/
inline void
float2::operator+=(const float2& rhs)
{
    this->X += rhs.X;
    this->Y += rhs.Y;
}

//------------------------------------------------------------------------------
/**
*/
inline void
float2::operator-=(const float2& rhs)
{
    this->X -= rhs.X;
    this->Y -= rhs.Y;
}

//------------------------------------------------------------------------------
/**
*/
inline void
float2::operator*=(scalar s)
{
    this->X *= s;
    this->Y *= s;
}

//------------------------------------------------------------------------------
/**
*/
inline float2
float2::operator+(const float2& rhs) const
{
    return float2(this->X + rhs.X, this->Y + rhs.Y);
}

//------------------------------------------------------------------------------
/**
*/
inline float2
float2::operator-(const float2& rhs) const
{
    //return float2(this->X + rhs.X, this->Y + rhs.Y);
	return float2(this->X - rhs.X, this->Y - rhs.Y);
}

//------------------------------------------------------------------------------
/**
*/
inline void
float2::set(scalar x, scalar y)
{
    this->X = x;
    this->Y = y;
}

//------------------------------------------------------------------------------
/**
*/
inline scalar&
float2::x()
{
    return this->X;
}

//------------------------------------------------------------------------------
/**
*/
inline scalar
float2::x() const
{
    return this->X;
}

//------------------------------------------------------------------------------
/**
*/
inline scalar&
float2::y()
{
    return this->Y;
}

//------------------------------------------------------------------------------
/**
*/
inline scalar
float2::y() const
{
    return this->Y;
}

//------------------------------------------------------------------------------
/**
*/
inline scalar
float2::length() const
{
    return n_sqrt(this->X * this->X + this->Y * this->Y);
}

//------------------------------------------------------------------------------
/**
*/
inline scalar
float2::lengthsq() const
{
    return this->X * this->X + this->Y * this->Y;
}

//------------------------------------------------------------------------------
/**
*/
inline float2
float2::abs() const
{
    return float2(n_abs(this->X), n_abs(this->Y));
}

//------------------------------------------------------------------------------
/**
*/
inline bool
float2::any() const
{
    return (this->X != 0.0f) || (this->Y != 0.0f);
}

//------------------------------------------------------------------------------
/**
*/
inline bool
float2::all() const
{
    return (this->X != 0.0f) && (this->Y != 0.0f);
}

//------------------------------------------------------------------------------
/**
*/
inline float2
float2::lt(const float2& v0, const float2& v1)
{
    float2 res;
    res.X = (v0.X < v1.X) ? 1.0f : 0.0f;
    res.Y = (v0.Y < v1.Y) ? 1.0f : 0.0f;
    return res;
}

//------------------------------------------------------------------------------
/**
*/
inline float2
float2::le(const float2& v0, const float2& v1)
{
    float2 res;
    res.X = (v0.X <= v1.X) ? 1.0f : 0.0f;
    res.Y = (v0.Y <= v1.Y) ? 1.0f : 0.0f;
    return res;
}

//------------------------------------------------------------------------------
/**
*/
inline float2
float2::gt(const float2& v0, const float2& v1)
{
    float2 res;
    res.X = (v0.X > v1.X) ? 1.0f : 0.0f;
    res.Y = (v0.Y > v1.Y) ? 1.0f : 0.0f;
    return res;
}

//------------------------------------------------------------------------------
/**
*/
inline float2
float2::ge(const float2& v0, const float2& v1)
{
    float2 res;
    res.X = (v0.X >= v1.X) ? 1.0f : 0.0f;
    res.Y = (v0.Y >= v1.Y) ? 1.0f : 0.0f;
    return res;
}

//------------------------------------------------------------------------------
/**
*/
inline float2
float2::normalize(const float2& v)
{
    scalar l = v.length();
    if (l > 0.0f)
    {
        return float2(v.X / l, v.Y / l);
    }
    else
    {
        return float2(1.0f, 0.0f);
    }
}

//------------------------------------------------------------------------------
/**
*/
inline float2
float2::maximize(const float2& v0, const float2& v1)
{
    return float2(n_max(v0.X, v1.X), n_max(v0.Y, v1.Y));
}

//------------------------------------------------------------------------------
/**
*/
inline float2
float2::minimize(const float2& v0, const float2& v1)
{
    return float2(n_min(v0.X, v1.X), n_min(v0.Y, v1.Y));
}

} // namespace Math
//------------------------------------------------------------------------------
#endif
