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

#include "IoC_LocalLifetime.h"
#include "IoC_Container.h"
#include "IoC_Entry.h"

ioc::IoC_LocalLifetime::IoC_LocalLifetime()
{
}

ioc::IoC_LocalLifetime::~IoC_LocalLifetime()
{
	instances.clear();
}

void ioc::IoC_LocalLifetime::deleteInstance(IoC_Entry * entry)
{
	auto release = entry->getDeleteHandler();

	for (auto& ptr : instances) {
		release(ptr);
	}
}

ioc::IoC_Type ioc::IoC_LocalLifetime::getInstance(ioc::IoC_Entry * entry)
{
	IoC_Type type = entry->getCreateHandler()();
	instances.push_back(type);
	return type;
}
		