#include "error.h"

using namespace FLAT;

int Error::getId()
{
	return m_id;
}

string Error::getMessage()
{
	return m_msg;
}

void Error::setId(int id)
{
	m_id = id;
}

void Error::setMessage(string msg)
{
	m_msg = msg;
}

FLAT::Error::Error(void)
{
	m_id = 0;
	m_msg = "";
}

Error::Error(int id, string msg)
{
	m_id = id;
	m_msg = msg;
}


Error::~Error(void)
{
}
