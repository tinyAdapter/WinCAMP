#include <iostream>

#include "worker.h"

using namespace WinCAMP;

Worker::~Worker()
{
	delete m_child;
}

Worker& Worker::start()
{
	m_child = new boost::process::child(
		boost::process::search_path("cmd.exe"), "/c", m_task->path(),
		boost::process::std_out > m_ap
	);

	boost::asio::async_read(m_ap, boost::asio::buffer(m_buffer),
		[&](const boost::system::error_code& ec, std::size_t size)
	{
		if (m_callback) m_callback(m_buffer);
		m_buffer.clear();
	});

	m_ios.run();
	return *this;
}

Worker::WorkerCallback Worker::callback()
{
	return m_callback;
}

Worker& Worker::callback(WorkerCallback callback)
{
	m_callback = callback;
	return *this;
}

Worker& Worker::wait()
{
	m_child->wait();
	return *this;
}

Worker* Worker::fromTask(Task* task, Worker::WorkerCallback callback)
{
	Worker* w = new Worker(task);
	w->callback(callback);
	w->start();
	return w;
}