#pragma once
class CTVSet;
#include<functional>
#include <iostream>
#include <map>
#include <fstream>

using namespace std;


class CRemoteControl
{
public:
	CRemoteControl(CTVSet & tv, istream & input, ostream & output);
	bool HandleComand();

private:
	bool TurnOn(istream &);
	bool TurnOff(istream &);
	bool SelectChannel(istream & args);
	bool SelectPreviousChannel(istream &);
	bool Info(istream &);
private:
	typedef map<string, std::function<bool(istream & args)>> ActionMap;

	CTVSet & m_tv;
	istream & m_input;
	ostream & m_output;

	const ActionMap m_actionMap;

};