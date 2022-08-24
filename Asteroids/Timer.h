#pragma once
class Timer
{
public:
	void Update(float deltaTime);

	void Set(float amountInSeconds);
	void Reset();
	bool Elapsed();

private:
	float TheSeconds;
	float TheAmount;
};

