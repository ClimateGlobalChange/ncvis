///////////////////////////////////////////////////////////////////////////////
///
///	\file    Exception.h
///	\author  Paul Ullrich
///	\version June 27, 2022
///
///	<summary>
///		This file provides functionality for formatted Exceptions.
///	</summary>

#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

///////////////////////////////////////////////////////////////////////////////

#include <cstdarg>
#include <iostream>

///////////////////////////////////////////////////////////////////////////////

#define _EXCEPTION() \
{std::cerr << Exception(__FILE__, __LINE__).ToString() << std::endl;exit(-1);}

#define _EXCEPTIONT(text) \
{std::cerr << Exception(__FILE__, __LINE__, text).ToString() << std::endl;exit(-1);}

#define _EXCEPTION1(text, var1) \
{std::cerr << Exception(__FILE__, __LINE__, text, var1).ToString() << std::endl;exit(-1);}

#define _EXCEPTION2(text, var1, var2) \
{std::cerr << Exception(__FILE__, __LINE__, text, var1, var2).ToString() << std::endl;exit(-1);}

#define _EXCEPTION3(text, var1, var2, var3) \
{std::cerr << Exception(__FILE__, __LINE__, text, var1, var2, var3).ToString() << std::endl;exit(-1);}

#define _EXCEPTION4(text, var1, var2, var3, var4) \
{std::cerr << Exception(__FILE__, __LINE__, text, var1, var2, var3, var4).ToString() << std::endl;exit(-1);}

#define _EXCEPTION5(text, var1, var2, var3, var4, var5) \
{std::cerr << Exception(__FILE__, __LINE__, text, var1, var2, var3, var4, var5).ToString() << std::endl;exit(-1);}

#define _EXCEPTION6(text, var1, var2, var3, var4, var5, var6) \
{std::cerr << Exception(__FILE__, __LINE__, text, var1, var2, var3, var4, var5, var6).ToString() << std::endl;exit(-1);}

#define _EXCEPTION7(text, var1, var2, var3, var4, var5, var6, var7) \
{std::cerr << Exception(__FILE__, __LINE__, text, var1, var2, var3, var4, var5, var6, var7).ToString() << std::endl;exit(-1);}

#define _EXCEPTION8(text, var1, var2, var3, var4, var5, var6, var7, var8) \
{std::cerr << Exception(__FILE__, __LINE__, text, var1, var2, var3, var4, var5, var6, var7, var8).ToString() << std::endl;exit(-1);}

#define _ASSERT(x) \
if (!(x)) {_EXCEPTIONT("Assertion failure");}

///////////////////////////////////////////////////////////////////////////////

#include <string>
#include <cstdio>
#include <stdarg.h>

///////////////////////////////////////////////////////////////////////////////

///	<summary>
///		An Exception is a formatted error message that is generated from a
///		throw directive.  This class is automatically generated when using
///		the _EXCEPTION macros.
///	</summary>
class Exception {
	
	public:
		///	<summary>
		///		Maximum buffer size for exception strings.
		///	</summary>
		static const int ExceptionBufferSize = 1024;

	public:
		///	<summary>
		///		Generic constructor.
		///	</summary>
		Exception(
			const char * szFile,
			unsigned int uiLine
		) :
			m_strText("General exception"),
			m_strFile(szFile),
			m_uiLine(uiLine)
		{ }
	
		///	<summary>
		///		Constructor with text and variables.
		///	</summary>
		Exception(
			const char * szFile,
			unsigned int uiLine,
			const char * szText,
			...
		) :
			m_strFile(szFile),
			m_uiLine(uiLine)
		{
			char szBuffer[ExceptionBufferSize];

			va_list arguments;

			// Initialize the argument list
			va_start(arguments, szText);

			// Write to string
			vsnprintf(szBuffer, ExceptionBufferSize, szText, arguments);

			m_strText = szBuffer;

			// Cleans up the argument list
			va_end(arguments);
		}
	
	public:
		///	<summary>
		///		Get a string representation of this exception.
		///	</summary>
		std::string ToString() const {
			std::string strReturn;

			char szBuffer[ExceptionBufferSize];

			// Preamble
			snprintf(szBuffer, ExceptionBufferSize, "EXCEPTION (");
			strReturn.append(szBuffer);

			// File name
			strReturn.append(m_strFile);

			// Line number
			snprintf(szBuffer, ExceptionBufferSize, ", Line %u) ", m_uiLine);
			strReturn.append(szBuffer);

			// Text
			strReturn.append(m_strText);

			return strReturn;
		}

	private:
		///	<summary>
		///		A string denoting the error in question.
		///	</summary>
		std::string m_strText;
	
		///	<summary>
		///		A string containing the filename where the exception occurred.
		///	</summary>
		std::string m_strFile;
	
		///	<summary>
		///		A constant containing the line number where the exception
		///		occurred.
		///	</summary>
		unsigned int m_uiLine;
};

///////////////////////////////////////////////////////////////////////////////

#endif

