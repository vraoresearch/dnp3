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
#ifndef __LOG_TYPES_H_
#define __LOG_TYPES_H_

namespace apl {

enum FilterLevel
{
	LEV_EVENT =		0x01,
	LEV_ERROR =		0x02,
	LEV_WARNING =	0x04,
	LEV_INFO  =		0x08,
	LEV_INTERPRET =	0x10,
	LEV_COMM =		0x20,
	LEV_DEBUG =		0x40
};

/// Converts a filter level enumeration to a mask with all higher levels set
int FilterLevelToMask(FilterLevel);

}

#endif

