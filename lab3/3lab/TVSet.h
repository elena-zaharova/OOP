#pragma once
class CTVSet
{
public:
	bool tv_isTurnedOn()const;
	void TurnOn();
	void TurnOff();
	int GetChannel()const;
	bool SelectChannel(int channel);
	bool SelectPreviousChannel();
private:
	bool tv_isOn = false;
	int tv_selectedChannel = 1;
	int tv_previousChannel = 1;
};