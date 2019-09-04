#pragma once

#include <string>
#include <vector>
#include <boost/process/environment.hpp>

namespace WinCAMP
{
	class Task
	{
	public:
		virtual ~Task();

		bool isPathValid() const;

		std::wstring name() const;
		Task& name(const std::wstring& name);

		bool enabled() const;
		Task& enabled(bool enabled);

		std::wstring path() const;
		Task& path(const std::wstring& path);

		boost::process::environment* env() const;
		Task& env(boost::process::environment* env);

		std::vector<const Task*> dependentTasks() const;
		Task& addDependentTask(const Task* task);
		Task& removeDependentTask(const Task* task);
		Task& removeAllDependentTasks();

		bool autoRestart() const;
		Task& autoRestart(bool autoRestart);

		unsigned int maxRetryTime() const;
		Task& maxRetryTime(unsigned int maxRetryTime);

	private:
		std::wstring m_name;
		bool m_enabled;
		std::wstring m_path;
		boost::process::environment* m_env;
		std::vector<const Task*> m_dependentTasks;
		bool m_autoRestart;
		unsigned int m_maxRetryTime;
	};
}
