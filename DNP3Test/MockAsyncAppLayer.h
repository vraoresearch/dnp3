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
#ifndef __MOCK_ASYNC_APP_LAYER_H_
#define __MOCK_ASYNC_APP_LAYER_H_


#include <DNP3/AsyncAppInterfaces.h>
#include <DNP3/APDUConstants.h>
#include <DNP3/APDU.h>
#include <APL/Loggable.h>
#include <queue>

namespace apl {
	class Logger;
}

namespace apl { namespace dnp {

/**	@section desc Test class to mock async app layer for master/slave */
class MockAsyncAppLayer : public IAsyncAppLayer, public Loggable
{
	public:
		MockAsyncAppLayer(Logger*);
		virtual ~MockAsyncAppLayer() {}


		void SetUser(IAsyncAppUser*);

		void SendResponse(APDU&);
		void SendUnsolicited(APDU&);
		void SendRequest(APDU&);
		void CancelResponse();

		size_t mNumCancel;

		void EnableAutoSendCallback(bool aIsSuccess);
		void DisableAutoSendCallback();

		APDU Read();
		size_t Count() { return mFragments.size(); }
		FunctionCodes ReadFunction();
		size_t NumAPDU() { return mFragments.size(); }

	private:

		void DoSendUnsol();
		void DoSendSol();

		IAsyncAppUser* mpUser;
		bool mAutoSendCallback;
		bool mIsSuccess;
		std::deque<APDU> mFragments;
};

}}

#endif

