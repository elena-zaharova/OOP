#include "stdafx.h"
#include "RemoteControl.h"
#include "TVSet.h"

using namespace std;

int main()
{
	CTVSet tv;
	CRemoteControl remoteControl(tv, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!remoteControl.HandleComand())
		{
			cout << "Unknown command!" << endl;
		}
	}

	return 0;
}