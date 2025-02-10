#pragma once

class KeyBoardInput {
public:
	/// <summary>
	/// キーボード入力のインスタンス
	/// </summary>
	/// <returns>シングルトンのポインター</returns>
	static KeyBoardInput* Instance() {
		static KeyBoardInput keyBoardInput;
		return &keyBoardInput;
	}
	//キー入力更新処理
	void Update();
	//特定キー押されているかどうかを得る
	bool IsPress(int key)const;
	//特定キーがトリガーされたかを得る
	bool IsTrigger(int key)const;
private:
	KeyBoardInput() = default;
	~KeyBoardInput() = default;
	KeyBoardInput(const KeyBoardInput&) = delete;
	KeyBoardInput& operator=(const KeyBoardInput&) = delete;
private:
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};