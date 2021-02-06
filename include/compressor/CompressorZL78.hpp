#ifndef COMPRESSORZL78_H
#define COMPRESSORZL78_H
#include <iostream>
#include "Compressor.hpp"

namespace compressor{
	class CompressorZL78: public Compressor{
	public:
		void encode() override;
		void decode() override;
		CompressorZL78();
		~CompressorZL78();
	};
}

#endif