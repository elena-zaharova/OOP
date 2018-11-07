#include "stdafx.h"
#include "TVSet.h"

const unsigned int MINChannel = 1;
const unsigned int MAXChannel = 99;


bool CTVSet::tv_isTurnedOn() const
{
	return tv_isOn;
}

void CTVSet::TurnOn()
{
	tv_isOn = true;
}

void CTVSet::TurnOff()
{
	tv_isOn = false;
}

int CTVSet::GetChannel() const
{
	return tv_isOn ? tv_selectedChannel : 0;
}

bool CTVSet::SelectChannel(int channel)
{
	bool channelValue = ((channel >= MINChannel) && (channel <= MAXChannel));
	if (tv_isOn && channelValue)
	{
		tv_previousChannel = tv_selectedChannel;
		tv_selectedChannel = channel;
		return true;
	}
	return false;
}

bool CTVSet::SelectPreviousChannel()
{
	if (tv_isOn)
	{
		int newChannel     = tv_selectedChannel;
		tv_selectedChannel = tv_previousChannel;
		tv_previousChannel = newChannel;
		return true;
	}
	return false;
}