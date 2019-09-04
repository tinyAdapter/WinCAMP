#pragma once

#include <vector>
#include <functional>
#include <boost/asio.hpp>
#include <boost/process.hpp>

#include "task.h"

namespace WinCAMP
{
	class Worker
	{
	public:
		Worker(Task* task) : Worker(task, DEFAULT_BUFFER_SIZE) {}
		Worker(Task* task, size_t bufferSize) :
			m_task(task),
			m_bufferSize(bufferSize),
			m_buffer(bufferSize),
			m_restartedTime(0),
			m_lastExitCode(0),
			m_ios(),
			m_ap(m_ios),
			m_child(nullptr) {}
		virtual ~Worker();

		Worker& start();

		typedef std::function<void(std::vector<char>)> WorkerCallback;
		WorkerCallback callback();
		Worker& callback(WorkerCallback callback);

		Worker& wait();

		static Worker* fromTask(Task* task, WorkerCallback callback);

	private:
		Task* m_task;
		std::vector<char> m_buffer;
		size_t m_bufferSize;
		WorkerCallback m_callback;
		unsigned int m_restartedTime;
		int m_lastExitCode;
		boost::asio::io_service m_ios;
		boost::process::async_pipe m_ap;
		boost::process::child* m_child;

		static constexpr size_t DEFAULT_BUFFER_SIZE = 4096;
	};
}
