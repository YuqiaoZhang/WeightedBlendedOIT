// This code contains NVIDIA Confidential Information and is disclosed to you
// under a form of NVIDIA software license agreement provided separately to you.
//
// Notice
// NVIDIA Corporation and its licensors retain all intellectual property and
// proprietary rights in and to this software and related documentation and
// any modifications thereto. Any use, reproduction, disclosure, or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA Corporation is strictly prohibited.
//
// ALL NVIDIA DESIGN SPECIFICATIONS, CODE ARE PROVIDED "AS IS.". NVIDIA MAKES
// NO WARRANTIES, EXPRESSED, IMPLIED, STATUTORY, OR OTHERWISE WITH RESPECT TO
// THE MATERIALS, AND EXPRESSLY DISCLAIMS ALL IMPLIED WARRANTIES OF NONINFRINGEMENT,
// MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE.
//
// Information and code furnished is believed to be accurate and reliable.
// However, NVIDIA Corporation assumes no responsibility for the consequences of use of such
// information or for any infringement of patents or other rights of third parties that may
// result from its use. No license is granted by implication or otherwise under any patent
// or patent rights of NVIDIA Corporation. Details are subject to change without notice.
// This code supersedes and replaces all information previously supplied.
// NVIDIA Corporation products are not authorized for use as critical
// components in life support devices or systems without express written approval of
// NVIDIA Corporation.
//
// Copyright (c) 2008-2014 NVIDIA Corporation. All rights reserved.
// Copyright (c) 2004-2008 AGEIA Technologies, Inc. All rights reserved.
// Copyright (c) 2001-2004 NovodeX AG. All rights reserved.

#ifndef NV_NVFOUNDATION_NVIO_H
#define NV_NVFOUNDATION_NVIO_H

/** \addtogroup common
  @{
*/

#include "NvSimpleTypes.h"

#if !NV_DOXYGEN
namespace nvidia
{
#endif

/**
\brief Input stream class for I/O.

The user needs to supply a NvInputStream implementation to a number of methods to allow the SDK to read data.
*/

class NvInputStream
{
  public:
	/**
	\brief read from the stream. The number of bytes read may be less than the number requested.

	\param[in] dest the destination address to which the data will be read
	\param[in] count the number of bytes requested

	\return the number of bytes read from the stream.
	*/

	virtual uint32_t read(void* dest, uint32_t count) = 0;

	virtual ~NvInputStream()
	{
	}
};

/**
\brief Input data class for I/O which provides random read access.

The user needs to supply a NvInputData implementation to a number of methods to allow the SDK to read data.
*/

class NvInputData : public NvInputStream
{
  public:
	/**
	\brief return the length of the input data

	\return size in bytes of the input data
	*/

	virtual uint32_t getLength() const = 0;

	/**
	\brief seek to the given offset from the start of the data.

	\param[in] offset the offset to seek to. 	If greater than the length of the data, this call is equivalent to
	seek(length);
	*/

	virtual void seek(uint32_t offset) = 0;

	/**
	\brief return the current offset from the start of the data

	\return the offset to seek to.
	*/

	virtual uint32_t tell() const = 0;

	virtual ~NvInputData()
	{
	}
};

/**
\brief Output stream class for I/O.

The user needs to supply a NvOutputStream implementation to a number of methods to allow the SDK to write data.
*/

class NvOutputStream
{
  public:
	/**
	\brief write to the stream. The number of bytes written may be less than the number sent.

	\param[in] src the destination address from which the data will be written
	\param[in] count the number of bytes to be written

	\return the number of bytes written to the stream by this call.
	*/

	virtual uint32_t write(const void* src, uint32_t count) = 0;

	virtual ~NvOutputStream()
	{
	}
};

#if !NV_DOXYGEN
} // namespace nvidia
#endif

/** @} */
#endif // #ifndef NV_NVFOUNDATION_NVIO_H
