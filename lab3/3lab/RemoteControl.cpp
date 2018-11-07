#include "stdafx.h"
#include <string>
#include <fstream>
#include <bitset>
#include "RemoteControl.h"
#include "TVSet.h"

using namespace std;
using namespace std::placeholders;

CRemoteControl::CRemoteControl(CTVSet& tv, std::istream& input, std::ostream& output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "TurnOn", [this](istream & strm) {return TurnOn(strm); } },
		{ "TurnOff", bind(&CRemoteControl::TurnOff, this, _1) },
		{ "Info", bind(&CRemoteControl::Info, this, _1) },
        { "SelectChannel",bind(&CRemoteControl::SelectChannel, this, _1) },
		{ "SelectPreviousChannel",bind(&CRemoteControl::SelectPreviousChannel, this, _1) }
		})
{
}

bool CRemoteControl::HandleComand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CRemoteControl::TurnOn(istream&)
{
	m_tv.TurnOn();
	m_output << "TV is turned on!" << endl;
	return true;
}

bool CRemoteControl::TurnOff(istream &)
{
	m_tv.TurnOff();
	m_output << "TV is turned off! " << endl;
	return true;
}

bool CRemoteControl::SelectChannel(istream& args)
{
	int channel;
	args >> channel;
	if (!m_tv.tv_isTurnedOn()) 
	{
		m_output << "Channel don't select because TV is turned off\n";
	}
	else if(!m_tv.SelectChannel(channel))
	{
		m_output << "Channel doesn't exist!\n";
	}
	else
	{
		m_output << "Cannel selected\n";
	}
	return true;

}

bool CRemoteControl::SelectPreviousChannel(istream&)
{
	if(!m_tv.tv_isTurnedOn())
	{
		m_output << "Channel don't select because TV is turned off\n";
	}
	else
	{
		m_tv.SelectPreviousChannel();
		m_output << "Cannel selected\n";
	}
	return true;
}

bool CRemoteControl::Info(istream &)
{
	string info = (m_tv.tv_isTurnedOn())
		? ("TV is turned on \nChannel is: " + to_string(m_tv.GetChannel()) + "\n")
		: "TV is turned off\n";
	m_output << info;

	return true;
}

