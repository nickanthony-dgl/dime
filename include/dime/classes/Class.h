/**************************************************************************\
 * Copyright (c) Kongsberg Oil & Gas Technologies AS
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

#ifndef DIME_CLASS_H
#define DIME_CLASS_H

#include <dime/Base.h>
#include <dime/Basic.h>
#include <dime/util/Array.h>
#include <dime/util/Linear.h>
#include <dime/RecordHolder.h>

class dimeInput;
class DimeMemHandler;
class dimeOutput;
class dimeModel;

class DIME_DLL_API dimeClass : public dimeRecordHolder
{
	friend class DimeClassesSection;
	friend class dimeModel;

public:
	dimeClass();
	~dimeClass() override;

	virtual const char* getDxfClassName() const = 0;
	virtual dimeClass* copy(dimeModel* model) const = 0;
	bool read(dimeInput* in) override;
	bool write(dimeOutput* out) override;
	bool isOfType(int thetypeid) const override;
	int countRecords() const override;

	const char* getClassName() const;
	const char* getApplicationName() const;
	int32 getVersionNumber() const;
	int8 getFlag280() const;
	int8 getFlag281() const;

	void setClassName(const char* classname,
	                  DimeMemHandler* memhandler = nullptr);
	void setApplicationName(const char* appname,
	                        DimeMemHandler* memhandler = nullptr);
	void setVersionNumber(int32 v);
	void setFlag280(int8 flag);
	void setFlag281(int8 flag);

protected:
	bool handleRecord(int groupcode,
	                  const dimeParam& param,
	                  DimeMemHandler* memhandler) override;

public:
	static dimeClass* createClass(const char* name,
	                              DimeMemHandler* memhandler = nullptr);

protected:
	bool copyRecords(dimeClass* newclass, dimeModel* model) const;

private:
	char* className;
	char* appName;
	int32 versionNumber;
	int8 flag1;
	int8 flag2;
}; // class dimeClass

inline const char*
dimeClass::getClassName() const
{
	return this->className;
}

inline const char*
dimeClass::getApplicationName() const
{
	return this->appName;
}

inline int32
dimeClass::getVersionNumber() const
{
	return this->versionNumber;
}

inline int8
dimeClass::getFlag280() const
{
	return this->flag1;
}

inline int8
dimeClass::getFlag281() const
{
	return this->flag2;
}

inline void
dimeClass::setVersionNumber(const int32 v)
{
	this->versionNumber = v;
}

inline void
dimeClass::setFlag280(const int8 flag)
{
	this->flag1 = flag;
}

inline void
dimeClass::setFlag281(const int8 flag)
{
	this->flag2 = flag;
}

#endif // ! DIME_CLASS_H
