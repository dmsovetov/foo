/**************************************************************************

 The MIT License (MIT)

 Copyright (c) 2015 Dmitry Sovetov

 https://github.com/dmsovetov

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

 **************************************************************************/

#ifndef __Foo_H__
#define __Foo_H__

#define FOO_INCLUDED

#ifdef FOO_NAMESPACE
    #define FOO_BEGIN_NAMESPACE namespace FOO_NAMESPACE {
    #define FOO_END_NAMESPACE   }
    #define USING_FOO using namespace FOO_NAMESPACE;
#else
    #define FOO_BEGIN_NAMESPACE
    #define FOO_END_NAMESPACE
    #define USING_FOO
#endif

#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>

#include "Preprocessor.h"
#include "Exception.h"
#include "Logger.h"
#include "StringHash.h"
#include "Format.h"
#include "Classes.h"
#include "Bitset.h"
#include "UserData.h"
#include "Guid.h"
#include "Composition.h"

FOO_BEGIN_NAMESPACE
    #include "delegate/Closure.h"
FOO_END_NAMESPACE

#include "memory/WeakPtr.h"
#include "memory/StrongPtr.h"
#include "memory/AutoPtr.h"

#include "Types.h"

#include "Variant.h"

FOO_BEGIN_NAMESPACE

    const float Pi		= 3.1415926535897932f;
	const float Epsilon	= 0.0001f;

	//! Calculates the next power of two of a given number.
	inline unsigned int nextPowerOf2( unsigned int n )
	{
		unsigned count = 0;

		/* First n in the below condition is for the case where n is 0*/
		if( n && !(n & (n - 1)) ) {
			return n;
		}

		while( n != 0 )
		{
			n >>= 1;
			count += 1;
		}
    
		return 1 << count;
	}

    //! Generates a random value in a [0, 1] range.
    inline float rand0to1( void ) {
        static float invRAND_MAX = 1.0f / RAND_MAX;
        return rand() * invRAND_MAX;
    }

    //! Does a linear interpolation between two values.
    inline float lerp( float a, float b, float scalar ) {
        return a * scalar + b * (1.0f - scalar);
    }

	//! Returns true if three float values are equal.
	inline float equal3( float a, float b, float c, float eps = 0.001f )
	{
		return fabs( a - b ) <= eps && fabs( b - c ) <= eps && fabs( c - a ) <= eps;
	}

    //! Returns a minimum value of two.
    inline float min2( float a, float b ) {
        return a < b ? a : b;
    }

    //! Returns a minimum value of three.
    inline float min3( float a, float b, float c ) {
        return min2( a, min2( b, c ) );
    }

    //! Returns a maximum value of two.
    inline float max2( float a, float b ) {
        return a > b ? a : b;
    }

    //! Returns a maximum value of three.
    inline float max3( float a, float b, float c ) {
        return max2( a, max2( b, c ) );
    }

    //! Converts degrees to radians
    inline float radians( float degrees ) {
        return (degrees) / 180.0f * Pi;
    }

    //! Converts degrees to radians
    inline float degrees( float radians ) {
        return (radians) * 180.0f / Pi;
    }

	//! Returns true if an argument is not a number.
	inline bool isNaN( float value )
	{
	#ifdef WIN32
		return _isnan( value ) ? true : false;
	#else
		return isnan( value );
	#endif
	}

FOO_END_NAMESPACE

#endif  /*  !defined( __Foo_H__ ) */
