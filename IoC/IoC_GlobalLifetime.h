/***
 * 
 * Copyright 10/12/2015 William wi11berto@yahoo.co.uk
 *  
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *  
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
***/

#pragma once

#include "IoC_Lifetime.h"

namespace ioc {
	class IOC_EXPORTS IoC_GlobalLifetime : public IoC_Lifetime 
	{
		void * instance;
	public:
		IoC_GlobalLifetime();
		virtual ~IoC_GlobalLifetime();

		void * getInstance(IoC_Entry *) override;
		void deleteInstance(IoC_Entry *) override;
	};
}
