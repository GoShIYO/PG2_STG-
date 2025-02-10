#include "KeyBoardInput.h"
#include<Novice.h>

void KeyBoardInput::Update()
{
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

bool KeyBoardInput::IsPress(int key)const
{
	return keys[key];
}

bool KeyBoardInput::IsTrigger(int key)const
{
	return keys[key] && !preKeys[key];
}
