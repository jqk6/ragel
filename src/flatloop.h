/*
 *  Copyright 2004-2014 Adrian Thurston <thurston@complang.org>
 */

#ifndef _C_FLATLOOP_H
#define _C_FLATLOOP_H

#include <iostream>
#include "flat.h"

/* Forwards. */
struct CodeGenData;
struct NameInst;
struct RedTransAp;
struct RedStateAp;

class FlatLooped
	: public Flat
{
public:
	FlatLooped( const CodeGenArgs &args )
		: Flat(args) {}

	std::ostream &TO_STATE_ACTION_SWITCH();
	std::ostream &FROM_STATE_ACTION_SWITCH();
	std::ostream &EOF_ACTION_SWITCH();
	std::ostream &ACTION_SWITCH();

	virtual void TO_STATE_ACTION( RedStateAp *state );
	virtual void FROM_STATE_ACTION( RedStateAp *state );
	virtual void EOF_ACTION( RedStateAp *state );
	virtual void COND_ACTION( RedCondAp *cond );

	void tableDataPass();

	virtual void genAnalysis();
	virtual void writeData();
	virtual void writeExec();
};

#endif
