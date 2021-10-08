#ifndef GraphicalObjects_HPP
#define GraphicalObjects_HPP

#include "glm/glm.hpp"
#include <vector>
#include <glad/glad.h>

#include "ezdef.hpp"

// Michal Bubnár has made this bearable to do.

#define BufferTypes int
class VertexBufferObject
{
	public:
	GLuint _bufferID;
	BufferTypes bt;
	std::vector<unsigned char> _rawData; // In-memory raw data buffer, used to gather the data for VBO.
	size_t _bytesAdded = 0; // Number of bytes added to the buffer so far
	size_t _uploadedDataSize; // Holds buffer data size after uploading to GPU
	bool _isBufferCreated = false; // Flag telling if the buffer has been created
	bool _isDataUploaded = false; // Flag telling, if data has been uploaded to GPU already.

	void makeVBO(size_t reserveSizeBytes)
	{
		if (_isBufferCreated)
		{
			std::cerr << "This buffer is already created! You need to delete it before re-creating it!" << std::endl;
			return;
		}

		glGenBuffers(1, &_bufferID);
		_rawData.reserve(reserveSizeBytes > 0 ? reserveSizeBytes : 1024);

		std::cout << "Created vertex buffer object with ID " << _bufferID << " and initial reserved size " << _rawData.capacity() << " bytes" << std::endl;
		_isBufferCreated = true;
	}
	void bindVBO(GLenum bufferType)
	{
		if (!_isBufferCreated)
		{
			std::cerr << "This buffer is not created yet! You cannot bind it before you create it!" << std::endl;
			return;
		}

		bt = bufferType;
		glBindBuffer(bt, _bufferID);

	}
	void addData(const void* ptrData, size_t dataSize, int repeat = 1)
	{

		const auto bytesToAdd = dataSize * repeat;
		const auto requiredCapacity = _bytesAdded + bytesToAdd;
		if (requiredCapacity > _rawData.capacity())
		{
			auto newCapacity = _rawData.capacity() * 2;
			while (newCapacity < requiredCapacity) {
				newCapacity *= 2;
			}

			std::vector<unsigned char> newRawData;
			newRawData.reserve(newCapacity);
			memcpy(newRawData.data(), _rawData.data(), _bytesAdded);
			_rawData = std::move(newRawData);
		}

		for (int i = 0; i < repeat; i++)
		{
			memcpy(_rawData.data() + _bytesAdded, ptrData, dataSize);
			_bytesAdded += dataSize;
		}
	}
	void gpuUpload(GLenum usageHint)
	{
		if (!_isBufferCreated)
		{
			std::cerr << "This buffer is not created yet! Call createVBO before uploading data to GPU!" << std::endl;
			return;
		}

		glBufferData(bt, _bytesAdded, _rawData.data(), usageHint);
		_isDataUploaded = true;
		_uploadedDataSize = _bytesAdded;
		_bytesAdded = 0;
	}

	void* mapBufferToMemory(GLenum usageHint) const
	{
		if (!_isDataUploaded) {
			return nullptr;
		}

		return glMapBuffer(bt, usageHint);
	}
};

#endif // GraphicalObjects_HPP