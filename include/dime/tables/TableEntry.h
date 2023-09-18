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

#ifndef DIME_TABLEENTRY_H
#define DIME_TABLEENTRY_H

#include <dime/Base.h>
#include <dime/RecordHolder.h>

class dimeModel;

class DIME_DLL_API dimeTableEntry : public dimeRecordHolder
{
	friend class dimeUnknownTable;
	friend class dimeLayerTable;

public:
	dimeTableEntry();
	~dimeTableEntry() override;

	virtual const char* getTableName() const = 0;
	bool read(dimeInput* in) override;
	bool write(dimeOutput* out) override;
	virtual dimeTableEntry* copy(dimeModel* model) const = 0;
	int typeId() const override = 0;
	bool isOfType(int thetypeid) const override;
	int countRecords() const override;

	static dimeTableEntry* createTableEntry(const char* name,
	                                        dimeMemHandler* memhandler = nullptr);

protected:
	bool preWrite(dimeOutput* output);

	bool handleRecord(int groupcode,
	                  const dimeParam& param,
	                  dimeMemHandler* memhandler) override;

	bool copyRecords(dimeTableEntry* table, dimeModel* model) const;
}; // class dimeTableEntry

#endif // ! DIME_TABLEENTRY_H
