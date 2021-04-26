/**
	*This file is copyrighted with the CreativeCommons
	* CA-NC-SA license. Please keep this entry in respect
	* of the author's work. Thanks.
	*
	* @author Michal Dziczkowski <mcgiwer@prokonto.pl>
	*
	*/

#include "headers/inc.h"

/**
	* Function to read the config and if does not exist
	* then it creates one
	*
	*/

public void config()
{
	// @todo Do testing

	// File pointer

		fstream config;

	// Parameters to read from config

	string line;
	string setting[];


	// Setting write parameters
	string data;
	string addr;
	int port;


	if(config.open("socket.cfg", ios::in)) {
		setting = getline(config, line, " ");
		addr = setting[0];
		port = setting[1];

		tcp_socket.address = addr;
		tcp_socket.port = port;
		config.close();
	}
	else
	{
		config.open("socket.cfg", ios::out)

		cout <<"Please give the server address: ";
		cin >> addr;

		while (!isdigit(port_val)) {
			cout <<"\nPlease give the server port: ";
			cin >> port;
		}

		if(is_empty(addr)) {
			cout <<"Address not given";
			break;
		}

		if(is_empty(port)) {
			cout << "Port not given";
			break;
		}

		tcp_socket.address = addr;
		tcp_socket.port = port;

		data = addr_str + " " + port_str;

		config << data;

		cout << "Your socket config has been saved as: \n";
		cout << "Host address: " + addr_str + "\n";
		cout << "Port number: " + port_str + "\n";
		config.close();
	}
}

