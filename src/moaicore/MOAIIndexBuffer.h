// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef	MOAIINDEXBUFFER_H
#define	MOAIINDEXBUFFER_H

#include <moaicore/MOAILua.h>

//================================================================//
// MOAIIndexBuffer
//================================================================//
/**	@name	MOAIIndexBuffer
	@text	Index buffer class. Unused at this time.
*/
class MOAIIndexBuffer :
	public MOAILuaObject {
private:

	u16*	mBuffer;
	u32		mIndexCount;
	
	GLuint	mGLBufferID;
	u32		mHint;
	
	//----------------------------------------------------------------//
	static int	_release				( lua_State* L );
	static int	_reserve				( lua_State* L );
	static int	_setIndex				( lua_State* L );

	//----------------------------------------------------------------//
	void		ClearBuffer				();
	void		Clear					();
	
public:
	
	DECL_LUA_FACTORY ( MOAIIndexBuffer )
	
	//----------------------------------------------------------------//
	bool		Bind					();
	void		DrawElements			( GLenum mode, GLsizei count, u32 offset );
				MOAIIndexBuffer			();
				~MOAIIndexBuffer		();
	void		RegisterLuaClass		( MOAILuaState& state );
	void		RegisterLuaFuncs		( MOAILuaState& state );
	void		ReserveIndices			( u32 indexCount );
	void		SetIndex				( u32 idx, u16 value );
};

#endif
