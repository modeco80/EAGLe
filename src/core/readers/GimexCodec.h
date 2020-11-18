#pragma once

#include <Core.h>
#include <ShpsStructs.h>

namespace eagle {
namespace core {

	enum class CodecResult : byte {
		OK,
		ErrorDecoding,
		ErrorEncoding,
		ErrorInputInvalid
	};

	// TODO: use CRTP for a eeny bit less runtime overhead
	// (all cases are static so crtp would work just fine)

	/**
	 * Gimex codec interface.
	 */
	struct BaseGimexCodec {
		
		/**
		 * Encode the image data.
		 * 
		 * Doesn't need to be implemented yet
		 */
		virtual std::vector<byte> Encode(const shps::Image& image) = 0;

		/**
		 * Decode the image data.
		 */
		virtual std::vector<byte> Decode(const shps::Image& image) = 0;
	};

}
}