/*
 * This is a part of the BugTrap package.
 * Copyright (c) 2005-2009 IntelleSoft.
 * All rights reserved.
 *
 * Description: In-memory output stream.
 * Author: Maksim Pyatkovskiy.
 *
 * This source code is only intended as a supplement to the
 * BugTrap package reference and related electronic documentation
 * provided with the product. See these sources for detailed
 * information regarding the BugTrap package.
 */

#include "StdAfx.h"
#include "MemStream.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/**
 * @param rMemStream - another binary buffer.
 */
CMemStream::CMemStream(const CMemStream& rMemStream)
{
	if (rMemStream.m_nPosition)
	{
		InitBuffer(rMemStream.m_nPosition);
		CopyData(rMemStream);
	}
	else
		InitBuffer();
}

/**
 * @param rMemStream - another binary buffer.
 * @return reference to self.
 */
CMemStream& CMemStream::operator=(const CMemStream& rMemStream)
{
	EnsureSize(rMemStream.m_nPosition, false);
	CopyData(rMemStream);
	return *this;
}

void CMemStream::InitBuffer(void)
{
	m_pBuffer = NULL;
	m_nSize = m_nLength = m_nPosition = 0;
}

/**
 * @param nSize - initial buffer size.
 */
void CMemStream::InitBuffer(size_t nSize)
{
	if (nSize)
	{
		m_nLength = m_nPosition = 0;
		m_pBuffer = new BYTE[nSize];
		if (m_pBuffer)
		{
			m_nSize = nSize;
		}
		else
		{
			m_nSize = 0;
			RaiseException(STATUS_NO_MEMORY, 0, 0, NULL);
		}
	}
	else
		InitBuffer();
}

/**
 * @param rMemStream - another binary buffer.
 */
void CMemStream::CopyData(const CMemStream& rMemStream)
{
	m_nPosition = rMemStream.m_nPosition;
	m_nLength = rMemStream.m_nLength;
	CopyMemory(m_pBuffer, rMemStream.m_pBuffer, m_nPosition);
}

/**
 * @param nSize - requested buffer size.
 * @param bAdaptiveGrowth - true for adaptive growth.
 */
void CMemStream::EnsureSize(size_t nSize, bool bAdaptiveGrowth)
{
	if (m_nSize < nSize)
	{
		if (bAdaptiveGrowth)
			nSize *= 2;
		PBYTE pBuffer = new BYTE[nSize];
		if (! pBuffer)
			RaiseException(STATUS_NO_MEMORY, 0, 0, NULL);
		if (m_pBuffer)
		{
			CopyMemory(pBuffer, m_pBuffer, m_nPosition);
			delete[] m_pBuffer;
		}
		m_pBuffer = pBuffer;
		m_nSize = nSize;
	}
}

/**
 * @param pBytes - bytes array to be written.
 * @param nCount - number of characters to add.
 * @return number of successfully written bytes.
 */
size_t CMemStream::WriteBytes(const BYTE* pBytes, size_t nCount)
{
	EnsureSize(m_nPosition + nCount, true);
	CopyMemory(m_pBuffer + m_nPosition, pBytes, nCount);
	m_nPosition += nCount;
	if (m_nPosition > m_nLength)
		m_nLength = m_nPosition;
	return nCount;
}

/**
 * @param bValue - byte value to be written.
 * @param nCount - number of characters to add.
 * @return number of written bytes.
 */
size_t CMemStream::WriteByte(BYTE bValue, size_t nCount)
{
	EnsureSize(m_nPosition + nCount, true);
	FillMemory(m_pBuffer + m_nPosition, nCount, bValue);
	m_nPosition += nCount;
	if (m_nPosition > m_nLength)
		m_nLength = m_nPosition;
	return nCount;
}

/**
 * @param bValue - byte value to be written.
 * @return true if data has been written.
 */
bool CMemStream::WriteByte(BYTE bValue)
{
	EnsureSize(m_nPosition + 1, true);
	m_pBuffer[m_nPosition++] = bValue;
	if (m_nPosition > m_nLength)
		m_nLength = m_nPosition;
	return true;
}

/**
 * @param nLength - new stream length.
 * @return new file length.
 */
size_t CMemStream::SetLength(size_t nLength)
{
	EnsureSize(nLength, false);
	if (m_nLength < nLength)
		ZeroMemory(m_pBuffer + m_nLength, nLength - m_nLength);
	m_nLength = nLength;
	if (m_nPosition > m_nLength)
		m_nPosition = m_nLength;
	return m_nLength;
}

/**
 * @param nOffset - offset from start point.
 * @param nStartFrom - start point.
 */
void CMemStream::SetPositionPriv(ptrdiff_t nOffset, size_t nStartFrom)
{
	if (nOffset < 0)
	{
		ptrdiff_t nNewPosition = nStartFrom + nOffset;
		if (nNewPosition < 0)
			m_nPosition = 0;
		else
			m_nPosition = nNewPosition;
	}
	else if (nOffset > 0)
	{
		size_t nNewPosition = nStartFrom + nOffset;
		if (nNewPosition > m_nLength)
			m_nPosition = m_nLength;
		else
			m_nPosition = nNewPosition;
	}
	else
		m_nPosition = nStartFrom;
}

/**
 * @param nOffset - offset from start point.
 * @param nMoveMethod - start point.
 * @return new position value.
 */
size_t CMemStream::SetPosition(ptrdiff_t nOffset, int nMoveMethod)
{
	switch (nMoveMethod)
	{
	case FILE_BEGIN:
		SetPositionPriv(nOffset, 0);
		break;
	case FILE_CURRENT:
		SetPositionPriv(nOffset, m_nPosition);
		break;
	case FILE_END:
		SetPositionPriv(nOffset, m_nLength);
		break;
	default:
		return MAXSIZE_T;
	}
	return m_nPosition;
}

/**
 * @param bValue - output value.
 * @return true if byte has been retrieved from the stream.
 */
bool CMemStream::ReadByte(BYTE& bValue)
{
	if (m_nPosition < m_nLength)
	{
		bValue = m_pBuffer[m_nPosition++];
		return true;
	}
	return false;
}

/**
 * @param arrBytes - output array of bytes.
 * @param nCount - number of bytes in the array.
 * @return number of retrieved bytes.
 */
size_t CMemStream::ReadBytes(BYTE* arrBytes, size_t nCount)
{
	size_t nMaxBytes = m_nLength - m_nPosition;
	if (nMaxBytes < nCount)
		nCount = nMaxBytes;
	CopyMemory(arrBytes, m_pBuffer + m_nPosition, nCount);
	m_nPosition += nCount;
	return nCount;
}
