//
// Licensed to Green Energy Corp (www.greenenergycorp.com) under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  Green Enery Corp licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//
#ifndef __TYPES_H_
#define __TYPES_H_

namespace apl
{
	//byte types
	typedef unsigned char byte_t;

	//16 bit types
	typedef signed short int_16_t;
	typedef unsigned short uint_16_t;

	//32 bit types
	typedef signed int int_32_t;
	typedef unsigned int uint_32_t;

	//64 bit types
	typedef long long int_64_t;
	typedef unsigned long long uint_64_t;

#ifndef SIZE_MAX
	#define SIZE_MAX ~0
#endif

	typedef int_64_t millis_t;

#ifdef _DEBUG
//#define STRONGLY_TYPED_TIMESTAMPS
#endif

#ifdef STRONGLY_TYPED_TIMESTAMPS

	class TimeStamp_t_Explicit{
		millis_t value;
	public:
		explicit TimeStamp_t_Explicit(millis_t aT):value(aT){}
		operator millis_t () const { return value;}

	};

	class UTCTimeStamp_t_Explicit{
		millis_t value;
	public:
		explicit UTCTimeStamp_t_Explicit(millis_t aT):value(aT){}
		operator millis_t () const { return value;}

	};

	//this is some c++ trickery to make sure that we get strong
	//typesaftey on the 2 different types of timestamp
	typedef TimeStamp_t_Explicit TimeStamp_t;
	typedef UTCTimeStamp_t_Explicit UTCTimeStamp_t;

#else
	//if we are not using the strong typing it should be faster
	//since the values are all simple 64bit value types rather than
	//overloaded classes.
	typedef millis_t TimeStamp_t;
	typedef millis_t UTCTimeStamp_t;

#endif
} //end namespace

#endif
