#define BOOST_TEST_MODULE Worker
#include <boost/test/unit_test.hpp>

#include <boost/process.hpp>
#include <boost/asio.hpp>

#include <iostream>

#include "worker.h"

BOOST_AUTO_TEST_CASE(test_worker)
{
	WinCAMP::Task* task = new WinCAMP::Task();
	task->name(L"Dir C:\\");
	task->path(L"dir C:\\");
	WinCAMP::Worker* worker = new WinCAMP::Worker(task);
	worker->callback([](std::vector<char> buffer) 
	{
		for (size_t i = 0; i < buffer.size(); i++)
		{
			std::cout << buffer[i];
		}
		std::cout << std::endl;
	});
	worker->start();
	worker->wait();

	delete worker;
	delete task;
}
