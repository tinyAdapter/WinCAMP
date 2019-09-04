#include "Hello.h"

QString Hello::getHelloWorldPrompt()
{
	return QString::fromWCharArray(L"Hello World!");
}