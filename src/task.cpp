#include <algorithm>

#include "task.h"

using namespace WinCAMP;

Task::~Task()
{
	delete m_env;
}

bool Task::isPathValid() const
{
	//TODO
	return false;
}

std::wstring Task::name() const
{
	return m_name;
}

Task& Task::name(const std::wstring& name)
{
	m_name = name;
	return *this;
}

bool Task::enabled() const
{
	return m_enabled;
}

Task& Task::enabled(bool enabled)
{
	m_enabled = enabled;
	return *this;
}

std::wstring Task::path() const
{
	return m_path;
}

Task& Task::path(const std::wstring& path)
{
	m_path = path;
	return *this;
}

boost::process::environment* Task::env() const
{
	return m_env;
}

Task& Task::env(boost::process::environment* env)
{
	m_env = env;
	return *this;
}

std::vector<const Task*> Task::dependentTasks() const
{
	return m_dependentTasks;
}

Task& Task::addDependentTask(const Task* task)
{ 
	m_dependentTasks.push_back(task);
	return *this;
}

Task& Task::removeDependentTask(const Task* task)
{
	m_dependentTasks.erase(
		std::remove(m_dependentTasks.begin(), m_dependentTasks.end(), task),
		m_dependentTasks.end());
	return *this;
}

Task& Task::removeAllDependentTasks()
{
	m_dependentTasks = std::vector<const Task*>{};
	return *this;
}

bool Task::autoRestart() const
{
	return m_autoRestart;
}

Task& Task::autoRestart(bool autoRestart)
{
	m_autoRestart = autoRestart;
	return *this;
}

unsigned int Task::maxRetryTime() const
{
	return m_maxRetryTime;
}

Task& Task::maxRetryTime(unsigned int maxRetryTime)
{
	m_maxRetryTime = maxRetryTime;
	return *this;
}
