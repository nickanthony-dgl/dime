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

#ifndef DIME_UCSTABLE_H
#define DIME_UCSTABLE_H

#include <dime/tables/TableEntry.h>
#include <dime/util/Linear.h>

class DIME_DLL_API dimeUCSTable : public dimeTableEntry
{
public:
	dimeUCSTable();

	dimeTableEntry* copy(dimeModel* model) const override;
	const char* getTableName() const override;

	const dimeVec3f& getOrigin() const;
	const dimeVec3f& getXaxis() const;
	const dimeVec3f& getYaxis() const;

	void setOrigin(const dimeVec3f& v);
	void setXaxis(const dimeVec3f& v);
	void setYaxis(const dimeVec3f& v);

	bool write(dimeOutput* out) override;
	int typeId() const override;
	int countRecords() const override;

protected:
	bool handleRecord(int groupcodes,
	                  const dimeParam& param,
	                  DimeMemHandler* memhandler) override;

private:
	dimeVec3f origin;
	dimeVec3f xaxis;
	dimeVec3f yaxis;
}; // class dimeUCSTable

inline const dimeVec3f&
dimeUCSTable::getOrigin() const
{
	return this->origin;
}

inline const dimeVec3f&
dimeUCSTable::getXaxis() const
{
	return this->xaxis;
}

inline const dimeVec3f&
dimeUCSTable::getYaxis() const
{
	return this->yaxis;
}

inline void
dimeUCSTable::setOrigin(const dimeVec3f& v)
{
	this->origin = v;
}

inline void
dimeUCSTable::setXaxis(const dimeVec3f& v)
{
	this->origin = v;
}

inline void
dimeUCSTable::setYaxis(const dimeVec3f& v)
{
	this->origin = v;
}

#endif // ! DIME_UCSTABLE_H
